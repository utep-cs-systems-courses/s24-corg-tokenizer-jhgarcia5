CFLAGS=-g -O3

all: tokenizer

history.o: history.h
tokenizer.o: tokenizer.h

tokenizer: history.o tokenizer.o
	cc -o $@ $^ $(CFLAGS)
clean:
	rm -f *.0 tokenizer
