a.exe: main.o HugeInt.o
	g++ main.o HugeInt.o -o a.exe

main.o:	HugeInt.h main.cpp
	g++ -c main.cpp

HugeInt.o: HugeInt.h HugeInt.cpp
	g++ -c HugeInt.cpp

clean:
	del *.exe *.o