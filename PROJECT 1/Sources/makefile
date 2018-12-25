# _*_ Makefile _*_

objects = allocate_memory.o free_memory.o display_memory.o write_memory.o invert_block.o write_pattern.o verify_pattern.o help.o main.o exit.o

CFLAGS = -I../Includes/

vpath %.h ../Includes/

target: $(objects)
	gcc -o target $(objects) $(CFLAGS)

main.o:main.c functions.h
	gcc -c main.c $(CFLAGS)

exit.o:exit.c functions.h exit.h
	gcc -c exit.c $(CFLAGS)

help.o:help.c functions.h help.h
	gcc -c help.c $(CFLAGS)

allocate_memory.o:allocate_memory.c functions.h allocate_memory.h
	gcc -c allocate_memory.c $(CFLAGS)

free_memory.o:free_memory.c functions.h free_memory.h
	gcc -c free_memory.c $(CFLAGS)

display_memory.o:display_memory.c functions.h display_memory.h
	gcc -c display_memory.c $(CFLAGS)

write_memory.o:write_memory.c functions.h write_memory.h
	gcc -c write_memory.c $(CFLAGS)

invert_block.o:invert_block.c functions.h invert_block.h
	gcc -c invert_block.c $(CFLAGS)

write_pattern.o:write_pattern.c functions.h write_pattern.h
	gcc -c write_pattern.c $(CFLAGS)

verify_pattern.o:verify_pattern.c functions.h verify_pattern.h
	gcc -c verify_pattern.c $(CFLAGS)

test: target testfile
	./target < testfile

clean:
	rm *.o target

