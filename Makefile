CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
SOURCE_DIR = src
TEST_DIR = tst
EXEC = sql_exercise
TEST_EXEC = test_sql_exercise

SOURCES = $(shell find $(SOURCE_DIR) -name "*.c")
TEST_SOURCES = $(shell find $(TEST_DIR) -name "*.c")

OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test_%.o, $(TEST_SOURCES))

LIBS = -lcmocka
LDFLAGS = $(LIBS)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

buildTests: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -o $(TEST_EXEC) -l cmocka -L /usr/local/lib

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: buildTests
	./$(TEST_EXEC)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXEC) $(TEST_EXEC)
