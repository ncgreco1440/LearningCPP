# Source Directory, any *.cpp and *.h file should be located here
SRC_DIR = src
# Binary Directory
BIN_DIR = bin
# Intermediate Directory, all *.o files go here
INT_DIR = bin-int
# Compiler to use
CC = g++
# C++ specification to use. \
Developer's Note: Honestly there is no reason to not use c++17
CPP_SPECIFICATION = c++17
cpp_spec_opt = -std=$(CPP_SPECIFICATION)
# Include files
INCLUDES = -I headers -I include -I ${MINGW_HOME}/include
inc_file_opt = $(INCLUDES)
# Optimizations \
O0 = no optimization \
O1 = some optimzation \
O2 = moar optimization \
O3 = even moar optimization
OPTIMIZATION = O0
optimization_opt = -$(OPTIMIZATION)
# Warnings \
This option will only support 1 argument \
Best bet is just use Wall to enable all warnings
WARNINGS = Wall
warn_opt = -$(WARNINGS) -Wextra
# Concat User Options
user_opts = 	$(warn_opt) \
							$(optimization_opt) \
							$(inc_file_opt) \
							$(cpp_spec_opt)
# Compiler flags
CFLAGS = -g -MD $(user_opts)
# Sources
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Object files the compiler should expect
object_files := $(subst $(SRC_DIR),$(INT_DIR),$(SRCS))
OBJS := $(subst .cpp,.o,$(object_files))
OBJS_ASM := $(subst .cpp,.s,$(object_files))

app : mkdir $(OBJS)
	$(CC) -o $(BIN_DIR)/app $(OBJS)

asm : mkdir $(OBJS_ASM)

$(INT_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(INT_DIR)/%.s : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -S $< -o $@

# Create all necessary directories if no exist
mkdir : mkdir_bin mkdir_bin_int

# Create bin (Binary) directory if no exist
mkdir_bin :
	mkdir -p $(BIN_DIR)

# Create bin_int (Intermediates) directory if no exist
mkdir_bin_int :
	mkdir -p $(INT_DIR)

# Clean everything up
clean : clean_int clean_bin

# Clean up binaries
clean_bin :
	rm -rf $(BIN_DIR)

# Clean up intermediates
clean_int :
	rm -rf $(INT_DIR)

-include $(OBJS:.o=.d)