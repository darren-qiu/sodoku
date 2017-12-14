
CXX = g++
CFLAGES := -Wall -O3 -std=c++0x
DEBUG = $(CFLAGES) 
 
INC = -I ./
BIN = sodoku
OBJ = cell.o \
	  check.o \
	  sodoku.o \
	  main.o\

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(DEBUG) $(OBJ) -o $@ $(CFLAGS) $(INC)

%.o: %.cpp
	$(CXX) $(DEBUG) -c $< -o $@ $(CFLAGS) $(INC)

clean:
	rm -f *.o
	rm -f $(BIN)
