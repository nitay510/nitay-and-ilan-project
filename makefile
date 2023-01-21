all: server client
server: server.o CanDistance.o CheDistance.o DistancesFunc.o EucDistance.o KNN.o ManDistance.o MinDistance.o func1.o func2.o func3.o func4.o func5.o HoldInfo.o SocketIO.o CLI.o
	g++ -std=c++11 -pthread -o server.out server.cpp CanDistance.cpp CheDistance.cpp DistancesFunc.cpp EucDistance.cpp KNN.cpp ManDistance.cpp MinDistance.cpp CLI.cpp SocketIO.cpp func1.cpp func2.cpp func3.cpp func4.cpp func5.cpp HoldInfo.cpp
client: client.o DistancesFunc.o
	g++ -o client.out client.cpp DistancesFunc.cpp

clean:
	@rm -f *.o *.out *.d
