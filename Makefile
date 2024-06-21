FLAGS=-std=c++20 -pthread
all: clean evenodd/bin
		
evenodd/bin:
	$(CC) evenodd/bin.cc -o evenodd/bin $(FLAGS)

clean:
	rm -rf **/bin

