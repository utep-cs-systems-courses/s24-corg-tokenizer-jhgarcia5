CFLAGS=-g -O3

all: tokenizer

history.o: history.h
tokenizer.o: tokenizer.h
uimain.o: uimain.c tokenizer.h history.h

tokenizer: history.o tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

run:
	./tokenizer

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# .0 tokenizer
