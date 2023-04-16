CPP=g++
LD=g++

SPECIALFLAGS=-O2 
#SPECIALFLAGS=-g -O0
ROOTCFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CFLAGS = $(SPECIALFLAGS) -I.
LFLAGS = -L.
MANFLAGS = -lstdc++fs

RCXX=$(CFLAGS) $(MANFLAGS) $(ROOTCFLAGS)
RLXX=$(LFLAGS) $(ROOTLIBS)

SRC=d_ana.cpp d.cpp

%.o: %.cpp d.h 
	$(CPP) $(RCXX) -c $<

all: $(SRC:.cpp=.o)
	$(LD) $(SRC:.cpp=.o) $(RLXX) -o d_ana

clean:
	rm -f *~ *.o
	rm -f d_ana
