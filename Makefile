
output: main.o matrici.o
	g++ main.cpp matrici.cpp -o output

main.o: main.cpp
	g++ -c main.cpp

matrici.o: matrici.cpp matrici.h
	g++ -c matrici.cpp

clean:
	rm *.o output
