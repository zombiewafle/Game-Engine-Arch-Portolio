# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zombiewafle/Escritorio/ECS_Pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zombiewafle/Escritorio/ECS_Pong/build

# Include any dependencies generated for this target.
include CMakeFiles/GAME.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GAME.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GAME.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GAME.dir/flags.make

CMakeFiles/GAME.dir/src/main.cpp.o: CMakeFiles/GAME.dir/flags.make
CMakeFiles/GAME.dir/src/main.cpp.o: /home/zombiewafle/Escritorio/ECS_Pong/src/main.cpp
CMakeFiles/GAME.dir/src/main.cpp.o: CMakeFiles/GAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GAME.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GAME.dir/src/main.cpp.o -MF CMakeFiles/GAME.dir/src/main.cpp.o.d -o CMakeFiles/GAME.dir/src/main.cpp.o -c /home/zombiewafle/Escritorio/ECS_Pong/src/main.cpp

CMakeFiles/GAME.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GAME.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zombiewafle/Escritorio/ECS_Pong/src/main.cpp > CMakeFiles/GAME.dir/src/main.cpp.i

CMakeFiles/GAME.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GAME.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zombiewafle/Escritorio/ECS_Pong/src/main.cpp -o CMakeFiles/GAME.dir/src/main.cpp.s

CMakeFiles/GAME.dir/src/Game/Game.cpp.o: CMakeFiles/GAME.dir/flags.make
CMakeFiles/GAME.dir/src/Game/Game.cpp.o: /home/zombiewafle/Escritorio/ECS_Pong/src/Game/Game.cpp
CMakeFiles/GAME.dir/src/Game/Game.cpp.o: CMakeFiles/GAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GAME.dir/src/Game/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GAME.dir/src/Game/Game.cpp.o -MF CMakeFiles/GAME.dir/src/Game/Game.cpp.o.d -o CMakeFiles/GAME.dir/src/Game/Game.cpp.o -c /home/zombiewafle/Escritorio/ECS_Pong/src/Game/Game.cpp

CMakeFiles/GAME.dir/src/Game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GAME.dir/src/Game/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zombiewafle/Escritorio/ECS_Pong/src/Game/Game.cpp > CMakeFiles/GAME.dir/src/Game/Game.cpp.i

CMakeFiles/GAME.dir/src/Game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GAME.dir/src/Game/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zombiewafle/Escritorio/ECS_Pong/src/Game/Game.cpp -o CMakeFiles/GAME.dir/src/Game/Game.cpp.s

CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o: CMakeFiles/GAME.dir/flags.make
CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o: /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Page1.cpp
CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o: CMakeFiles/GAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o -MF CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o.d -o CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o -c /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Page1.cpp

CMakeFiles/GAME.dir/src/Page1/Page1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GAME.dir/src/Page1/Page1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Page1.cpp > CMakeFiles/GAME.dir/src/Page1/Page1.cpp.i

CMakeFiles/GAME.dir/src/Page1/Page1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GAME.dir/src/Page1/Page1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Page1.cpp -o CMakeFiles/GAME.dir/src/Page1/Page1.cpp.s

CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o: CMakeFiles/GAME.dir/flags.make
CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o: /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Systems.cpp
CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o: CMakeFiles/GAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o -MF CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o.d -o CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o -c /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Systems.cpp

CMakeFiles/GAME.dir/src/Page1/Systems.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GAME.dir/src/Page1/Systems.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Systems.cpp > CMakeFiles/GAME.dir/src/Page1/Systems.cpp.i

CMakeFiles/GAME.dir/src/Page1/Systems.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GAME.dir/src/Page1/Systems.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zombiewafle/Escritorio/ECS_Pong/src/Page1/Systems.cpp -o CMakeFiles/GAME.dir/src/Page1/Systems.cpp.s

CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o: CMakeFiles/GAME.dir/flags.make
CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o: /home/zombiewafle/Escritorio/ECS_Pong/src/Scene/Scene.cpp
CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o: CMakeFiles/GAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o -MF CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o.d -o CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o -c /home/zombiewafle/Escritorio/ECS_Pong/src/Scene/Scene.cpp

CMakeFiles/GAME.dir/src/Scene/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GAME.dir/src/Scene/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zombiewafle/Escritorio/ECS_Pong/src/Scene/Scene.cpp > CMakeFiles/GAME.dir/src/Scene/Scene.cpp.i

CMakeFiles/GAME.dir/src/Scene/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GAME.dir/src/Scene/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zombiewafle/Escritorio/ECS_Pong/src/Scene/Scene.cpp -o CMakeFiles/GAME.dir/src/Scene/Scene.cpp.s

CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o: CMakeFiles/GAME.dir/flags.make
CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o: /home/zombiewafle/Escritorio/ECS_Pong/src/Scripting/scriptManager.cpp
CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o: CMakeFiles/GAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o -MF CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o.d -o CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o -c /home/zombiewafle/Escritorio/ECS_Pong/src/Scripting/scriptManager.cpp

CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zombiewafle/Escritorio/ECS_Pong/src/Scripting/scriptManager.cpp > CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.i

CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zombiewafle/Escritorio/ECS_Pong/src/Scripting/scriptManager.cpp -o CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.s

# Object files for target GAME
GAME_OBJECTS = \
"CMakeFiles/GAME.dir/src/main.cpp.o" \
"CMakeFiles/GAME.dir/src/Game/Game.cpp.o" \
"CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o" \
"CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o" \
"CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o" \
"CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o"

# External object files for target GAME
GAME_EXTERNAL_OBJECTS =

GAME: CMakeFiles/GAME.dir/src/main.cpp.o
GAME: CMakeFiles/GAME.dir/src/Game/Game.cpp.o
GAME: CMakeFiles/GAME.dir/src/Page1/Page1.cpp.o
GAME: CMakeFiles/GAME.dir/src/Page1/Systems.cpp.o
GAME: CMakeFiles/GAME.dir/src/Scene/Scene.cpp.o
GAME: CMakeFiles/GAME.dir/src/Scripting/scriptManager.cpp.o
GAME: CMakeFiles/GAME.dir/build.make
GAME: /usr/lib/libSDL2_image.so
GAME: /usr/lib/liblua5.4.so
GAME: /usr/lib/libm.so
GAME: CMakeFiles/GAME.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable GAME"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GAME.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GAME.dir/build: GAME
.PHONY : CMakeFiles/GAME.dir/build

CMakeFiles/GAME.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GAME.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GAME.dir/clean

CMakeFiles/GAME.dir/depend:
	cd /home/zombiewafle/Escritorio/ECS_Pong/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zombiewafle/Escritorio/ECS_Pong /home/zombiewafle/Escritorio/ECS_Pong /home/zombiewafle/Escritorio/ECS_Pong/build /home/zombiewafle/Escritorio/ECS_Pong/build /home/zombiewafle/Escritorio/ECS_Pong/build/CMakeFiles/GAME.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GAME.dir/depend

