# _*_ Makefile _*_

CC=gcc

CFLAGS = -Wall -Werror -I../inc/

vpath %.h ../inc

all: unittest
	
SRC:=circular_buffer.c main.c application.c

objects:=$(SRC:.c=.o)

unittest: $(objects)
	#$(CC) -o unittest $(objects) $(CFLAGS) -lcunit

target: $(objects)
	$(CC) -o target $(objects) $(CFLAGS)

clean:
	#rm *.o target
	rm  *.o *.xml unittest
