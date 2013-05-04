# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Include_Path=
Release_Include_Path=

# Library paths...
Debug_Library_Path=
Release_Library_Path=

# Additional libraries...
Debug_Libraries=
Release_Libraries=

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D GCC_BUILD 
Release_Preprocessor_Definitions=-D GCC_BUILD 

# Implictly linked object files...
Debug_Implicitly_Linked_Objects=
Release_Implicitly_Linked_Objects=

# Compiler flags...
Debug_Compiler_Flags=-O0 -g 
Release_Compiler_Flags=-O2 -g 

# Builds all configurations for this project...
.PHONY: build_all_configurations
build_all_configurations: Debug Release 

# Builds the Debug configuration...
.PHONY: Debug
Debug: create_folders gccDebug/DynamicProblem.o gccDebug/main.o gccDebug/Printer.o gccDebug/Problem.o gccDebug/Range.o gccDebug/String.o gccDebug/GloutonProblem.o 
	g++ gccDebug/DynamicProblem.o gccDebug/main.o gccDebug/Printer.o gccDebug/Problem.o gccDebug/Range.o gccDebug/String.o gccDebug/GloutonProblem.o  $(Debug_Library_Path) $(Debug_Libraries) -Wl,-rpath,./ -o ../gccDebug/li325.exe

# Compiles file DynamicProblem.cpp for the Debug configuration...
-include gccDebug/DynamicProblem.d
gccDebug/DynamicProblem.o: DynamicProblem.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c DynamicProblem.cpp $(Debug_Include_Path) -o gccDebug/DynamicProblem.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM DynamicProblem.cpp $(Debug_Include_Path) > gccDebug/DynamicProblem.d

# Compiles file main.cpp for the Debug configuration...
-include gccDebug/main.d
gccDebug/main.o: main.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c main.cpp $(Debug_Include_Path) -o gccDebug/main.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM main.cpp $(Debug_Include_Path) > gccDebug/main.d

# Compiles file Printer.cpp for the Debug configuration...
-include gccDebug/Printer.d
gccDebug/Printer.o: Printer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Printer.cpp $(Debug_Include_Path) -o gccDebug/Printer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Printer.cpp $(Debug_Include_Path) > gccDebug/Printer.d

# Compiles file Problem.cpp for the Debug configuration...
-include gccDebug/Problem.d
gccDebug/Problem.o: Problem.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Problem.cpp $(Debug_Include_Path) -o gccDebug/Problem.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Problem.cpp $(Debug_Include_Path) > gccDebug/Problem.d

# Compiles file Range.cpp for the Debug configuration...
-include gccDebug/Range.d
gccDebug/Range.o: Range.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Range.cpp $(Debug_Include_Path) -o gccDebug/Range.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Range.cpp $(Debug_Include_Path) > gccDebug/Range.d

# Compiles file String.cpp for the Debug configuration...
-include gccDebug/String.d
gccDebug/String.o: String.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c String.cpp $(Debug_Include_Path) -o gccDebug/String.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM String.cpp $(Debug_Include_Path) > gccDebug/String.d

# Compiles file GloutonProblem.cpp for the Debug configuration...
-include gccDebug/GloutonProblem.d
gccDebug/GloutonProblem.o: GloutonProblem.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c GloutonProblem.cpp $(Debug_Include_Path) -o gccDebug/GloutonProblem.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM GloutonProblem.cpp $(Debug_Include_Path) > gccDebug/GloutonProblem.d

# Builds the Release configuration...
.PHONY: Release
Release: create_folders gccRelease/DynamicProblem.o gccRelease/main.o gccRelease/Printer.o gccRelease/Problem.o gccRelease/Range.o gccRelease/String.o gccRelease/GloutonProblem.o 
	g++ gccRelease/DynamicProblem.o gccRelease/main.o gccRelease/Printer.o gccRelease/Problem.o gccRelease/Range.o gccRelease/String.o gccRelease/GloutonProblem.o  $(Release_Library_Path) $(Release_Libraries) -Wl,-rpath,./ -o ../gccRelease/li325.exe

# Compiles file DynamicProblem.cpp for the Release configuration...
-include gccRelease/DynamicProblem.d
gccRelease/DynamicProblem.o: DynamicProblem.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c DynamicProblem.cpp $(Release_Include_Path) -o gccRelease/DynamicProblem.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM DynamicProblem.cpp $(Release_Include_Path) > gccRelease/DynamicProblem.d

# Compiles file main.cpp for the Release configuration...
-include gccRelease/main.d
gccRelease/main.o: main.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -o li325 -c main.cpp $(Release_Include_Path) -o gccRelease/main.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM main.cpp $(Release_Include_Path) > gccRelease/main.d

# Compiles file Printer.cpp for the Release configuration...
-include gccRelease/Printer.d
gccRelease/Printer.o: Printer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Printer.cpp $(Release_Include_Path) -o gccRelease/Printer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Printer.cpp $(Release_Include_Path) > gccRelease/Printer.d

# Compiles file Problem.cpp for the Release configuration...
-include gccRelease/Problem.d
gccRelease/Problem.o: Problem.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Problem.cpp $(Release_Include_Path) -o gccRelease/Problem.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Problem.cpp $(Release_Include_Path) > gccRelease/Problem.d

# Compiles file Range.cpp for the Release configuration...
-include gccRelease/Range.d
gccRelease/Range.o: Range.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Range.cpp $(Release_Include_Path) -o gccRelease/Range.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Range.cpp $(Release_Include_Path) > gccRelease/Range.d

# Compiles file String.cpp for the Release configuration...
-include gccRelease/String.d
gccRelease/String.o: String.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c String.cpp $(Release_Include_Path) -o gccRelease/String.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM String.cpp $(Release_Include_Path) > gccRelease/String.d

# Compiles file GloutonProblem.cpp for the Release configuration...
-include gccRelease/GloutonProblem.d
gccRelease/GloutonProblem.o: GloutonProblem.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c GloutonProblem.cpp $(Release_Include_Path) -o gccRelease/GloutonProblem.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM GloutonProblem.cpp $(Release_Include_Path) > gccRelease/GloutonProblem.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p gccDebug
	mkdir -p ../gccDebug
	mkdir -p gccRelease
	mkdir -p ../gccRelease

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f gccDebug/*.o
	rm -f gccDebug/*.d
	rm -f ../gccDebug/*.a
	rm -f ../gccDebug/*.so
	rm -f ../gccDebug/*.dll
	rm -f ../gccDebug/*.exe
	rm -f gccRelease/*.o
	rm -f gccRelease/*.d
	rm -f ../gccRelease/*.a
	rm -f ../gccRelease/*.so
	rm -f ../gccRelease/*.dll
	rm -f ../gccRelease/*.exe

