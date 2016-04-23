These are updated versions of the Direct3D 9 and Direct3D 10 samples from the DirectX SDK June 2010 release.

All samples have been minimally updated to successfully compile and build against the latest versions of Windows and Visual Studio.

Updated Direct3D11 samples are available from https://github.com/walbourn/directx-sdk-samples

Current Direct3D samples are available from https://github.com/Microsoft/DirectX-Graphics-Samples

=================
Table of Contents
=================
1. Build Environment
2. Changes
3. Direct3D10 Samples
4. Building Direct3D10 Samples
5. Direct3D9 Samples
6. Building Direct3D9 Samples


====================
1. Build Environment
====================
All samples have been updated to the following build environment:
* Windows 10
* Visual Studio 2015 Update 1
* Windows 10 SDK 10586

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

For the Direct3D9 and Direct3D10 samples, there is still a dependency on the D3DX9 and D3DX10 header files and library files included with the DirectX SDK June 2010.  Information on specific file dependencies and where to copy them in order to build are included below with the instructions for Direct3D9 and Direct3D10.

General Changes:
* Visual Studio solution and projects upgraded to Visual Studio 2015
* C++ Target platform version upgraded to 10.0.10586.0
* Fixed compiler warnings and errors
* Fixed linker warnings and errors
* Fixed miscellaneous bugs in both C++ and media files
* Replaced dxerr.lib with native code


=====================
3. Direct3D10 Samples
=====================
The following Direct3D10 samples are included:

10BitScanout10
--------------
This sample produces a linear gray scale test pattern in both 8 and 10 bit color and displays it on multiple monitors to enable direct comparison.

AdvancedParticles
-----------------
This is one of 3 sample applications shown during the Advanced Real-Time Rendering in 3D Graphics and Games course at SIGGraph 2007. The Direct3D 10 sample shows a particle system that interacts with its environment. The system is managed entirely by the GPU.

BasicHLSL10
-----------
This Direct3D 10 sample shows a simple example of the High-Level Shader Language (HLSL) using the effect interface. This sample also includes a Direct3D 9 fallback

ContentStreaming
----------------
The ContentStreaming sample demonstrates streaming content in the background for applications that need to display more data than can fit in video or system ram at any given time. This sample supports both Direct3D 9 and Direct3D 10.

CubeMapGS
---------
This Direct3D 10 sample shows an example of rendering to all 6 faces of a cube map in one pass.

DDSWithoutD3DX
--------------
DDS texture loading without using the D3DX helper functions.

DeferredParticles
-----------------
This sample shows how to create more volumetric-looking particles using a deferred rendering approach.

DepthOfField10.1
----------------
This Direct3D 10.1 sample, courtesy of AMD, shows how to use depth of field with MSAA on Direct3D 10.1 hardware.

DrawPredicated
--------------
This Direct3D 10 sample shows the use of predicated Direct3D 10 calls to avoid drawing occluded geometry.

FixedFuncEMU
------------
This Direct3D 10 sample shows how to implement Direct3D 9 level fixed-function functionality in Direct3D 10

GPUBoids
--------
This is one of 3 sample applications shown during the Advanced Real-Time Rendering in 3D Graphics and Games course at SIGGraph 2007. The Direct3D 10 sample shows a flocking algorithm managed entirely by the GPU.

GPUSpectrogram
--------------
This Direct3D 10 sample shows the creation of a spectrogram from a wav file using the GPU.

HDAO10.1
--------
This sample, contributed by AMD, presents an innovative technique for achieving High Definition Ambient Occlusion (HDAO). It utilizes Direct3D 10.1 APIs and hardware, making use of the new shader model 4.1 gather4 instruction, to greatly accelerate the performance of this technique.

HDRFormats10
------------
High dynamic range lighting effects require the ability to work with color values beyond the 0 to 255 range, usually by storing high range color data in textures. Floating point texture formats are the natural choice for HDR applications, but they may not be available on all target systems. This Direct3D 10 sample shows how high dynamic range data can be encoded into integer formats for compatibility across a wide range of devices. This sample also includes a Direct3D 9 fallback.

HLSLWithoutFX10
---------------
This Direct3D 10 sample shows a simple example of the High-Level Shader Language (HLSL) without using the effect interface.

Instancing10
------------
This Direct3D 10 sample shows an example of using instancing to render a complex scene using few draw calls.

MeshFromOBJ10
-------------
This sample shows how an ID3DX10Mesh object can be created from mesh data stored in a Wavefront Object file (.obj). This sample is an adaption of the Direct3D 9 sample MeshFromOBJ, which demonstrates best practices when porting to Direct3D 10 from Direct3D 9. The sample code has been constructed to facilitate side by side comparisons between versions to assist with learning.

