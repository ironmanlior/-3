CC = gcc

all: StrList

StrList: main.o StrList.a
	$(CC) -o StrList main.o StrList.a

StrList.a: StrList.o
	ar rc StrList.a StrList.o
	rm -f StrList.o

StrList.o: StrList.c StrList.h
	$(CC) -Wall -c StrList.c

main.o: main.c StrList.a
	$(CC) -Wall -c main.c

clean: 
	rm -f *.o
	rm -f *.a
	rm -f *.exe