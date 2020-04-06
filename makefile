# macro tells which compiler to use
CC = g++

# macro says using c++11 standard
CFLAGS = -std=c++11 -c

# run "make all" to run both mergesort and insertsort
all: insertsort mergesort

# make the merge sort program
merge: mergesort.o
	$(CC) mergesort.o -o merge

mergesort.o:
	$(CC) $(CFLAGS) mergeTime.cpp

# make the insert sort program
insert: insertsort.o
	$(CC) insertsort.o -o insert

insertsort.o:
	$(CC) $(CFLAGS) insertTime.cpp


clean:
	rm *.o
	rm -f merge.out
	rm -f insert.out
	rm mergesort
	rm insertsort
