OBJS = main.o fraction.o elimination.o

main: $(OBJS)
	g++ $(OBJS) -o main -g

main.o: mattersbyHerminos.cpp
	g++ -c mattersbyGZX.cpp -o main.o

fraction: fraction.h fraction.cpp
	g++ -c fraction.cpp -o fraction.o

elimination: elimination.h elimination.cpp
	g++ -c elimination.cpp -o elimination.o

clean:
	rm ./*.o main
