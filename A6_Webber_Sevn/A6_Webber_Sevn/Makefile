a.exe: Savings.o Checking.o main.o BankAccount.o
	g++ Savings.o Checking.o main.o BankAccount.o -o a.exe
main.o: main.cpp Checking.h Savings.h BankAccount.o
	g++ -c main.cpp
BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp
Savings.o: Savings.cpp Savings.h
	g++ -c Savings.cpp
Checking.o: Checking.cpp Checking.h
	g++ -c Checking.cpp

clean:
	del a.exe *.o