OBJS = main.o fraction.o

main: $(OBJS)
	g++ $(OBJS) -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

fraction: fraction.h fraction.cpp
	g++ -c fraction.cpp -o fraction.o

clean:
	rm ./*.o main
