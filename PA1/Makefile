cipher: main.o block.o stream.o utility.o
	g++ main.o block.o stream.o utility.o -o cipher

main.o: main.cpp
	g++ -c main.cpp

block.o: block.cpp block.h
	g++ -c block.cpp

stream.o: stream.cpp stream.h
	g++ -c stream.cpp

utility.o: utility.cpp utility.h
	g++ -c utility.cpp

clean:
	rm *.o cipher
