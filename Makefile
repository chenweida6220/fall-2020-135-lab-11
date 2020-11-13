--std=c++11

main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o

tests.o: doctest.h profile.h network.h

main.o: main.cpp profile.h network.h

profile.o: profile.cpp profile.h

network.o: network.cpp network.h

clean:
	rm -f a.out main main.o tests tests.o profile.o network.o
