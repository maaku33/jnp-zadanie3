CXX=g++
CXXFLAGS=-Wall -Wextra -O2 -std=c++17
RM=rm -f

SRCS=sejf.cc
OBJS=sejf.o

all: test

test: $(OBJS) sejf_test1.o sejf_test2.o sejf_test3.o sejf_test4.o sejf_test5.o
	$(CXX) $(OBJS) sejf_test1.o -o sejf_test1
	$(CXX) $(OBJS) sejf_test2.o -o sejf_test2
	$(CXX) $(OBJS) sejf_test3.o -o sejf_test3
	$(CXX) $(OBJS) sejf_test4.o -o sejf_test4
	$(CXX) $(OBJS) sejf_test5.o -o sejf_test5

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) *.o