Motionblur10
------------
This Direct3D 10 sample demonstrates using a combination of fin extrusion in the geometry shader and anisotropic texture filtering to create the illusion of motion blur.

MultiMon10
----------
This sample shows how to handle multiple monitors in Direct3D 10.

MultiStreamRendering
--------------------
Multi-Stream rendering for Direct3D10 and Direct3D9 codepaths

NBodyGravity
------------
This is one of 3 sample applications shown during the Advanced Real-Time Rendering in 3D Graphics and Games course at SIGGraph 2007. The Direct3D 10 sample shows N-Body particles system managed entirely by the GPU.

ParticlesGS
-----------
This Direct3D 10 sample shows a particles system managed entirely by the GPU.

Pick10
------
This samples illustrates picking using Direct3D 10.

PipesGS
-------
This Direct3D 10 sample shows how to use the geometry shader to create new geometry on the fly.

ProceduralMaterials
-------------------
This Direct3D 10 sample shows various procedural materials created through shaders.

RaycastTerrain
--------------
This sample shows how to render terrain using cone-step mapping in the pixel shader.

ShadowVolume10
--------------
This Direct3D 10 sample shows how to implement shadow volume using the Geometry Shader. This sample also includes a Direct3D 9 fallback

Skinning10
----------
The Skinning10 sample demonstrates 4 different methods of indexing bone transformation matrices for GPU skinning. In addition, it demonstrates how stream out without a Geometry Shader can be used to cut down vertex processing cost when skinned model will used for mutiple rendering passes.

SoftParticles
-------------
This Direct3D 10 sample eliminates artifacts commonly seen when 2D particles intersect 3D geometry by reading the depth buffer and clipping particles against it smoothly. On a Direct3D 10.1 card, it also shows how to do the same technique against an MSAA enabled depth buffer.

SparseMorphTargets
------------------
This Direct3D 10 sample shows facial animation using sparse morph targets, wrinkle maps, and LDPRT lighting.

SubD10
------
This Direct3D 10 sample demonstrates Charles Loop's and Scott Schaefer's Approximate Catmull-Clark subdivision surface technique running on D3D10 hardware.

TransparencyAA10.1
------------------
This sample, contributed by AMD, presents a technique for achieving MSAA quality rendering for primitives that require transparency. It utilizes Direct3D 10.1 APIs and hardware to make use of the new fixed MSAA sample patterns, and the export of the coverage mask from the pixel shader.


==============================
4. Building Direct3D10 Samples
==============================
Debug versions of the Direct3D10 samples require the installation of the Direct3D Debug Layer. If the Direct3D Debug Layer is not installed, device creation will fail in debug builds due to the use of the debug flag.

To install the Direct3D Debug Layer:
* Go to Cortana
* Enter: Optional features
* Select: Add an Optional Feature
* Click: Add a feature
* Select and Install: Graphics Tools


The Direct3D10 samples still rely on the D3D10x header and library files from the DirectX SDK June 2010.

Download the DirectX SDK June 2010.  https://www.microsoft.com/en-us/download/details.aspx?id=6812

You do not need to install the SDK.  You only need to extract the following files.

Copy the following header files from the DirectX SDK June 2010 include\ directory, to the include\ directory in the root of the repository.  The readme.txt file in the directory provides these same instructions.

D3DX10.h
d3dx10async.h
D3DX10core.h
D3DX10math.h
D3DX10math.inl
D3DX10mesh.h
D3DX10tex.h
d3dx9.h
d3dx9anim.h
d3dx9core.h
d3dx9effect.h
d3dx9math.h
d3dx9math.inl
d3dx9mesh.h
d3dx9shader.h
d3dx9shape.h
d3dx9tex.h
d3dx9xof.h

Now, copy the following library files from the DirectX SDK June 2010 lib\ directory, to the lib\ directory in the root of the repository.  The readme.txt files in the lib\ directories provide these same instructions.

x64\d3dx10.lib
x64\d3dx10d.lib
x64\d3dx9.lib
x64\d3dx9d.lib
x64\dxguid.lib

x86\d3dx10.lib
x86\d3dx10d.lib
x86\d3dx9.lib
x86\d3dx9d.lib
x86\dxguid.lib

Once these files are copied, you can now successfully build and run any of the Direct3D10 samples.


====================
5. Direct3D9 Samples
====================
The following Direct3D9 samples are included:

AntiAlias
---------
Multisampling attempts to reduce aliasing by mimicking a higher resolution display; multiple sample points are used to determine each pixel's color. This sample shows how the various multisampling techniques supported by your video card affect the scene's rendering. Although multisampling effectively combats aliasing, under particular situations it can introduce visual artifacts of its own. As illustrated by the sample, centroid sampling seeks to eliminate one common type of multisampling artifact. Support for centroid sampling is supported under Pixel Shader 2.0 in the latest version of the DirectX runtime.

