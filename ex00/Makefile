# Makefile for megaphone.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = megaphone

# Source file
SRC = megaphone.cpp

# Default target
all: $(TARGET)

# Linking the object file(s) to create the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

# Optional: rebuild everything
re: clean all
