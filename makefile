CC=g++
IN_DIR=./src
OUT_DIR=./output
OUT_OBJ_DIR=$(OUT_DIR)/obj
UI_DIR=./ui
TEST_DIR=./tests
EXEC=$(OUT_DIR)/Sort
CPP_FILES=$(wildcard $(IN_DIR)/*.cpp)
OBJ_FILES=$(addprefix $(OUT_OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

all: createOutputDirs $(OUT_DIR)/Sort $(OUT_DIR)/Test

createOutputDirs:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_OBJ_DIR)

$(OUT_OBJ_DIR)/%.o: $(IN_DIR)/%.cpp
	$(CC) -c $< -o $@

$(OUT_DIR)/Sort: $(OBJ_FILES) $(OUT_OBJ_DIR)/UIMain.o
	@echo "Linking Sort"
	@$(CC) $^ -o $@

$(OUT_OBJ_DIR)/UIMain.o: $(UI_DIR)/UIMain.cpp
	$(CC) -c $< -o $@

$(OUT_DIR)/Test: $(OBJ_FILES) $(OUT_OBJ_DIR)/TestMain.o
	@echo "Linking Test"
	@$(CC) $^ -o $@

$(OUT_OBJ_DIR)/TestMain.o: $(TEST_DIR)/TestMain.cpp
	$(CC) -c $< -o $@

clean:
	@rm -rf $(OUT_DIR)
