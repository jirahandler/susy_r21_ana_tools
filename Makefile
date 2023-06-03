# Directories
HEADER_DIR := include
SOURCE_DIR := src
OBJECT_DIR := obj
BINARY_DIR := bin

# Header files
HEADERS := $(HEADER_DIR)/sus.h $(HEADER_DIR)/tt.h

# Source files
TT_SOURCES := $(SOURCE_DIR)/tt.cpp
SUS_SOURCES := $(SOURCE_DIR)/sus.cpp
TT_ANA_SOURCES := $(SOURCE_DIR)/tt_ana.cpp
SUS_ANA_SOURCES := $(SOURCE_DIR)/sus_ana.cpp

# Object files
TT_OBJECTS := $(OBJECT_DIR)/tt.o
SUS_OBJECTS := $(OBJECT_DIR)/sus.o
TT_ANA_OBJECTS := $(OBJECT_DIR)/tt_ana.o $(TT_OBJECTS)
SUS_ANA_OBJECTS := $(OBJECT_DIR)/sus_ana.o $(SUS_OBJECTS)

# Executables
TT_ANA_EXECUTABLE := $(BINARY_DIR)/tt_ana
SUS_ANA_EXECUTABLE := $(BINARY_DIR)/sus_ana

# CERN ROOT flags and libraries
ROOT_CFLAGS := $(shell root-config --cflags)
ROOT_LIBS := $(shell root-config --libs)

# Compiler flags
CFLAGS := -Wall -Wextra -I$(HEADER_DIR) $(ROOT_CFLAGS)
LDFLAGS := $(ROOT_LIBS)

# Default target
all: $(TT_ANA_EXECUTABLE) $(SUS_ANA_EXECUTABLE)

# Rule to generate object files
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(HEADERS)
	mkdir -p $(OBJECT_DIR)
	g++ $(CFLAGS) -c -o $@ $<

# Rules to generate executables
$(TT_ANA_EXECUTABLE): $(TT_ANA_OBJECTS)
	mkdir -p $(BINARY_DIR)
	g++ $^ $(LDFLAGS) -o $@

$(SUS_ANA_EXECUTABLE): $(SUS_ANA_OBJECTS)
	mkdir -p $(BINARY_DIR)
	g++ $^ $(LDFLAGS) -o $@

.PHONY: all clean

clean:
	rm -rf $(OBJECT_DIR) $(BINARY_DIR)
