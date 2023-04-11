employee.exe: employee_file_io.o employee.o DeptInfo.o
	g++ employee_file_io.o employee.o DeptInfo.o -o employee.exe

employee_file_io.o: employee.h employee_file_io.cpp
	g++ -c -g employee_file_io.cpp

employee.o: employee.h employee.cpp
	g++ -c -g employee.cpp

DeptInfo.o: employee.h DeptInfo.cpp
	g++ -c -g DeptInfo.cpp

clean:
	del *.o  
	del employee.exe
	