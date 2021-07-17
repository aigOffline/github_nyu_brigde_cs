
#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize)
{
    if( arrSize < 1 )
        return 0;
    else
        return sumOfSquares(arr, arrSize - 1) + arr[arrSize-1] * arr[arrSize-1];
}

bool isSorted(int arr[], int arrSize)
{
    if (arrSize == 0 || arrSize == 1){
        return true;
    }
    else {
        if(arr[arrSize - 1] < arr[arrSize - 2])
            return false;
        else
            return isSorted(arr, arrSize - 1);
    }
}


int main(){
    cout <<"Part A: " << endl;
    
    int arr[] = {2, -1, 3, 10};
    
    cout << "The sum is " << sumOfSquares(arr, 4);
    cout << endl;
    
    
    cout <<"Part B: "<<endl;
    
    int arr1[] = {1, 2, 1, 4, 5};
    
    if(isSorted(arr1, 5)){
        cout << "True" << endl;
    }
    else
        cout << "False" <<endl;
    
    return 0;
}

