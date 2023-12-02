CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: door_struct list_test stack_test

door_struct: dmanager_module.o
	$(CC) $(CFLAGS)  dmanager_module.o -o ../build/Quest_1

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

list_test: list.o list_test.o
	$(CC) $(CFLAGS) list.o list_test.o -o ../build/Quest_2

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

list.o: list.c
	$(CC) $(CFLAGS) -c list.c -o list.o

stack_test: stack.o stack_test.o
	$(CC) $(CFLAGS) stack.o stack_test.o -o ../build/Quest_3

stack_test.o : stack_test.c
	$(CC) $(CFLAGS) -c stack_test.c -o stack_test.o

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c -o stack.o

rebuild: clean build

build: door_struct list_test stack_test

clean:
	rm -f *.o ../build/Quest_*