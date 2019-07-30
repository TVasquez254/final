output: main.o graph.o data.o
	g++ -std=c++11 main.o graph.o data.o output


data.o: data.h
	g++ -std=c++11 data.h

main.o: main.cpp
	g++ -std=c++11 main.cpp

graph.o: graph.cpp
	g++ -std=c++11 graph.cpp

clean:
	rm *.o output


