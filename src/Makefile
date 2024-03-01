OBJS = uimain.o tester.o tokenizer.o history.o

CFLAGS=-g -03

all: tokens

tokenizer: $(OBJS)
	cc -o tokens $(CFLAGS) $(OBJS)

tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: uimain.h

clean:
	rm -f *.0 tokens

run:tokens
	./tokens
