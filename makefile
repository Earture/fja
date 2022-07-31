fja: fja.c
	gcc fja.c -o fja

install: fja
	sudo cp fja /usr/local/bin/fja
