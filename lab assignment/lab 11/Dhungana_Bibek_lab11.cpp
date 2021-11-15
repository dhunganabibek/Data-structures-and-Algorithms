/*
AUTHOR: Bibek Dhungana
DATE: November 30, 1997
FILENAME:Dhungana_Bibek_lab11.cpp
DESCRIPTION: The following code perform mergesort to sort the given array.
*/

#include <iostream>
using namespace std;

//function prototypes
void merge(int a[], int left, int mid, int right);
void merge_sort(int array[], int begin, int end);


int main(void){
    //creating the original array
    int a[] = {10,9,8,7,6,5,4,3,2,1};

     //finding size of the array
    int arraySize = sizeof(a)/sizeof(int);

    //printing the element before merge_sort
    cout << "The elements of the array before merge_sort:" << endl;
    for(int i = 0; i < arraySize; i++){
        cout << a[i] << " ";
    }

    cout << "\n********************************************\n";

    //calling merge_sort function
    merge_sort(a, 0, arraySize - 1);

    cout << "The elements of the array after mergersort: " << endl;
    //printing the element after merge_sort
    for(int i = 0; i < arraySize; i++){
        cout << a[i] << " ";
    }
    return 0;
}

//function for merge operation
void merge(int array[], int left, int mid, int right){
    //required variables and array creation
    int array1 = mid - left + 1;
    int array2 = right - mid;
    int* leftArray = new int[array1];
    int* rightArray = new int[array2];
    //copying the element
    for (int i = 0; i < array1; i++)
        leftArray[i] = array[left + i];
    for ( int j = 0; j < array2; j++)
        rightArray[j] = array[mid + 1 + j];
    //finding the index of arrays
    int index1 = 0; 
    int index2 = 0; 
    int indexMerged = left; 
    while (index1 < array1 && index2 < array2) {
        if (leftArray[index1] <= rightArray[index2]) {
            array[indexMerged] = leftArray[index1];
            index1 = index1 + 1;
        }
        else{
            array[indexMerged] = rightArray[index2];
            index2 = index2 + 1;
        }
        indexMerged = indexMerged + 1;
    }
    while (index1 < array1) {
        array[indexMerged] = leftArray[index1];
        index1 = index1 + 1;
        indexMerged = indexMerged + 1;
    }
    while (index2 < array2) {
        array[indexMerged] = rightArray[index2];
        index2 = index2 + 1;
        indexMerged = indexMerged + 1;
    }
}
  
//function for the merge_sort
void merge_sort(int array[], int beginIndex, int endIndex){
    if (beginIndex >= endIndex)
        return; 
    int midIndex = beginIndex + (endIndex - beginIndex) / 2;
    merge_sort(array, beginIndex, midIndex);
    merge_sort(array, midIndex + 1, endIndex);
    merge(array, beginIndex, midIndex, endIndex);
}