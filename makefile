CC=g++
IN_DIR=./src
OUT_DIR=./output
EXEC=$(OUT_DIR)/Sort
CPP_FILES=$(wildcard $(IN_DIR)/*.cpp)
OBJ_FILES=$(addprefix $(OUT_DIR)/obj/,$(notdir $(CPP_FILES:.cpp=.o)))

$(OUT_DIR)/Sort: $(OBJ_FILES)
	$(CC) $^ -o $@

$(OUT_DIR)/obj/%.o: $(IN_DIR)/%.cpp
	$(CC) -c $< -o $@

clean:
	rm $(OUT_DIR)/obj/* $(OUT_DIR)/Sort
