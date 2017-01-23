CXX=g++ -std=c++11
#clang++

BINARIES=closestPair

all: ${BINARIES}

closestPair: closestPair.o 
	${CXX} $^ -o $@ 

clean:
	/bin/rm -f ${BINARIES} *.o *~
