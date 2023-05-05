main: main.o 
	g++ main.o -o main

main.o: main.cpp BinaryNode.h BinarySearchTree.h BinaryTree.h enum.h
	g++ -c -g main.cpp

clean:
	del *.o *.exe