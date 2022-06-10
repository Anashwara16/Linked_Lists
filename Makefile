
# Name: Anashwara Rajinkumar Puthlat
# USC NetID: puthlat
# USC ID: 2138-2056-39
# CSCI 455 Extra Credit Assgt.
# Fall 2021


# Makefile for CS 455 extra credit assgt Fall 2021
#
#
#     make ectest
#        Makes ectest executable
#


CXXFLAGS = -ggdb -Wall -std=c++11
OBJS = ecListFuncs.o ectest.o


ectest: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ectest; ./ectest

$(OBJS): ecListFuncs.h 