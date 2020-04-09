runable: build/main.o main.cpp
	g++ -lVulkan -lGLFW build/main.o -o runable

build/main.o: main.cpp
	mkdir -p build
	g++ -c main.cpp -o build/main.o

.phony: clean
clean:
	rm -rf build runable

.phony: run
run: runable
	./runable
