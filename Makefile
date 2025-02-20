CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
EXEC = sql_exercise

SOURCES = $(shell find . -name "*.c")
OBJECTS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES))

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)
