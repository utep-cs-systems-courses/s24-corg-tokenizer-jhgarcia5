OBJS = uimain.o tester.o tokenizer.o history.o

CFLAGS=-g -O3

all: tokens

tokens: $(OBJS)
	cc -o tokens $(CFLAGS) $(OBJS)

tokenizer.o: tokenizer.h
history.o: history.h

clean:
	rm -f *.0 tokens

run:tokens
	./tokens
