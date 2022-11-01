# compiler
CC=g++
CFlags=-Wall -I$(INC_DIR) $(EXT_INC_DIR) $(EXT_LIB_DIR) $(EXT_LIB)

# directories
SRC_DIR=./source
TRG_DIR=./target
INC_DIR=./include
BLD_DIR=./build

# external directories
EXT_LIB=-lSDL2
EXT_LIB_DIR=-L/usr/lib/x86_64-linux-gnu/
EXT_INC_DIR=-I/usr/include/SDL2

# files
SRC=$(wildcard $(SRC_DIR)/*.cpp)
BLD=$(subst $(SRC_DIR),$(BLD_DIR),$(SRC:.cpp=.o))
INC=$(wildcard $(INC_DIR)/*.h)
TRG=$(TRG_DIR)/libPlanetSim.a

# the target file
all: $(TRG)

# compiling the static library from .o files
$(TRG): $(BLD)
	ar crs $@ $^

# compiling the .o files from the .cpp files
$(BLD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $^ -o $@ $(CFlags)

# deleting target and build
clean:
	rm -f $(TRG_DIR)/* $(BLD_DIR)/*