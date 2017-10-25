// Sorting Algorithm Implementations 

//                          Best            Avg             Worst             Worst
//Selection Sort --- SPACE: Ω(n^2)      	Θ(n^2)	        O(n^2)       |	  TIME:  O(1)
//Insertion Sort --- SPACE:	Ω(n)	        Θ(n^2)	        O(n^2)	     |    TIME:  O(1)
//Bubble Sort	 --- SPACE: Ω(n)	        Θ(n^2)      	O(n^2)       |    TIME:  O(1)
//Heapsort       --- SPACE: Ω(n log(n))	    Θ(n log(n)) 	O(n log(n))	 |    TIME:  O(1)
//Mergesort	     --- SPACE: Ω(n log(n))	    Θ(n log(n)) 	O(n log(n))	 |    TIME:  O(n)
//Quicksort	     --- SPACE: Ω(n log(n)) 	Θ(n log(n)) 	O(n^2)       |    TIME:  O(log(n))

//Prints an array

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}


//Selection Sort
void SelectionSort(vector<int> &unsortedArr){
    int n = unsortedArr.size();
    int minIndex = 0;
    int temp = 0;
    for (int i = 0; i < n; i++){
        minIndex = i;
        for (int j = i+1; j < n; j++){
            if (unsortedArr[j] < unsortedArr[minIndex]){
                minIndex = j;
            }
        }
        //Swap the first unsorted value and the minIndex value
        temp = unsortedArr[i];
        unsortedArr[i] = unsortedArr[minIndex];
        unsortedArr[minIndex] = temp;
    }
}

//Insertion Sort
void InsertionSort(vector<int> &unsortedArr){
    int n = unsortedArr.size();
    int i,j = 0;
    int temp = 0;
    for (i = 0; i < n; i++){
        j=i;
        while(j > 0 && unsortedArr[j] < unsortedArr[j-1]){
            temp = unsortedArr[j];
            unsortedArr[j] = unsortedArr[j-1];
            unsortedArr[j-1] = temp;
            j--;
        }
    }
}

//Bubble Sort
void BubbleSort(vector<int> &unsortedArr){
    int n = unsortedArr.size();
    int i,j = 0;
    int temp = 0;
    for (i = 0; i < n; i++){
        
    }

}


int main()
{
    vector<int> arr {64, 25, 12, 22, 11, 34, 51, 79};
    vector<int> arr1 {64, 25, 12, 22, 11, 34, 51, 79};
    vector<int> arr2 {64, 25, 12, 22, 11, 34, 51, 79};
    vector<int> arr3 {64, 25, 12, 22, 11, 34, 51, 79};
    vector<int> arr4 {64, 25, 12, 22, 11, 34, 51, 79};
    vector<int> arr5 {64, 25, 12, 22, 11, 34, 51, 79};
    //Selection Sort
    SelectionSort(arr);
    printf("Selection Sorted array: \n");
    printArray(arr);
    //Insertion Sort 
    InsertionSort(arr1);
    printf("Insertion Sorted array: \n");
    printArray(arr1);
    //Bubble Sort
    return 0;
}




