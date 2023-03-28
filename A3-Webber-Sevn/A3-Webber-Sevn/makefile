a.exe: main.o movie_class.o
	g++ main.o movie_class.o -o a.exe

main.o: main.cpp movie_class.h
	g++ -c main.cpp

movie_class.o: movie_class.cpp movie_class.h
	g++ -c movie_class.cpp

clean:
	del a.exe *.o