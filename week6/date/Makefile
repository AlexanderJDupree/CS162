main: date.o dateTime.o testDate.o
	g++ date.o dateTime.o testDate.o -o main

date.o: date.cpp date.h
	g++ -c date.cpp -Wall

dateTime.o: dateTime.cpp dateTime.h
	g++ -c dateTime.cpp -Wall

testDate.o: testDate.cpp
	g++ -c testDate.cpp -Wall

clean:
	rm *.o main

