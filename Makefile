CC=gcc
CFLAGS=-I/usr/include/python3.2mu/ -L/usr/lib/python3.2/config-3.2mu/ -lpthread -ldl -lutil -lm -lpython3.2mu

atoimake: src/libAtoiModule.o 
	$(CC) -DNDEBUG -g -fPIC -Wall -c src/libAtoiModule.c $(CFLAGS)
	$(CC) -shared libAtoiModule.o -L/usr/local/lib -o libAtoiModule.so --debug=frames

clean:
	rm -rf *.o *.c.* *.so src/*.o src/*.so
