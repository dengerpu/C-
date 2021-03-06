# Microsoft Developer Studio Project File - Name="pcre" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=pcre - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pcre.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pcre.mak" CFG="pcre - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pcre - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "pcre - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pcre - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "DLL_EXPORT" /D "PCRE_STATIC" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "pcre - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "DLL_EXPORT" /D "PCRE_STATIC" /D "HAVE_CONFIG_H" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "pcre - Win32 Release"
# Name "pcre - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\pcre16_byte_order.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_chartables.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_compile.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_config.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_dfa_exec.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_exec.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_fullinfo.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_get.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_globals.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_jit_compile.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_maketables.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_newline.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_ord2utf16.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_refcount.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_string_utils.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_study.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_tables.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_ucd.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_utf16_utils.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_valid_utf16.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_version.c
# End Source File
# Begin Source File

SOURCE=.\pcre16_xclass.c
# End Source File
# Begin Source File

SOURCE=.\pcre_byte_order.c
# End Source File
# Begin Source File

SOURCE=.\pcre_chartables.c
# End Source File
# Begin Source File

SOURCE=.\pcre_compile.c
# End Source File
# Begin Source File

SOURCE=.\pcre_config.c
# End Source File
# Begin Source File

SOURCE=.\pcre_dfa_exec.c
# End Source File
# Begin Source File

SOURCE=.\pcre_exec.c
# End Source File
# Begin Source File

SOURCE=.\pcre_fullinfo.c
# End Source File
# Begin Source File

SOURCE=.\pcre_get.c
# End Source File
# Begin Source File

SOURCE=.\pcre_globals.c
# End Source File
# Begin Source File

SOURCE=.\pcre_jit_compile.c
# End Source File
# Begin Source File

SOURCE=.\pcre_maketables.c
# End Source File
# Begin Source File

SOURCE=.\pcre_newline.c
# End Source File
# Begin Source File

SOURCE=.\pcre_ord2utf8.c
# End Source File
# Begin Source File

SOURCE=.\pcre_refcount.c
# End Source File
# Begin Source File

SOURCE=.\pcre_string_utils.c
# End Source File
# Begin Source File

SOURCE=.\pcre_study.c
# End Source File
# Begin Source File

SOURCE=.\pcre_tables.c
# End Source File
# Begin Source File

SOURCE=.\pcre_ucd.c
# End Source File
# Begin Source File

SOURCE=.\pcre_valid_utf8.c
# End Source File
# Begin Source File

SOURCE=.\pcre_version.c
# End Source File
# Begin Source File

SOURCE=.\pcre_xclass.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=.\pcre.h
# End Source File
# Begin Source File

SOURCE=.\pcre_internal.h
# End Source File
# Begin Source File

SOURCE=.\ucp.h
# End Source File
# End Group
# End Target
# End Project
