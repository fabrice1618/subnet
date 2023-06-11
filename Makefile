CXX       := gcc
CXX_FLAGS := -std=c17 -ggdb -Wall -Werror -Wextra -Wpedantic
BIN     := bin
SRC     := src
INCLUDE := include
LIBRARIES   :=
EXECUTABLE  := subnet

all: $(BIN)/$(EXECUTABLE)

opt: opt.c
	$(CXX) $(CXX_FLAGS) $^ -o $@

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

test:
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
