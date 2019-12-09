# LearningCPP

|Resources|Description|
|--|--|
|GNU g++|primary C++ compiler for this project|
|make|primary build system, should be provided by GNU g++|
|clang|needed for clang-format, may alternatively use clang c++ compiler|

### Create a new Project
To make a new project, run tools/new-project.sh script.\
A new project directory will be created in the current working directory for you. This project will contain\
configuration for clang-format, editorconfig, and a basic makefile.
```
./tools/new-project.sh [name of new project]
```