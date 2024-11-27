# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Linker flags for GLFW and GLEW
LDFLAGS = -lglfw -lGLEW -lGL

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = builds
SHADER_DIR = shaders

# Output binary
TARGET = $(BUILD_DIR)/my_project

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link object files to create the final binary
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the project from the root directory
run: all
	./$(TARGET)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean run

