set(PLUGIN_SOURCES
    "dog.cpp"
    "cat.cpp"
    "tiger.cpp"
)

foreach(PLUGIN_SOURCE ${PLUGIN_SOURCES})
    string(REPLACE ".cpp" "" LIB_NAME ${PLUGIN_SOURCE})
    set(LIB_NAMES ${LIB_NAMES} ${LIB_NAME})
    add_library(${LIB_NAME} SHARED ${PLUGIN_SOURCE})
endforeach(PLUGIN_SOURCE ${PLUGIN_SOURCES})
