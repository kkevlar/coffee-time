

BOARD_TAG = nano328
BOARDS_TXT=/usr/share/arduino/hardware/arduino/boards.txt
PROJECT_DIR = .
ARDMK_DIR=../Arduino-Makefile
# all: inoup

# inoup: inobuild
# 	cd nano; ino upload -m nano

# nano/src:
# 	cd nano; ino init
# 	cd nano/src; rm -rf *

# inobuild: nano nano/src nano/src/coffee.c nano/src/coffee.h
# 	cd nano; ino clean ; ino build -m nano328

# nano/src/coffee.c: coffee.c
# 	cp coffee.c nano/src/coffee.c

# nano/src/coffee.h: coffee.h
# 	cp coffee.h nano/src/coffee.h

# nano:
# 	mkdir nano328
# 	cd nano; rm -rf *

# clean:
# 	rm -f *.o
# 	rm -rf nano

include $(ARDMK_DIR)/Arduino.mk

