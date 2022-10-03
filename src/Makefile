#Makefile for Project 1, Tokenizer


OBJS = uimain.o history.o tokenizer.o


CFLAGS=-g -O3

all: tokenizer history uimain

tokenizer: $(OBJS)
	cc -o uimain $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o tokenizer uimain history


run: uimain
	./uimain
