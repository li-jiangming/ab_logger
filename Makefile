.PHONY: all clean

CROSS_COMPILE=
CC=$(CROSS_COMPILE)gcc
CXX=$(CROSS_COMPILE)g++
AR=$(CROSS_COMPILE)ar

TARGET=libab_logger.so

CFLAGS=-I. \
	-I3rd_party/log4c-1.2.4/include \
	-g3 -fPIC -std=gnu11

LDFLAGS=-L. \
	-L3rd_party/log4c-1.2.4/lib \
	-llog4c

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -shared -o $@ $(LDFLAGS)

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
