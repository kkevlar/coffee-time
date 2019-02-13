

all: ino inomake

ino:
	mkdir ino

ino/Makefile: INO-Makefile | ino
	cp INO-Makefile ino/Makefile

ino/Arduino-Makefile: | ino
	cd ino && git clone git@github.com:sudar/Arduino-Makefile.git

ino/coffee.cpp: coffee.cpp | ino
	cp coffee.cpp ino


inomake: ino/Makefile ino/coffee.cpp  | ino ino/Arduino-Makefile 
	cd ino && make

upload: inomake
	cd ino && make upload

clean:
	rm -rf ino

