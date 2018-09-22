HEADERS=Board.hpp AStar.hpp
CPP=Board.cpp AStar.cpp

default:
	g++ Source.cpp ${HEADERS} ${CPP} -o Project1 -std=c++11

release:
	rm -rf Project1
