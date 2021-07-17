#include <iostream>
using namespace std;

int* findMissing(int a[], int n, int& resArrSize){
    int count = 0;
    for (int i = 0; i <= n; i++) {
        bool check = false;
        for (int j = 0; j < n; j++)
            if(a[j] == i)
            {
                check= true;
                break;
            }
        if (!check)
            count++;
    }
    int k = 0;
    resArrSize = count;
    int *p = new int[count];
    for (int i = 0; i <= n; i++) {
        bool check = false;
        for (int j = 0; j < n; j++)
            if(a[j] == i)
            {
                check= true;
                break;
            }
        if (!check) {
            p[k] = i;
            k++;
        }
    }
    return p;
}

//3 1 3 0 6 4
int main(){
    int n = 6;
    int a[n];
    cout << "Please enter 6 numbers: "<<endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int resArrSize = 0;
    int *p;
    p = findMissing( a, n, resArrSize);
    
    for(int i = 0; i < resArrSize; i++){
        cout << p[i] << " ";
    }
}

