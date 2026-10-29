CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

BIN := bin
SIS := sistema-productos
SIS_SRC := $(wildcard $(SIS)/src/*.cpp)
SIS_INC := $(wildcard $(SIS)/include/*.h)

.PHONY: all practica1 sistema run-practica1 run-sistema clean

all: practica1 sistema

practica1: $(BIN)/areas_inline
sistema: $(BIN)/sistema_productos

$(BIN)/areas_inline: practica1-areas-inline/areas_inline.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN)/sistema_productos: $(SIS_SRC) $(SIS_INC) | $(BIN)
	$(CXX) $(CXXFLAGS) -I$(SIS)/include $(SIS_SRC) -o $@

$(BIN):
	mkdir -p $(BIN)

run-practica1: practica1
	./$(BIN)/areas_inline

run-sistema: sistema
	./$(BIN)/sistema_productos

clean:
	rm -rf $(BIN)
