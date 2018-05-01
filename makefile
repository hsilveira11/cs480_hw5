hw05: main.o Customer.o Movie.o
	g++ -Wall -o hw05 main.o Customer.o Movie.o
	./hw05
main.o: main.cpp Movie.hpp Customer.hpp
	g++ -Wall -c main.cpp
Customer.o: Customer.cpp
	g++ -Wall -c Customer.cpp
Movie.o: Movie.cpp
	g++ -Wall -c Movie.cpp
clean:
	rm -f *.o core hw05
