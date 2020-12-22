## zoo overview

Plugins must comply with a basic API:

* A plugin called `name` must expose `createName` and `destroyName`
* `createName` must return a pointer to a `new`'d `Name` held by the plugin
  * Using a `shared_ptr` instead would be more C++
* `destroyName` must destroy an existing `Name` object
* `Name` objects must implement `makeSound` -- they are zoo animals after all

Plugins may be added to the designated plugins directory at any time, even
while `zoo` is running. If added, plugins will be picked up and started on the
fly.
