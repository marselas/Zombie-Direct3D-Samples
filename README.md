These are updated versions of the Direct3D9, Direct3D10, and Direct3D11 samples from the DirectX SDK June 2010 release.

All samples have been minimally updated to successfully compile and build against the latest versions of Windows and Visual Studio.

Current Direct3D samples are available from https://github.com/Microsoft/DirectX-Graphics-Samples

**Table of Contents**
1. Build Environment
2. Changes


====================

1. Build Environment

====================

All samples have been updated to the following build environment:
* Windows 10 RS4
* Visual Studio 2017 version 15.8.5
* Windows 10 SDK 10.0.17134.0

Debug versions of the Direct3D10 samples require the installation of the Direct3D Debug Layer. If the Direct3D Debug Layer is not installed, device creation will fail in debug builds due to the use of the debug flag.

To install the Direct3D Debug Layer:
* Go to Cortana
* Enter: Optional features
* Select: Add an Optional Feature
* Click: Add a feature
* Select and Install: Graphics Tools


==========

2. Changes

==========
The goal of the changes to these samples was to enable them to be successfully built in a modern environment with a minimum number of changes.

General Changes:
* Visual Studio solution and projects upgraded to Visual Studio 2015
* C++ Target platform version upgraded to 10.0.10586.0
* Fixed compiler warnings and errors
* Fixed linker warnings and errors
* Fixed miscellaneous bugs in both C++ and media files
* Replaced dxerr.lib with native code
