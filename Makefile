CXX=g++
CXXFLAGS=-Wall -Wextra -O2 -std=c++17
RM=rm -f

SRCS=sejf.cc
OBJS=$(subst .cc,.o,$(SRCS))
  
%.o: %.cc %.h
    $(CXX) $(CXXFLAGS) -c $<

clean:
  $(RM) $(OBJS)
