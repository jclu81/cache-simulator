cc = g++
CFLAGS = -std=c++11 -g
memsim:cacheSimulator.cpp Cache.o Tools.o Block.h
	echo --------compiling cacheSimulator.cpp--------
	$(cc) $(CFLAGS) cacheSimulator.cpp Cache.o Tools.o Block.h -o memsim

clean:
	echo --------remove executable program--------
	/bin/rm -rf *.o *.gch memsim