# Compiler and linker flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -MMD -MP -DNDEBUG -D_FORTIFY_SOURCE=2 -O2 -isystem $(shell root-config --cflags) -Wno-unused-variable -Wno-unused-function
LDFLAGS = $(shell root-config --libs)

# Source files and object files
SRC = event.cpp event_generator.cpp inputfile.cpp
HEADER = event_generator.h inputfile.h track.h variables.h
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

# Directories
EXEC_DIR = executables
$(shell mkdir -p $(EXEC_DIR))

# Read variables from inputfile.cpp
LAMDAMASS = $(shell grep -oP 'lambdamass\s*=\s*\K[0-9\.]+' inputfile.cpp)
N = $(shell grep -oP 'N\s*=\s*\K[0-9]+' inputfile.cpp)
PTMIN = $(shell grep -oP 'ptmin\s*=\s*\K[0-9\.]+' inputfile.cpp)
PTMAX = $(shell grep -oP 'ptmax\s*=\s*\K[0-9\.]+' inputfile.cpp)
ETAMIN = $(shell grep -oP 'etamin\s*=\s*\K[0-9\.-]+' inputfile.cpp)
ETAMAX = $(shell grep -oP 'etamax\s*=\s*\K[0-9\.-]+' inputfile.cpp)

# Generate the executable name dynamically
EXEC_NAME = Lambda_${LAMDAMASS}_N-O-E_${N}_etamin_${ETAMIN}_etamax_${ETAMAX}_ptmin_${PTMIN}_ptmax_${PTMAX}
EXEC_PATH = $(EXEC_DIR)/$(EXEC_NAME)

# Default target
all: run_simulations

# Rule to run simulations
run_simulations: $(EXEC_PATH)
	@./$(EXEC_PATH)

# Rule to generate the simulation executable
$(EXEC_PATH): inputfile.cpp $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(EXEC_PATH)

# Rule for compiling .cpp to .o
%.o: %.cpp $(HEADER)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEP)

# Clean
clean:
	@echo "Cleaning up..."
	rm -f $(OBJ) $(DEP)
	rm -rf $(EXEC_DIR)

.PHONY: all clean run_simulations

