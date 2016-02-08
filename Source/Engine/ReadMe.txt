========================================================================
    CONSOLE APPLICATION : Engine Project Overview
========================================================================

AppWizard has created this Engine application for you.

This file contains a summary of what you will find in each of the files that
make up your Engine application.


Engine.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Engine.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Engine.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:


/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

This program uses the windows platform sdk, autodesk fbs 2009.1 sdk, and the c++ xerces xml library.

To configure visual studio to link the proper files add the following and replace path with the appropriate path:

Tools->Options->Projects and Solutions->VC++ Directories
  Include Files
    path\xerces-c-3.1.1\src
    path\Autodesk\FBX\FbxSdk\2009.1\include\kbaselib
    path\Autodesk\FBX\FbxSdk\2009.1\include\fbxfilesdk
    path\Autodesk\FBX\FbxSdk\2009.1\include\
    path\Microsoft SDKs\Windows\v7.0\Include

  Library files
    path\Microsoft SDKs\Windows\v7.0\Lib
    path\Autodesk\FBX\FbxSdk\2009.1\lib
  
  C/C++
    Preprocessor Defs = WIN32;_DEBUG;_CONSOLE;K_PLUGIN;K_FBXSDK;K_NODLL;_CRT_SECURE_NO_DEPRECATE

  Linker
    Additional Dependancies = fbxsdk_md2008d.lib

  Dll's
    glut32.dll needs to be copied to Debug Release folders
	xcopy /Y D:\Projects\Games\Engine\Debug\glut32.dll $(OutDir)
    xcopy /Y D:\Projects\External\xerces-c-3.1.1\Build\Win32\VC10\$(IntDir)*.dll $(OutDir)
    
  Projects
    XercesLib
    Logging

/////////////////////////////////////////////////////////////////////////////