BasicHLSL
---------
This sample shows a simple example of the High-Level Shader Language (HLSL) using the effect interface.

CompiledEffect
--------------
This sample shows how an ID3DXEffect object can be compiled when the project is built and loaded directly as a binary file at runtime.

DepthOfField
------------
This sample shows a technique for creating a depth-of-field effect with Direct3D 9, in which objects are only in focus at a given distance from the camera, and are out of focus at other distances.

EffectParam
-----------
This sample shows two features in the Direct3D 9 Extension effect framework: parameter blocks and parameter sharing. Parameter blocks group multiple Setxxx() calls and associate them with an effect handle, allowing an application to easily set those parameters contained in the block with a single API call. Parameter sharing lets parameters in multiple effect objects stay synchronized, so that when an application updates a parameter in one effect object, the corresponding parameter in all other effect objects are updated.

HDRCubeMap
----------
This sample demonstrates cubic environment-mapping with floating-point cube textures and high dynamic range lighting. DirectX 9.0's new floating-point textures can store color values higher than 1.0, which can make lighting effects more realistic on the environment-mapped geometry when the material absorbs part of the light. Note that not all cards support all features for the environment-mapping and high dynamic range lighting techniques.

HDRFormats
----------
High dynamic range lighting effects require the ability to work with color values beyond the 0 to 255 range, usually by storing high range color data in textures. Floating point texture formats are the natural choice for HDR applications, but may not be available on all target systems. This sample shows how high dynamic range data can be encoded into integer formats for compatibility across a wide range of devices.

HDRLighting
-----------
This sample demonstrates some high dynamic range lighting effects using floating point textures. Integer texture formats have a limited range of discrete values, which results in lost color information under dynamic lighting conditions; conversely, floating point formats can store very small or very large color values, including values beyond the displayable 0.0 to 1.0 range. This flexibility allows for dynamic lighting effects, such as blue-shifting under low lighting and blooming under intense lighting. This sample also employs a simple light adaptation model, under which the camera is momentarily over-exposed or under-exposed to changing light conditions.

HDRPipeline
-----------
This sample, contributed by Jack Hoxley (a Microsoft Most Valuable Professional), demonstrates the numerous steps that occur "behind the scenes" in a High Dynamic Range rendering pipeline. Intended as an educational sample to complement existing examples, this implementation's difference is that it shows the results of all the intermediary stages and allows the user to change the parameters and get immediate feedback via the GUI.

HLSLwithoutEffects
------------------
This sample shows some of the effects that can be achieved using vertex shaders written in Microsoft Direct3D 9's High-Level Shader Language (HLSL). HLSL shaders have C-like syntax and constructs, such as functions, expressions, statements, and data types. A vertex shader looks very similar to a C function, and is executed by the 3D device once per every vertex processed to affect the properties of the vertex. Note that not all cards may support all the various features vertex shaders. For more information on vertex shaders, refer to the DirectX SDK documentation.

Instancing
----------
This sample demonstrates the new instancing feature available in DirectX 9.0c and shows alternate ways of achieving results similar to hardware instancing.

IrradianceVolume
----------------
This sample donated by ATI Technologies (www.ati.com) builds upon the PRTDemo Sample and adds preprocessing of the scene to create a volume of radiance samples stored in an octree. This technique allows a PRT object to use the local lighting environment as it moves through a scene. This sample includes a default data set for user experimentation but can be changed to use your own data sets.

LocalDeformablePRT
------------------
This sample demonstrates a simple usage of Local-deformable precomputed radiance transfer (LDPRT). This implementation does not require an offline simulator for calculating PRT coefficients; instead, the coefficients are calculated from a 'thickness' texture. This allows an artist to create and tweak sub-surface scattering PRT data in an intuitive way.

MeshFromOBJ
-----------
This sample shows how an ID3DXMesh object can be created from mesh data stored in a Wavefront Object file ( .obj). It's convenient to use X-Files (.x) when working with ID3DXMesh objects since D3DX can create and fill an ID3DXMesh object directly from an .x file; however, it's also easy to initialize an ID3DXMesh object with data gathered from any file format or memory resource. 

MultiAnimation
--------------
This sample demonstrates mesh animation with multiple animation sets using HLSL skinning and D3DX's animation controller. It shows how an application can render 3D animation by utilizing D3DX's animation support. D3DX has APIs that handles the loading of the animatable mesh, as well as the blending of multiple animations. The animation controller supports animation tracks for this purpose, and allows transitioning from one animation to another smoothly.

