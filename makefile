all: server client
server: server.o CanDistance.o CheDistance.o DistancesFunc.o EucDistance.o KNN.o ManDistance.o MinDistance.o
	g++ -o server.out server.cpp CanDistance.cpp CheDistance.cpp DistancesFunc.cpp EucDistance.cpp KNN.cpp ManDistance.cpp MinDistance.cpp
client: client.o DistancesFunc.o
	g++ -o client.out client.cpp DistancesFunc.cpp

clean:
	@rm -f *.o *.out *.d
