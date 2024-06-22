FLAGS= -std=c++20 -lpthread
all: clean evenodd/bin joindetach/bin mutex/bin multi/bin atomic/bin limit/bin

evenodd/bin:
	$(CC) evenodd/bin.cc -o evenodd/bin $(FLAGS)

joindetach/bin:
	$(CC) joindetach/bin.cc -o joindetach/bin $(FLAGS)

mutex/bin:
	$(CC) mutex/bin.cc -o mutex/bin $(FLAGS)	

multi/bin:
	$(CC) multi/bin.cc -o multi/bin $(FLAGS)

atomic/bin:
	$(CC) atomic/bin.cc -o atomic/bin $(FLAGS)

limit/bin:
	$(CC) limit/bin.cc -o limit/bin $(FLAGS)

clean:
	rm -rf **/bin

