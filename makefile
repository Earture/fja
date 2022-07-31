fja: 
	gcc fja.c -o fja

install: fja
	sudo cp vja /usr/local/bin/fja
