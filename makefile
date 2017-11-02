
stackdb: stack.c stackdbio.c main.c
	gcc -g -o stackdb stack.c stackdbio.c main.c -I.

clean:
	rm -rf *.o stackdb
