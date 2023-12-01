out:	main.o readMatrix.o findMaxColumn.o
	g++ $^ -o $@
main.o:	main.cpp
	g++ -c $^
readMatrix.o:	readMatrix.cpp readMatrix.hpp
	g++ -c $^
findMaxColumn.o:	findMaxColumn.cpp findMaxColumn.hpp
	g++ -c $^
clean:
	rm *.o *.gch out
