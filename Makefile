#installation directory prefix
ifndef prefix
	export prefix=~
endif
export prefix

build:
	$(MAKE) -C src build
	$(MAKE) -C include build
install: build
	$(MAKE) -C src install
	$(MAKE) -C include install
uninstall:
	$(MAKE) -C src uninstall
	$(MAKE) -C include uninstall
clean:
	$(MAKE) -C src clean
	$(MAKE) -C include clean
