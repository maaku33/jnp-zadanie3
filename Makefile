CXX=g++
CXXFLAGS=-Wall -Wextra -O2 -std=c++17
RM=rm -f

SRCS=sejf.cc
OBJS=sejf.o

all: test

test: $(OBJS) sejf_test1.o
	$(CXX) $(OBJS) sejf_test1.o -o sejf_test1

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o