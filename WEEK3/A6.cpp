#include <iostream>
#include <cstdlib>
#include <ctime>

void makeArray(int arr[], int size) {
    //srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 100;
    }
}

void merge(int arr1[], int arr2[], int size, int arr[]) {
    for (int i = 0; i < size*2; i=i+2) {
        arr[i] = arr1[i/2];
        arr[i+1] = arr2[i/2];
    }
}

int main(){
    srand(time(0));

    int arr1[5];
    int arr2[5];
    makeArray(arr1, 5);
    makeArray(arr2, 5);
    int arr3[10];
    merge(arr1, arr2, 5, arr3);


    std::cout << "Array 1: ";
    for (auto a1_num : arr1) {
        std::cout << a1_num << "   ";
    }
    std::cout << std::endl << "Array 2: ";
    for (auto a2_num : arr2) {
        std::cout << a2_num << "   ";
    }
    std::cout << std::endl << "Merged Array: ";
    for (auto a3_num : arr3) {
        std::cout << a3_num << "   ";
    }

    return 0;
}