========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : Student_Info
========================================================================


AppWizard has created this Student_Info application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your Student_Info application.

Student_Info.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

Student_Info.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CStudent_InfoApp application class.

Student_Info.cpp
    This is the main application source file that contains the application
    class CStudent_InfoApp.

Student_Info.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

Student_Info.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\Student_Info.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file Student_Info.rc.

res\Student_Info.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.

Student_Info.reg
    This is an example .REG file that shows you the kind of registration
    settings the framework will set for you.  You can use this as a .REG
    file to go along with your application.

Student_Info.odl
    This file contains the Object Description Language source code for the
    type library of your application.



/////////////////////////////////////////////////////////////////////////////

AppWizard creates one dialog class and automation proxy class:

Student_InfoDlg.h, Student_InfoDlg.cpp - the dialog
    These files contain your CStudent_InfoDlg class.  This class defines
    the behavior of your application's main dialog.  The dialog's
    template is in Student_Info.rc, which can be edited in Microsoft
	Visual C++.

DlgProxy.h, DlgProxy.cpp - the automation object
    These files contain your CStudent_InfoDlgAutoProxy class.  This class
    is called the "automation proxy" class for your dialog, because it
    takes care of exposing the automation methods and properties that
    automation controllers can use to access your dialog.  These methods
    and properties are not exposed from the dialog class directly, because
    in the case of a modal dialog-based MFC application it is cleaner and
    easier to keep the automation object separate from the user interface.

/////////////////////////////////////////////////////////////////////////////

Help Support:

hlp\Student_Info.hpj
    This file is the Help Project file used by the Help compiler to create
    your application's Help file.

hlp\*.bmp
    These are bitmap files required by the standard Help file topics for
    Microsoft Foundation Class Library standard commands.

hlp\*.rtf
    This file contains the standard help topics for standard MFC
    commands and screen objects.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Student_Info.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is 
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC42XXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFC42DEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////
