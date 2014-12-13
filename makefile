CC=g++
IN_DIR=./src
OUT_DIR=./output
EXEC=$(OUT_DIR)/Sort
CPP_FILES=$(wildcard $(IN_DIR)/*.cpp)
OBJ_FILES=$(addprefix $(OUT_DIR)/obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all: createOutputDirs $(OUT_DIR)/Sort

createOutputDirs:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/obj

$(OUT_DIR)/Sort: $(OBJ_FILES)
	$(CC) $^ -o $@

$(OUT_DIR)/obj/%.o: $(IN_DIR)/%.cpp
	$(CC) -c $< -o $@

clean:
	@rm -rf $(OUT_DIR)
