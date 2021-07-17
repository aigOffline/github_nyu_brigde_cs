#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {

    int arr[] = {5, 2, 11, 7, 6, 4};

    oddsKeepEvensFlip(arr, 6);

    cout<<"Odds Keep & Evens Flip:\n";
    for (int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* tempArr;
    tempArr = new int[arrSize];
    int i, index = 0;
 
    for (i = 0; i < arrSize; i++)
        if ((arr[i] % 2 == 1))
            tempArr[index++] = arr[i];
 
    for (i = arrSize; i >= 0; i--)
        if (arr[i] % 2 == 0)
            tempArr[index++] = arr[i];

    for (i = 0; i < arrSize; i++) {
        arr[i] = tempArr[i];
    }

    delete [] tempArr;
    tempArr = arr;
}
