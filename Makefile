

all: ino inomake

ino:
	mkdir ino

ino/Makefile: | ino
	cp INO-Makefile ino/Makefile

ino/Arduino-Makefile: | ino
	cd ino && git clone git@github.com:sudar/Arduino-Makefile.git

ino/coffee.c: coffee.c | ino
	cp coffee.c ino

ino/coffee.h: coffee.h | ino
	cp coffee.h ino

inomake: ino/Makefile ino/coffee.c ino/coffee.h  | ino ino/Arduino-Makefile 
	cd ino && make

upload: inomake
	cd ino && make upload

clean:
	rm -rf ino

