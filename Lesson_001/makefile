# Source Directory, any *.cpp and *.h file should be located here
SRC_DIR = src
# Binary Directory
BIN_DIR = bin
# Intermediate Directory, all *.o files go here
INT_DIR = bin-int
# Compiler to use
CC = g++
# Compiler flags
CFLAGS = -g -Wall
# Object files the compiler should expect
OBJS = $(INT_DIR)/*.o

app: mkdir main.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/app $(OBJS)

main.o : $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c -o $(INT_DIR)/main.o $(SRC_DIR)/main.cpp

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