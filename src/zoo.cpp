#include <dlfcn.h>

#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <mutex>
#include <set>
#include <thread>

#include "util/globothy.h"
#include "util/libnameothy.h"
#include "animal.h" // using generic pointers to all plugins

std::set<std::string> libNames;
std::mutex libLock;

std::atomic<bool> zooOpen { true };

extern "C" void signalHandler(int signal)
{
    zooOpen = false;
}

void zookeeper(std::atomic<bool> &running, unsigned int update_s)
{
    const auto naptime = std::chrono::milliseconds(100);

    while(running) {
        for(std::string plugin : libNames) {
            void *dlhandle = dlopen(plugin.c_str(), RTLD_LAZY);

            std::pair<std::string, std::string> delibbed =
                libnameothy(plugin);

            Animal *(*create)();
            void (*destroy)(Animal *);

            std::string cn = "create" + delibbed.second;
            std::string dn = "destroy" + delibbed.second;

            create = (Animal *(*)())dlsym(dlhandle, cn.c_str());
            destroy = (void (*)(Animal *))dlsym(dlhandle, dn.c_str());

            Animal *a = create();

            a->makeSound();

            destroy(a);
        }

        unsigned int napped = 0;
        while(running) {
            // spin here too, so we can check running status multiple
            // times during a long sleep
            if(napped > update_s * 1000) {
                break;
            }
            std::this_thread::sleep_for(naptime);
            napped += 100;
        }
    }

    std::cout << "Exiting zookeeper thread" << std::endl;
}

void updateLibs(std::atomic<bool> &running, unsigned int update_s)
{
    const auto naptime = std::chrono::milliseconds(100);
    
    while(running) {
        std::cout << "Checking for new libs" << std::endl;

#if __APPLE__
        const std::string libGlob("plugins/*.dylib");
#else
        const std::string libGlob("plugins/*.so");
#endif

        std::vector<std::string> filenames = globothy(libGlob);

        size_t before = libNames.size();
        libLock.lock(); // get locked, boi ------------------------------//
        for(std::string plugin : filenames) {                            //
            libNames.insert(plugin);                                     //
        }                                                                //
        libLock.unlock(); // got 'em ------------------------------------//
        size_t after = libNames.size();

        if(after - before > 0) {
            std::cout << "Found " << after - before << " new plugins";
            std::cout << std::endl;
        }

        unsigned int napped = 0;
        while(running) {
            // spin here too, so we can check running status multiple
            // times during a long sleep
            if(napped > update_s * 1000) {
                break;
            }
            std::this_thread::sleep_for(naptime);
            napped += 100;
        }
    }

    std::cout << "Exiting update thread" << std::endl;
}

void installSignalHandler()
{
    std::signal(SIGINT, &signalHandler);
}

int main(int argc, char *argv[])
{
    installSignalHandler();

    std::thread updateThread(updateLibs, std::ref(zooOpen), 5);
    std::thread zooThread(zookeeper, std::ref(zooOpen), 5);

    const auto naptime = std::chrono::milliseconds(100);
    while(zooOpen) {
        std::this_thread::sleep_for(naptime);
    }

    std::cout << std::endl << "The zoo is now closed" << std::endl;
    updateThread.join();
    zooThread.join();

    return 0;
}
