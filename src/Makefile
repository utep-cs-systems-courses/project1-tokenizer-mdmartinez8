#Makefile for Project 1, Tokenizer


OBJS = history.o tokenizer.o


CFLAGS=-g -O3

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): history.h 

clean:
	rm -f *.o tokenizer


run: tokenizer
	./tokenizer
