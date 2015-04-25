libdir=$(prefix)/lib

AMJMEMORY_SRC=amjMemory.c
AMJMEMORY_OBJ=$(AMJMEMORY_SRC:.c=.o)

CFLAGS=-Wall -g -fPIC
CC=gcc

build: libamjMemory.a libamjMemory.so

libamjMemory.a: $(AMJMEMORY_OBJ)
	ar rc $@ $^

libamjMemory.so: $(AMJMEMORY_OBJ)
	$(CC) -shared -Wl,-soname,$@ -o $@ $^

install: $(libdir)/libamjMemory.a $(libdir)/libamjMemory.so

$(libdir)/libamjMemory.a $(libdir)/libamjMemory.so:
	cp libamjMemory.a libamjMemory.so $(libdir)

uninstall:
	- rm -f $(libdir)/libamjMemory.a $(libdir)/libamjMemory.so

clean:
	- rm -f libamjMemory.a libamjMemory.so $(AMJMEMORY_OBJ)