OptimizedMesh
-------------
The OptimizedMesh sample illustrates how to load and optimize a file-based mesh using the D3DX mesh utility functions. For more info on D3DX, refer to the DirectX SDK documentation.

ParallaxOcclusionMapping
------------------------
This sample donated by ATI Technologies (www.ati.com) presents the parallax occlusion mapping algorithm which employs per-pixel ray-tracing for dynamic lighting of surfaces in real-time on the GPU. The method uses a high precision algorithm for approximating view-dependent surface extrusion for a given height field to simulate motion parallax and perspective-correct depth. Additionally, the method allows generation of soft shadows in real-time for surface occlusions. This sample includes an automatic level-of-detail system for in-shader complexity scaling.

Pick
----
This samples illustrates picking using Direct3D 9.

PixelMotionBlur
---------------
This sample shows how to do a motion blur effect using floating point textures and multiple render targets. The first pass renders the scene to the first render target and writes the velocity of each pixel to the second render target. Then it renders a full screen quad and uses a pixel shader to look up the velocity of that pixel and blurs the pixel based on the velocity.

PostProcess
-----------
This sample demonstrates some interesting image-processing effects that can be achieved interactively. Traditionally, image-processing takes a significant amount of processor power on the host CPU, and is usually done offline. With pixel shaders, these effects can now be performed on the 3D hardware more efficiently, allowing them to be applied in real-time.

PRTCmdLine
----------
PRTCmdLine is a command line example tool that uses a D3DDEVTYPE_NULLREF Direct3D 9 device and an 'XML' options file to run the PRT simulator. The output can be viewed in a PRT application such as the PRTDemo sample.

PRTDemo
-------
This sample features several scenes which compare precomputed radiance transfer (PRT) implementations against the standard lighting equations

ShadowMap
---------
This sample demonstrates one popular shadow technique called shadow mapping. A shadow map, in the form of a floating-point texture, is written with depth information of the scene as if the camera is looking out from the light. Then, the shadow map is project onto the scene during rendering. The depth values in the scene are compared with those in the shadow map. If they do not match for a particular pixel, then that pixel is in shadow. This approach allows very efficient real-time shadow casting.

ShadowVolume
------------
The sample demonstrates one common technique for rendering real-time shadows called shadow volumes. The shadows in the sample work by extruding faces of the occluding geometry that are facing away from light to form a volume that represents the shadowed area in 3D space and utilizing the stencil buffer of the 3D device. Stencil buffer is a buffer that can be updated as geometry is rendered, and then used as a mask for rendering additional geometry. Common stencil effects include mirrors, shadows (an advanced technique), and dissolves.

SkinnedMesh
-----------
The SkinnedMesh sample shows how to use D3DX to load and display a skinned mesh.

StateManager
------------
This sample shows an example implementation of the ID3DXEffectStateManager interface. This inteface can be used to implement custom state-change handling for the D3DX Effects system.

Text3D
------
The Text3D sample shows how to draw 2D text and 3D text in a 3D scene. This is most useful for display stats, in game menus, etc.

UVAtlas
-------
UVAtlas.exe is a command line example tool that uses the D3DX UVAtlas and IMT computation functions to generate an optimal, unique texture parameterization for an input mesh. See the DirectX docs for more details on the UVAtlas API. 


==============================
6. Building Direct3D9 Samples
==============================
The Direct3D9 samples still rely on the D3D9x header and library files from the DirectX SDK June 2010.

Download the DirectX SDK June 2010.  https://www.microsoft.com/en-us/download/details.aspx?id=6812

You do not need to install the SDK.  You only need to extract the following files.

Copy the following header files from the DirectX SDK June 2010 include\ directory, to the include\ directory in the root of the repository.  The readme.txt file in the directory provides these same instructions.

D3DX10.h
d3dx10async.h
D3DX10core.h
D3DX10math.h
D3DX10math.inl
D3DX10mesh.h
D3DX10tex.h
d3dx9.h
d3dx9anim.h
d3dx9core.h
d3dx9effect.h
d3dx9math.h
d3dx9math.inl
d3dx9mesh.h
d3dx9shader.h
d3dx9shape.h
d3dx9tex.h
d3dx9xof.h

Now, copy the following library files from the DirectX SDK June 2010 lib\ directory, to the lib\ directory in the root of the repository.  The readme.txt files in the lib\ directories provide these same instructions.

x64\d3dx10.lib
x64\d3dx10d.lib
x64\d3dx9.lib
x64\d3dx9d.lib
x64\dxguid.lib

x86\d3dx10.lib
x86\d3dx10d.lib
x86\d3dx9.lib
x86\d3dx9d.lib
x86\dxguid.lib

Once these files are copied, you can now successfully build and run any of the Direct3D9 samples.
