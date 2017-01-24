CXX=g++ -std=c++11
#clang++

BINARIES=closestPair

all: ${BINARIES}

closestPair: closestPair.o main.o 
	${CXX} $^ -o $@ 

clean:
	/bin/rm -f ${BINARIES} *.o *~
