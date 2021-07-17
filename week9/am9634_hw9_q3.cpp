#include <iostream>
#include <cmath>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0)
            outPosArrSize++;
    int* a = new int[outPosArrSize];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0) {
            a[j] = arr[i];
            j++;
        }
    return a;
}
void getPosNums2(int* arr, int arrSize,
                 int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0)
            outPosArrSize++;
    outPosArr = new int[outPosArrSize];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0) {
            outPosArr[j] = arr[i];
            j++;
        }
    
}
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0)
            (*outPosArrSizePtr)++;
    int* a = new int[*outPosArrSizePtr];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0) {
            a[j] = arr[i];
            j++;
        }
    return a;
}
void getPosNums4(int* arr, int arrSize,
                 int** outPosArrPtr, int* outPosArrSizePtr)
{
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0)
            (*outPosArrSizePtr)++;
    *outPosArrPtr = new int[*outPosArrSizePtr];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > 0) {
            (*outPosArrPtr)[j] =  arr[i];
            j++;
        }
}

int main(void) {
    int arr[] = {3, -1, -3, 0, 6, 4};
    int n = 6;
    int m = 6;
    int* a;
    cout << "1st Array" << endl;
    a = getPosNums1(arr, n, m);
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";
    cout << endl;
    
    cout << "2nd Array" << endl;
    int* b;
    getPosNums2(arr, n, b, m);
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
    cout << endl;
    
    cout << "3rd Array" << endl;
    int* c;
    c=getPosNums3(arr, n, &m);
    for (int i = 0; i < m; i++)
        cout << c[i] << " ";
    cout << endl;
    
    cout << "4th Array" << endl;
    int* d;
    getPosNums4(arr, n, &d, &m);
    for (int i = 0; i < m; i++)
        cout << d[i] << " ";
    cout << endl;
    return 0;
}

