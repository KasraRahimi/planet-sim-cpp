# compiler
CC=g++
CFlags=-Wall

# directories
LIB_DIR=-L../lib_dir/target -L/usr/lib/x86_64-linux-gnu/
INC_DIR=-I../lib_dir/include -I/usr/include/SDL2

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