libdir=$(prefix)/lib

AMJMEMORY_SRC=amjMemory.c
AMJMEMORY_OBJ=$(AMJMEMORY_SRC:.c=.o)

CFLAGS=-Wall -g
CC=gcc $(CFLAGS)

libamjMemory.a: $(AMJMEMORY_OBJ)
	ar rc $@ $^
install:
	cp libamjMemory.a $(libdir)
uninstall:
	rm $(libdir)/libamjMemory.a
clean:
	- rm libamjMemory.a $(AMJMEMORY_OBJ)

