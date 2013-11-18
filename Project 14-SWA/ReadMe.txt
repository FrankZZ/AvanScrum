================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : Project 14-SWA Project Overview
===============================================================================

The application wizard has created this Project 14-SWA application for
you.  This application not only demonstrates the basics of using the Microsoft
Foundation Classes but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your Project 14-SWA application.

Project 14-SWA.vcxproj
    This is the main project file for VC++ projects generated using an application wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    application wizard.

Project 14-SWA.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Project 14-SWA.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CProject14SWAApp application class.

Project 14-SWA.cpp
    This is the main application source file that contains the application
    class CProject14SWAApp.

Project 14-SWA.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++. Your project resources are in 1033.

res\Project 14-SWA.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file Project 14-SWA.rc.

res\Project14SWA.rc2
    This file contains resources that are not edited by Microsoft
    Visual C++. You should place all resources not editable by
    the resource editor in this file.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:
    The project includes a standard MFC interface.

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CMDIFrameWnd and controls all MDI frame features.

res\Toolbar.bmp
    This bitmap file is used to create tiled images for the toolbar.
    The initial toolbar and status bar are constructed in the CMainFrame
    class. Edit this toolbar bitmap using the resource editor, and
    update the IDR_MAINFRAME TOOLBAR array in Project 14-SWA.rc to add
    toolbar buttons.
/////////////////////////////////////////////////////////////////////////////

For the child frame window:

ChildFrm.h, ChildFrm.cpp
    These files define and implement the CChildFrame class, which
    supports the child windows in an MDI application.

/////////////////////////////////////////////////////////////////////////////

The application wizard creates one document type and one view:

Project 14-SWADoc.h, Project 14-SWADoc.cpp - the document
    These files contain your CProject14SWADoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CProject14SWADoc::Serialize).

Project 14-SWAView.h, Project 14-SWAView.cpp - the view of the document
    These files contain your CProject14SWAView class.
    CProject14SWAView objects are used to view CProject14SWADoc objects.

res\Project 14-SWADoc.ico
    This is an icon file, which is used as the icon for MDI child windows
    for the CProject14SWADoc class.  This icon is included by the main
    resource file Project 14-SWA.rc.




/////////////////////////////////////////////////////////////////////////////

Other Features:

ActiveX Controls
    The application includes support to use ActiveX controls.

Printing and Print Preview support
    The application wizard has generated code to handle the print, print setup, and print preview
    commands by calling member functions in the CView class from the MFC library.

/////////////////////////////////////////////////////////////////////////////

Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Project 14-SWA.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

Project 14-SWA.manifest
	Application manifest files are used by Windows XP to describe an applications
	dependency on specific versions of Side-by-Side assemblies. The loader uses this
	information to load the appropriate assembly from the assembly cache or private
	from the application. The Application manifest  maybe included for redistribution
	as an external .manifest file that is installed in the same folder as the application
	executable or it may be included in the executable in the form of a resource.
/////////////////////////////////////////////////////////////////////////////

Other notes:

The application wizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, you will need
to redistribute the MFC DLLs. If your application is in a language
other than the operating system's locale, you will also have to
redistribute the corresponding localized resources MFC100XXX.DLL.
For more information on both of these topics, please see the section on
redistributing Visual C++ applications in MSDN documentation.

/////////////////////////////////////////////////////////////////////////////
