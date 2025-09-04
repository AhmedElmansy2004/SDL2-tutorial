CC = gcc
CFLAGS = -Iinclude
LDFLAGS = -Llib -lmingw32 -lSDL2main -lSDL2

SRC = main.c
OUT = main.exe

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

run: all
	./$(OUT)

clean:
	del $(OUT)
