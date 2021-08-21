all: main.o libb.a
	gcc main.o -L. -lb

main.o: main.c 
	gcc main.c -c

libb.a: b.c a.c
	gcc b.c -c
	gcc a.c -c
	ar -cr libb.a b.o a.o

clean:
	rm -fr *.o *.a *.so a.out