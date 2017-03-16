run: main.o functions.o hashtable.o linkedlist.o node.o tuple.o
	g++ main.o functions.o hashtable.o linkedlist.o node.o tuple.o -o run

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp functions.h
	g++ -c functions.cpp

hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c linkedlist.cpp

node.o: node.cpp node.h
	g++ -c node.cpp
	
tuple.o: tuple.cpp tuple.h
	g++ -c tuple.cpp	
	
clean:
	rm *.o run
