main: main.o Heap.o
	g++ main.o Heap.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

Heap.o: Heap.cpp Heap.h 
	g++ -c Heap.cpp

clean:
	del *.o *.exe