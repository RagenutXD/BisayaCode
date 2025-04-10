CC=gcc
LANG=c

all: build run

.SILENT: build run

build:
	$(CC) $(wildcard src/*.$(LANG)) -Wall  -o ./out/a.exe

run:
	./out/a.exe