all:
	@echo "Please specify a target, try: make [ab | ba]"
	
ab: main.o liba.so libb.so
	gcc main.o -L. -la -lb -Wl,-rpath=.

ba: main.o liba.so libb.so
	gcc main.o -L. -lb -la -Wl,-rpath=.

main.o: main.c 
	gcc main.c -c

liba.so: a.c
	gcc -fPIC -shared a.c -o liba.so

libb.so: b.c 
	gcc -fPIC -shared b.c -o libb.so

clean:
	rm -fr *.o *.a *.so a.out