CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 \
         -Wpedantic \
         -Wshadow \
         -Wconversion \
         -Wsign-conversion \
         -Wnull-dereference \
         -Wformat=2 \
         -Wuninitialized \
         -Wlogical-op \
         -fstack-protector-strong

BUILD = build
TARGET = $(BUILD)/calculator
SRC = src/main.c \
      src/libs/add/add.c \
      src/libs/minus/minus.c
OBJ = $(patsubst src/%.c, $(BUILD)/%.o, $(SRC))

TEST_MAIN = src/__tests__/main.c
TEST_SRC  = $(wildcard src/__tests__/**/*.c)
TEST_BIN  = $(BUILD)/tests
TEST_OBJ  = $(filter-out $(BUILD)/main.o, $(OBJ))

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(BUILD)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(TEST_MAIN) $(TEST_SRC) $(TEST_OBJ)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $(TEST_MAIN) $(TEST_SRC) $(TEST_OBJ) -lcheck -lm -lsubunit -pthread

test: $(TEST_BIN)
	$(TEST_BIN)

clean:
	rm -rf $(BUILD)