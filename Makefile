# A makefile for graphconnections

CC=g++
CXXFLAGS=-std=c++11
LDFLAGS= -Wall -g

all: graphconnections

graphconnections: graphconnections.o

graphconnections.o: graphconnections.cpp

clean: 
	rm -f graphconnections graphconnections.o *.o core*

cleanBackups:
	rm *~
