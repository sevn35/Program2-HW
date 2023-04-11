employee.exe: employee_file_io.o 
	g++ employee_file_io.o -o employee.exe
#for each .0 file, give instructions how to create the .o file
#For Each.ofile, the dependencies include all the header files includen in the corresponding cpp file
#When you modify the header file or .cpp file, you need to recompile
#g++ line must have - c option and only one .cpp file and no other
#you never copile .h because it does not have the body of the functions
employee_file_io.o: employee.h employee_file_io.cpp	
	g++ -c -g employee_file_io.cpp

#clean is special argument for the make program
# used for rebuilding the executable file
# delete all.o and the executable
#Windows, del command
#Mac OS/Linus, rm
# *.o: wildcard character (*)

clean:
	del *.o  
	del employee.exe
	