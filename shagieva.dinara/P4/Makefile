out:	main.o maatrix.o
	g++ $^ -o $@
main.o: main.cpp
	g++ -c $^
matrix.o:	matrix.hpp matrix.cpp
	g++ -c $^
clean:
	rm *.o *.gch out
