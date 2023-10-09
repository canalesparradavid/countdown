.SILENT:

all: clean create_dirs clock
	gcc ./src/countdown.c ./bin/clock.o -o ./bin/countdown.exe


clock: ./src/clock.h ./src/clock.c
	gcc ./src/clock.c -c -o ./bin/clock.o

build: all bin/countdown.exe
	cp bin/countdown.exe countdown.exe

create_dirs:
	mkdir -p bin

clean:
	rm -rf "./bin"
