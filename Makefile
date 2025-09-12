CC = gcc
CFLAGS = -ISDL2 -Iglad
LDFLAGS = -Llib -lmingw32 -lSDL2main -lSDL2 -lopengl32

SRC = main.c glad/glad.c
OUT = main.exe

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
