c.out: client.o c_foo.o
	gcc -o c.out client.o c_foo.o

client.o: client.c c_foo.h
	gcc -c client.c

c_foo.o: c_foo.c c_foo.h
	gcc -c c_foo.c

run: c.out
	./c.out

clean:
	rm c_foo.o client.o c.out
