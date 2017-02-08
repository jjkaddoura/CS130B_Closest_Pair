CXX=g++ -std=c++11 
#clang++

BINARIES=closestPair randData

all: ${BINARIES}

closestPair: closestPair.o 
	${CXX} $^ -o $@ 

randData: randData.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o *~
