
CC = g++
VER = -std=c++11

SRC := src
OBJ := obj

SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

labs01: $(OBJECTS)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(VER) -o $@ -c $<
