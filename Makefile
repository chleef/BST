# Makefile for P1 - MTFList - Clyde leef


CC = g++
CFLAGS = -Wall -g
SRCS = main.cc


#SRCS = ${wildcard *.cc}
OBJS = ${SRCS:.cc=.o}
#INCLS = ${wildcard *.h}
INCLS = ${SRCS:.cc=.h} main.h BST.h

p2: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o p2

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cc

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) HONOR Makefile Makefile.dep

clean:
	rm -f $(OBJS) p2 core

include Makefile.dep
