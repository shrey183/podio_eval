binaries=program1 program2

all: clean $(binaries)

program1: write_struct.cpp
	h5c++ -o write_struct write_struct.cpp

program2: read_struct.cpp
	h5c++ -o read_struct read_struct.cpp

clean:
	rm -f $(binaries) *.o
