export prefix=~

all:
	$(MAKE) -C src 
	$(MAKE) -c include
install:
	$(MAKE) -C src install
	$(MAKE) -C include install
uninstall:
	$(MAKE) -C src uninstall
	$(MAKE) -C include uninstall
clean:
	$(MAKE) -C src clean
	$(MAKE) -C include clean
