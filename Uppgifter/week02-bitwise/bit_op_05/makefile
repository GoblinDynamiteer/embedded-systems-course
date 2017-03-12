TARGET = bitop_ex5
LIBS =
CC = gcc
CFLAGS =
SUBDIR = lib
SRC = $(wildcard *.c) $(wildcard $(SUBDIR)/*.c)

all: clean compile run

compile:
	$(CC) $(SRC) -o $(TARGET) $(LIBS) $(CFLAGS)

clean:
	-rm -f *.o
	-rm -f $(TARGET).*

run:
	.\$(TARGET)
