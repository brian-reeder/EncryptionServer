s.out: server.o s_foo.o
	gcc -o s.out server.o s_foo.o

server.o: server.c s_foo.h
	gcc -c server.c

s_foo.o: s_foo.c s_foo.h
	gcc -c s_foo.c

run: 
	./s.out

clean:
	rm server.o s_foo.o s.out
