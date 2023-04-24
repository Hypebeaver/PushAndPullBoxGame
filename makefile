CC = gcc
CFLAGS = -Wall -pedantic -Werror -ansi
OBJ = box.o check.o color.o map.o move.o randomBox.o terminal.o
EXEC = box

ifdef PULL
CFLAGS += -D PULL
PULL : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

check.o : check.c check.h macro.h
	$(CC) $(CFLAGS) -c check.c

color.o : color.c color.h
	$(CC) $(CFLAGS) -c color.c

map.o : map.c map.h color.h
	$(CC) $(CFLAGS) -c map.c

move.o : move.c move.h
	$(CC) $(CFLAGS) -c move.c

randomBox.o : randomBox.c randomBox.h macro.h
	$(CC) $(CFLAGS) -c randomBox.c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

box.o : box.c check.h map.h randomBox.h terminal.h move.h macro.h
	$(CC) $(CFLAGS) -c box.c

clean :
	rm -f $(EXEC) $(OBJ)
