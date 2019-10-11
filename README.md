
# Instructions

Feel free to ask me any questions.

## 1. Initialize submodules

You only need to do this once each time you clone the repo.

```bash
$ git submodule init --recursive
$ git submodule update
```

## 2. Build godot-cpp

Go into the `godot-cpp` folder and follow [their build instructions][1], which
is basically running `scons`. It may take several minutes to compile this part!

[1]: https://github.com/GodotNativeTools/godot-cpp

## 3. Build the library

Back to this repo's root directory, run:

```bash
$ make
```

(sorry it's unix only)

You might need to fix the name of the godot-cpp static library in the
`Makefile`.

## 4. Grab the dynamic library

It should be on the `bin` folder of this repo now. Place it inside your godot
projet.

## 5. Create the GDNativeLibrary resource

And link out library to the corresponding platform. Save the resource with the
`*.gdnlib` extension.

## 6. Create the NativeScript resource

In the inspector, write the name of the class imported (`GeneratedTileMap`) and
choose the `gdnlib` file generated from the previous step. Save this resource
as a `*.gdns` file.

## 7. Use the native script!

Create a Godot scene as usual, attach the NativeScript to a TileMap node, and
call its `generate()` method after setting the parameters in the inspector. You
might need to reopen the scene or reload Godot for the exported variables to
appear in the inspector!

## 8. ???

## 9. Profit!

