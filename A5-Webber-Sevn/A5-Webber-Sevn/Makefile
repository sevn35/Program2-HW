A.exe: main.o Executive.o Manager.o Employee.o
	g++ main.o Executive.o Manager.o Employee.o -o A.exe

Main.o: main.o Executive.h 
	g++ -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -c Executive.cpp
Manager.o: Manager.cpp Manager.h 
	g++ -c Manager.cpp

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp

clean:
	del a.exe *.o
