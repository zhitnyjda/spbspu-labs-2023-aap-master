out:  main.o  Funcs.o
	g++ $^  -o $@

main.o: main.cpp
	g++ -c  $^

Funcs.o:  Funcs.cpp
	g++ -c  $^

clean:
	rm  *.o  out
