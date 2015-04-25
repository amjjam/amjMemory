includedir=$(prefix)/include

build: 

install: $(includedir)/amjMemory.h

$(includedir)/amjMemory.h: amjMemory.h
	cp amjMemory.h $(includedir)

uninstall:
	- rm -f $(includedir)/amjMemory.h

clean:
