# Makefile to build client and server executables

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

LIB = ./lib/
BIN = ./bin/

# Executables
CLIENT_TARGET = $(BIN)client
SERVER_TARGET = $(BIN)server
MAIN_TARGET = main  # Main executable in current directory

# Build all targets
all: $(CLIENT_TARGET) $(SERVER_TARGET) $(MAIN_TARGET)

# Rule to build the client executable
$(CLIENT_TARGET): $(LIB)client.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule to build the server executable
$(SERVER_TARGET): $(LIB)server.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule to build the main executable in the current directory
$(MAIN_TARGET): $(LIB)main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Phony targets
.PHONY: all clean

# Clean rule
clean:
	rm -f $(CLIENT_TARGET) $(SERVER_TARGET) $(MAIN_TARGET)
