.PHONY: all clean

COMPILE=

CC=$(COMPILE)gcc

TARGET=demo

CFLAGS=-I. -I3rd_party/log4c/include \
	   -g3 -std=c11

LDFLAGS=-L. -L3rd_party/log4c/lib \
	    -llog4c

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
