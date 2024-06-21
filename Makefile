FLAGS=-std=c++20 -pthread
all: clean evenodd/bin joindetach/bin

evenodd/bin:
	$(CC) evenodd/bin.cc -o evenodd/bin $(FLAGS)

joindetach/bin:
	$(CC) joindetach/bin.cc -o joindetach/bin $(FLAGS)

clean:
	rm -rf **/bin

