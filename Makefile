BUILD     = build
TARGET    = $(BUILD)/calculator
OBJ_DIR   = $(BUILD)/obj
TEST_DIR  = $(BUILD)/test

SRC = src/main.c \
      src/libs/add/add.c \
      src/libs/minus/minus.c
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

TEST_MAIN = src/__tests__/main.c
TEST_SRC  = $(wildcard src/__tests__/**/*.c)
TEST_BIN  = $(BUILD)/tests
TEST_OBJ  = $(filter-out $(OBJ_DIR)/main.o, $(OBJ))

COVERAGE_FLAGS = --coverage -fprofile-arcs -ftest-coverage
COVERAGE_DIR   = $(BUILD)/coverage
COVERAGE_BIN   = $(COVERAGE_DIR)/tests
COVERAGE_OBJ   = $(patsubst src/%.c, $(COVERAGE_DIR)/%.o, $(filter-out src/main.c, $(SRC)))

LINT_SRC = $(SRC) $(TEST_MAIN) $(TEST_SRC)
CLANG_TIDY_CHECKS = -checks=clang-diagnostic-*,clang-analyzer-*,bugprone-*,modernize-*,performance-*,portability-*,readability-*,-readability-magic-numbers,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling

CLANG_FORMAT_STYLE = --style="{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 100}"

.PHONY: all clean run test coverage lint format format-check

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(TEST_MAIN) $(TEST_SRC) $(TEST_OBJ)
	mkdir -p $(TEST_DIR)
	$(CC) $(CFLAGS) -o $@ $(TEST_MAIN) $(TEST_SRC) $(TEST_OBJ) -lcheck -lm -lsubunit -pthread

test: $(TEST_BIN)
	$(TEST_BIN)

$(COVERAGE_DIR)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

$(COVERAGE_BIN): $(TEST_MAIN) $(TEST_SRC) $(COVERAGE_OBJ)
	mkdir -p $(COVERAGE_DIR)
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -o $@ $(TEST_MAIN) $(TEST_SRC) $(COVERAGE_OBJ) -lcheck -lm -lsubunit -pthread

coverage: $(COVERAGE_BIN)
	$(COVERAGE_BIN)
	lcov --capture --directory $(COVERAGE_DIR) --output-file $(COVERAGE_DIR)/coverage.info
	genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR)/html
	@echo "Report: $(COVERAGE_DIR)/index.html"

lint:
	clang-tidy $(CLANG_TIDY_CHECKS) $(LINT_SRC) -- $(CFLAGS)

format:
	clang-format $(CLANG_FORMAT_STYLE) -i $(SRC) $(TEST_MAIN) $(TEST_SRC)

format-check:
	clang-format $(CLANG_FORMAT_STYLE) --dry-run --Werror $(SRC) $(TEST_MAIN) $(TEST_SRC)

clean:
	rm -rf $(BUILD)