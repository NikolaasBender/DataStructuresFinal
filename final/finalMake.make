#g++ -std=c++11 -g finalLL.cpp finalLL.hpp finalSTL.cpp finalSTL.hpp finalHeap.cpp finalHeap.hpp final.cpp -o final

CC=g++
CFLAGS= -std=c++11 -g -Wall
DEPS = finalLL.hpp finalSTL.hpp finalHeap.hpp
OBJ = finalLL.o finalSTL.o finalHeap.o
CLASSES = finalLL.cpp finalSTL.cpp finalHeap.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) $(CFLAGS) $(DEPS) $(CLASSES) final.cpp -o final