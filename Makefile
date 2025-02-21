CC = gcc
CFLAGS = -Wall -Wno-unused-function
BUILD_DIR = build
SOURCE_DIR = src
TEST_DIR = tst
EXEC = sql_exercise
TEST_EXEC = test_sql_exercise
MAIN_FILE = main

# Designate MAIN variables
MAIN_SOURCE = $(SOURCE_DIR)/$(MAIN_FILE).c
MAIN_OBJECT = $(BUILD_DIR)/$(MAIN_FILE).o

SOURCES = $(shell find $(SOURCE_DIR) -name "*.c" | grep -v "$(MAIN_SOURCE)")

TEST_SOURCES = $(shell find $(TEST_DIR) -name "*.c")

OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test_%.o, $(TEST_SOURCES))

LIBS = -lcmocka
LDFLAGS = $(LIBS)

$(EXEC): $(MAIN_OBJECT) $(OBJECTS)
	$(CC) $(CFLAGS) $(MAIN_OBJECT) $(OBJECTS) -o $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Utility Commands

run: $(EXEC)
	./$(EXEC)

buildTests: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(TEST_OBJECTS) -o $(TEST_EXEC) -l cmocka -L /usr/local/lib

test: buildTests
	./$(TEST_EXEC)

clean:
	rm -f $(MAIN_OBJECT) $(OBJECTS) $(TEST_OBJECTS) $(EXEC) $(TEST_EXEC)
