#Makefile for Project 1, Tokenizer


OBJS = uimain.o history.o tokenizer.o


CFLAGS=-g -O3 -Wall -Wextra

all: uimain

uimain: $(OBJS)
	cc -o uimain $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o tokenizer uimain history


run: uimain
	./uimain
