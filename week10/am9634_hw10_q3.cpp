
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
// 13,5
// 8
// 2
// 9
// 5
// 8
// 8
// -1
void search1(int* a, int num, int target){
    
    for (int i = 0; i < num; i++)
        if (a[i] == target)
            cout << i << " ";
    cout << endl;
    
}
void search2(vector<int> a, int num, int target){
    
    for (int i = 0; i < num; i++)
        if (a[i] == target)
            cout << i << " ";
    cout << endl;
    
}

void main1(){
    cout<<"SECTION A"<<endl;
    cout<<"Please enter numbers: ";
    int num = 0, next;
    int *a;
    int target;
    
    
    a = (int*) malloc(num);
    while(cin >> next && next != -1){
        a = (int*) realloc(a, (num+1)*sizeof(int));
        a[num] = next;
        num++;
    }
    cout << "What num are you searching?"<<endl;
    cin >> target;
    search1(a,  num, target);
    free(a);
}


void main2(){
    cout << "SECTION B"<<endl;
    vector <int> v;
    cout << "Please enter a positive numbers:"<<endl;
    int next;
    int num = 0, target;
    while(cin >> next && next != -1){
        v.push_back(next);
        num++;
    }
    cout << "What num are you searching?"<<endl;
    cin >> target;
    search2(v, num,  target);
}

int main() {
    main1();
    main2();
}
