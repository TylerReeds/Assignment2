#include <iostream>
#include <vector>
#include <Windows.h>

//Function to generate and play the sound for the swaps 
void playSwapSound() {
    Beep(400, 400); //Creates a Beep at 400HZ for a duration of 400 ms. 
}

//Function to merge the divided lists together 
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
        //Calls function to play the swap sound 
        playSwapSound();
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

//Function for the actual merge sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;

    std::cout << "Splitting: ";
    for (int i = left; i <= right; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);

    std::cout << "Merging: ";
    for (int i = left; i <= right; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
//Function to print the array 
void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
//Main Function
int main() {
    //Asks for the user to input the number of elements they want to use
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    //Asks for the user to input the elements 
    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    //Prints out the Original Array
    std::cout << "Original array: ";
    printArray(arr);

    //Calls mergesort function to start sorting the array 
    mergeSort(arr, 0, arr.size() - 1);

    //Prints out the Sorted Array
    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

