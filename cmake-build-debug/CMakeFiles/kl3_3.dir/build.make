# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\777rd\CLionProjects\kl3_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\kl3_3.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\kl3_3.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\kl3_3.dir\flags.make

CMakeFiles\kl3_3.dir\main.cpp.obj: CMakeFiles\kl3_3.dir\flags.make
CMakeFiles\kl3_3.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kl3_3.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\kl3_3.dir\main.cpp.obj /FdCMakeFiles\kl3_3.dir\ /FS -c C:\Users\777rd\CLionProjects\kl3_3\main.cpp
<<

CMakeFiles\kl3_3.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kl3_3.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\kl3_3.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\777rd\CLionProjects\kl3_3\main.cpp
<<

CMakeFiles\kl3_3.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kl3_3.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\kl3_3.dir\main.cpp.s /c C:\Users\777rd\CLionProjects\kl3_3\main.cpp
<<

CMakeFiles\kl3_3.dir\classes.cpp.obj: CMakeFiles\kl3_3.dir\flags.make
CMakeFiles\kl3_3.dir\classes.cpp.obj: ..\classes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kl3_3.dir/classes.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\kl3_3.dir\classes.cpp.obj /FdCMakeFiles\kl3_3.dir\ /FS -c C:\Users\777rd\CLionProjects\kl3_3\classes.cpp
<<

CMakeFiles\kl3_3.dir\classes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kl3_3.dir/classes.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\kl3_3.dir\classes.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\777rd\CLionProjects\kl3_3\classes.cpp
<<

CMakeFiles\kl3_3.dir\classes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kl3_3.dir/classes.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\kl3_3.dir\classes.cpp.s /c C:\Users\777rd\CLionProjects\kl3_3\classes.cpp
<<

# Object files for target kl3_3
kl3_3_OBJECTS = \
"CMakeFiles\kl3_3.dir\main.cpp.obj" \
"CMakeFiles\kl3_3.dir\classes.cpp.obj"

# External object files for target kl3_3
kl3_3_EXTERNAL_OBJECTS =

kl3_3.exe: CMakeFiles\kl3_3.dir\main.cpp.obj
kl3_3.exe: CMakeFiles\kl3_3.dir\classes.cpp.obj
kl3_3.exe: CMakeFiles\kl3_3.dir\build.make
kl3_3.exe: CMakeFiles\kl3_3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable kl3_3.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\kl3_3.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\kl3_3.dir\objects1.rsp @<<
 /out:kl3_3.exe /implib:kl3_3.lib /pdb:C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug\kl3_3.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\kl3_3.dir\build: kl3_3.exe
.PHONY : CMakeFiles\kl3_3.dir\build

CMakeFiles\kl3_3.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kl3_3.dir\cmake_clean.cmake
.PHONY : CMakeFiles\kl3_3.dir\clean

CMakeFiles\kl3_3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\777rd\CLionProjects\kl3_3 C:\Users\777rd\CLionProjects\kl3_3 C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug C:\Users\777rd\CLionProjects\kl3_3\cmake-build-debug\CMakeFiles\kl3_3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\kl3_3.dir\depend

