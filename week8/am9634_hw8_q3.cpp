
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
    
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    
    return 0;
}

void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize){
    for(int i = 0; i <arrSize/2; i++){
        int temp = arr[i];
        arr[i] = arr[arrSize - i - 1];
        arr[arrSize - i - 1] = temp;
    }
}

void removeOdd(int arr[], int& arrSize){
    int i = 0;
    while(i < arrSize){
        if(arr[i] % 2 != 0){
            for(int j = i; j < arrSize - 1; j++ )
                arr[j] = arr[j+1];
                arrSize--;
            
        }else
            i++;
    }
}

 void splitParity(int arr[], int arrSize){

   for(int i = 0; i < arrSize; i++)
     if(arr[i] % 2 == 0){
       int j = i + 1;
       while(j < arrSize && arr[j] % 2 == 0)
         j++;
       if (j == arrSize) break;
       else {
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
       }
     }

 }


