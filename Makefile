FLAGS=-std=c++20 -pthread
all: clean evenodd/bin joindetach/bin mutex/bin

evenodd/bin:
	$(CC) evenodd/bin.cc -o evenodd/bin $(FLAGS)

joindetach/bin:
	$(CC) joindetach/bin.cc -o joindetach/bin $(FLAGS)

mutex/bin:
	$(CC) mutex/bin.cc -o mutex/bin $(FLAGS)	

clean:
	rm -rf **/bin

