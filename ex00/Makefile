# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 16:12:07 by tbui-quo          #+#    #+#              #
#    Updated: 2025/04/24 16:12:09 by tbui-quo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for megaphone.cpp

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = megaphone

# Source file
SRC = MegaPhone.cpp

# Object file
OBJ = MegaPhone.o

# Default target
all: $(TARGET)

# Linking the object file(s) to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compiling source file to object file
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC)

# Clean up object files
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

# Optional: rebuild everything
re: clean all
