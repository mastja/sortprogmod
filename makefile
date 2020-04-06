# macro tells which compiler to use
CC = g++

# macro says using c++11 standard
CFLAGS = -std=c++11 -c

# run "make all" to run both mergesort and insertsort
all: insert mergeTime

# make the merge sort program
merge: mergeTime.o
	$(CC) $(CFLAGS) mergeTime.cpp

# make the insert sort program
insert: insertTime.o
	$(CC) $(CFLAGS) insertTime.cpp


clean:
	rm *.o
	rm -f merge.out
	rm -f insert.out
	rm mergesort
	rm insertsort
