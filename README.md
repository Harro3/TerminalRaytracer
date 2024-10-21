# TerminalRaytracer

This is a personnal project that implements simple ray casting in the terminal window

# Usage

Compiling:

```sh
cmake -B build -S.
cd build
make -j
```

Then edit the config file, the syntax is the following:
<object> <x> <y> <z> <radius>

x, y, and z fields can be calls to the `range` function. For now only the `sphere` object is supported.
Range is used like this: `range(from, to, step)`

Here is an example config:
```
sphere range( -1 1 1 ) range( -1 1 1 ) -1 0.5
sphere 1 1 1 1
```

then just execute the binary `terminal-raytracer`
