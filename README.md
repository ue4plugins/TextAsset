# TextAsset

Unreal Engine 4 plug-in that adds a text asset and editor for personal notes.

![Screenshot](Docs/screenshot.png)


## About

The TextAsset plug-in implements two modules that demonstrate how to add a new
type of content asset to Unreal Engine 4. The asset itself stores a simple text
string that can be used for adding personal notes or other textual information
to your project, or to be consumed within Blueprints. The plug-in also includes
an asset editor, asset factories, and asset actions for the Content Browser. 

Make sure to pull the *Tag* that matches your Unreal Engine version. If you sync
to *Master* the code may not compile, because it may depend on Engine changes
that are not yet available in the UE4 Master branch.

## Supported Platforms

This plug-in was last built against **Unreal Engine 4.19**. It works on all
platforms.


## Dependencies

This plug-in requires Visual Studio and either a C++ code project or the full
Unreal Engine 4 source code from GitHub. If you are new to programming in UE4,
please see the official [Programming Guide](https://docs.unrealengine.com/latest/INT/Programming/index.html)! 


## Usage

You can use this plug-in as a project plug-in, or an Engine plug-in.

If you use it as a project plug-in, clone this repository into your project's
*/Plugins* directory and compile your game in Visual Studio. A C++ code project
is required for this to work.

If you use it as an Engine plug-in, clone this repository into the
*/Engine/Plugins/Media* directory and compile your game. Full Unreal Engine 4
source code from GitHub (4.9 or higher) is required for this.


## Support

Please [file an issue](https://github.com/ue4plugins/TextAsset/issues),
submit a [pull request](https://github.com/ue4plugins/TextAsset/pulls?q=is%3Aopen+is%3Apr)
or email us at info@headcrash.industries


## References

* [Introduction to UE4 Plugins](https://wiki.unrealengine.com/An_Introduction_to_UE4_Plugins)
