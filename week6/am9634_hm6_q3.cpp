
#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    cout<<"\nSection A: Reversed array\n";
    printArray(arr1, arr1Size);
    cout<<"reversed is \n";
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    cout<<"\nSection B: Removed Odds\n";
    printArray(arr2, arr2Size);
    cout<<"removed odds is \n";
    removeOdd(arr2, arr2Size);
    cout<<endl;
    
    cout<<"\nSection C: Split Parity\n";
    printArray(arr3, arr3Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    
    return 0;
    
}


void reverseArray(int arr[], int arrSize) {
    int first, n;
    int last = arrSize - 1;
    
    for (first = 0; first < (arrSize - 1) / 2; first++, last--) {
        n = arr[first];
        arr[first] = arr[last];
        arr[last] = n;
    }
}
void removeOdd(int arr[], int& arrSize) {
    int newSize = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            cout<<arr[i]<<" ";
            newSize++;
        }
    }
    arrSize = newSize;
}

void splitParity(int arr[], int arrSize) {
    
    int first, n;
    int last = arrSize - 1;
    
    for (first = 0; first < (arrSize - 1) / 2; first++, last--) {
        if (arr[first] % 2 == 0) {
            n = arr[first];
            arr[first] = arr[last];
            arr[last] = n;
        }
    }
}


void printArray(int arr[], int arrSize) {
    
    int i;
    
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
