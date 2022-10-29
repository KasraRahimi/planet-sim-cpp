# compiler
CC=g++
CFlags=-Wall

# directories
SRC_DIR=./source
TRG_DIR=./target
INC_DIR=./include
BLD_DIR=./build

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
$(BLD): $(SRC)
	$(CC) -c $^ -o $@ -I $(INC_DIR) $(CFlags)

# deleting target and build
clean:
	rm -f $(TRG_DIR)/* $(BLD_DIR)/*