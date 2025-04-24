# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = phonebook

# Source files (using wildcard)
SRC = $(wildcard *.cpp)

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Linking the object file(s) to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compiling each source file to object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files
clean:
	rm -f $(OBJ)

# Remove both object files and executable
fclean: clean
	rm -f $(TARGET)

# Optional: rebuild everything (full clean + rebuild)
re: fclean all
