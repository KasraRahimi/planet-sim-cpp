# compiler
CC=g++
CFlags=-Wall

# directories
LIB_DIR=../lib_dir/target
INC_DIR=../lib_dir/include

# files
LIB=PlanetSim
SRC=main.cpp
TRG=$(SRC:.cpp=)

# the final file
all: $(TRG)

# compiling the target
$(TRG): $(SRC)
	$(CC) $^ -o $@ -l$(LIB) -L $(LIB_DIR) -I $(INC_DIR)

# running it
run: $(TRG)
	./$^

# cleaning it
clean:
	rm -f $(TRG)