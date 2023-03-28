a.exe: main.o DB.o Node.o Employee.o
	g++ main.o DB.o Node.o Employee.o -o a.exe

main.o: main.cpp DB.h Node.h Employee.h
	g++ -g -c main.cpp

DB.o: DB.cpp DB.h Node.h Employee.h
	g++ -g -c DB.cpp

Node.o: Node.cpp Node.h Employee.h
	g++ -g -c Node.cpp

Employee.o: Employee.cpp Employee.h
	g++ -g -c Employee.cpp

clean: 
	del *.o sll

