

all: ino inomake

ino:
	mkdir ino

ino/Makefile: INO-Makefile | ino
	cp INO-Makefile ino/Makefile

ino/Arduino-Makefile: | ino
	cd ino && git clone git@github.com:sudar/Arduino-Makefile.git

ino/coffee.cpp: coffee.cpp | ino
	python3 timetill9am.py | sed -r 's;(.*);cat coffee.cpp | sed -r "s:FUTURE_SECONDS:\1:" > ino/coffee.cpp;' | bash

ino/coffee.hpp: coffee.hpp | ino
	cp coffee.hpp ino

inomake: ino/Makefile ino/coffee.cpp ino/coffee.hpp  | ino ino/Arduino-Makefile 
	cd ino && make

upload: inomake
	cd ino && make upload

clean:
	rm -rf ino

