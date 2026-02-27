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

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(BUILD)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD)
