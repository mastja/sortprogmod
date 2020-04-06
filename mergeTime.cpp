/*  Project Name : Merge Sort
    Date: 4/5/2020
    Programmer: Jacob Mast
    Description: This program runs merge sort on arrays of random numbers
    generated by the computer system.  The program records the average running time 
    of the merge sort algorithm and prints this information to the screen.
*/


#include<iostream>
#include<fstream>
#include<assert.h>
#include<limits>
#include<time.h>
#include<ctime>
#include<cstdlib>
using namespace std;

void merge_sort(int arr[], int m, int n);

void merge(int arr[], int p, int q, int r);

int main(){

    //seed the random number generator
    srand(time(NULL));

    // open output file in write mode
    ofstream outfile1("merge.out");

    // variables for keeping track of time
    clock_t t1, t2;

    // declare variable for array length
    int n = 5000;

    // repeat loop every 5,000 up to 40,000 (7x)
    while (n<=40000){

        // declare a float to keep time total
        float time = 0.00;

        // repeat loop measuring time of sort program 4 times for greater accuray
        // average results over 4 trials
        for (int j=0; j<4; j++){

            // declare array of size n+1
            int arr[n];

            // fill array with random numbers 0 to 10000
            for (int i=0; i<n; i++){
                arr[i] = rand()%10000+1;
                }

            // get clock measure before running insertion sort
            t1 = clock();

            // run insertion sort function
            merge_sort(arr, 0, n-1);

            // get clock measure after running insertion sort
            t2 = clock();

            // place difference of clock values in new float variable
            float diff ((float)t2-(float)t1);
            
            // translate clock value into seconds
            float seconds = diff/CLOCKS_PER_SEC;

            // Add time to total, will compute average of 4 trials after loop exits
            time = time + seconds;
        }

        // compute the average time over 4 trials
        float average = time/4.00;

        // print to screen the value of n and the time to run
        cout << "Array size: " << n << "\t Time to run: " << average << endl;
        
        // write values to output file
        outfile1 << n << " " << average << endl;
        
        // increment array size
        n = n + 5000;
    }

    // close the opened files
    outfile1.close();

    return 0;
}


// merge_sort function sorts an array using the merge sort alorithm

void merge_sort(int arr[], int m, int n){

    int mid;

    // if there is more than one value in the array
    if(m < n){

        // get mid index
        mid = (m + n) / 2;

        // recursive call to sort the left subarray
        merge_sort(arr, m, mid);

        // recursive call to sort the right subarray
        merge_sort(arr, mid + 1, n);

        // merge the two subarrays, function is written below
        merge(arr, m, mid, n);
    }
}

// function merges two arrays, placing values in merged array in increasing order

void merge(int arr[], int p, int q, int r) {

    // length of left subarray
    int len = q - p + 1;

    // length of right subarray
    int len2 = r - q;

    // declare counter variables
    int i, j, k;

    // create two arrays left and right
    int *left = new int[len + 2];
    int *right = new int[len2 + 2];

    // fill left with contents of left subarray of arr
    for(i = 1; i <= len; i++){
        left[i] = arr[p + i - 1];
    }

    // fill right w contents of right subarray of arr
    for(i = 1; i <= len2; i++){
        right[i] = arr[q + i];
    }

    // set last element of each array to the max int value or infinity,
    // which is our sentinel value
    left[len + 1] = std::numeric_limits<int>::max();
    right[len2 + 1] = std::numeric_limits<int>::max();

    i=1;
    j=1;

    //repeat the loop below for the length of the array (r - p + 1)

    for(k = p ; k <= r; k++){

        // if the current left is smaller than current right
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }

        // else if the current left is larger than current right
        else{
            arr[k] = right[j];
            j++;
        }
    }
}