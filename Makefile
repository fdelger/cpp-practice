#Practice makefile 
run:
	./hello
build: helloworld.o
	g++ helloworld.o -o hello
helloworld.o: helloworld.cpp
	g++ -c helloworld.cpp
clean:
	rm *.o
	rm hello

