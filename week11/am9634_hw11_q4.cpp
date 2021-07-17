
#include <iostream>
using namespace std;

int jumpIn(int *arr, int i, int n) {
    if (i < n - 2) {
        if (arr[i + 1] < arr[i + 2] )
            return arr[i] + jumpIn(arr, i + 1, n);
        else
            return arr[i] + jumpIn(arr, i + 2, n);
    }
    else {
        if (i == n - 1)
            return arr[i];
        else
            return arr[i] + arr[i + 1];
    }
}

int main() {
    int arr[] = {0, 3, 80, 6, 57, 10};
    
    cout << jumpIn(arr, 0, 6) << endl;
    return 0;
}

