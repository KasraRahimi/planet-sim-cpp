# compiler
CC=g++
CFlags=-Wall

# directories
LIB_DIR=-L../lib_dir/target
INC_DIR=-I../lib_dir/include

# files
LIB=-lPlanetSim -lSDL2
SRC=main.cpp
TRG=$(SRC:.cpp=)

# the final file
all: $(TRG)

# compiling the target
$(TRG): $(SRC)
	$(CC) $^ -o $@ $(LIB) $(LIB_DIR) $(INC_DIR)

# running it
run: $(TRG)
	./$^

# cleaning it
clean:
	rm -f $(TRG)