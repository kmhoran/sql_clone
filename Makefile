CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
EXEC = sql_exercise

# Find all .c files in the current directory and subdirectories
SOURCES = $(shell find . -name "*.c")
# Convert the .c file names to .o file names in the build directory
OBJECTS = $(SOURCES:.c=$(BUILD_DIR)/.o)

# Default target
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile each .c file to .o file in the build directory
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build files
clean:
	rm -f $(OBJECTS) $(EXEC)
