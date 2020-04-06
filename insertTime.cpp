/*  Project Name : Insertion Sort
    Date: 4/5/2020
    Programmer: Jacob Mast
    Description: This program runs insertion sort on arrays of random numbers
    generated by the computer system.  The program records the average running time 
    of the insert sort algorithm and prints this information to the screen.
*/


#include<iostream>
#include<fstream>
#include<assert.h>
#include<time.h>
#include<ctime>
using namespace std;

void insertion_sort(int arr[], int n);

int main(){

    //seed the random number generator
    srand(time(NULL));

    // open output file in write mode
    ofstream outfile1("insert.out");

    //steps for insertion sort
    // create variable for array length
    int len;

    // variables for keeping track of time
    clock_t t1, t2;

    // declare variable for array length
    int n=5000;

    // repeat loop every 5,000 up to 40,000 (7x)
    while (n<=40000){

        // declare a float to keep time total
        float time = 0;

        // repeat loop measuring time of sort program 5 times for greater accuray
        // average results over 4 trials
        for (int j=0; j<4; j++){

            // declare array of size n
            int arr[n];

            // fill array with random numbers 0 to 10000
            for (int i=0; i<n; i++){
                arr[i] = rand()%10000+1;
                }

            // get clock measure before running insertion sort
            t1=clock();

            // run insertion sort function
            insertion_sort(arr, n);

            // get clock measure after running insertion sort
            t2=clock();

            // place difference of clock values in new float variable
            float diff ((float)t2-(float)t1);
            
            // translate clock value into seconds
            float seconds = diff/CLOCKS_PER_SEC;

            // Add time to total, will compute average of 4 trials after loop exits
            time = time + seconds;
        }

        // compute the average time over 4 trials
        float average = time/4;

        // print to screen the value of n and the time to run
        cout << "Array size: " << n << "\t Time to run: " << average << endl;
        
        // write values to output file
        outfile1 << n << " " << average << endl;
        
        // increment array size
        n = n + 5000;


    }

    // close the opened file
    outfile1.close();

    return 0;

}


/* insertion sort function
    program takes an array of unsorted positive integers and sorts into increasing order
    first value in the passed array is the length of the list of integers to be sorted
*/

void insertion_sort(int arr[], int n){

    // declare local variables
    int i, j, key;

    // counter from 1 to integer list length
    for (i = 1; i < n; i++){
        
        // place current in key
        key = arr[i]; 

        // index spot of previous value
        j = i - 1;

        // compare the key to the value indexed at previous spot, if key is less than, continue while loop
        // while loop exits when key is greater than or equal to value indexed at previous spot
        while (j > 0 && arr[j] > key){

            // since the key is less than the value at index j, j is moved to index spot of j+1
            arr[j+1] = arr[j];

            // j is decremented so that we can compare the key to the previous spot
            j--;

            //function moves back up to test the conditionals in the while statement line
        }

        // while loop has exited, key is greater than or equal to value at index j
        // key is placed at index j + 1.
        arr[j + 1] = key;

    }

}