#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> min_and_max(vector<int> v){
    if(v.size() == 1){
        return {v[0], v[0]};
    }
    else if(v.size()== 2){
        if(v[0] > v[1])
            return{v[0],v[1]};
        else
            return {v[1], v[0]};
    }
    else {
        const vector<int> left(&v[0], &v[v.size() /2]);
        const vector<int> right(&v[v.size() / 2], &v[v.size()]);
        vector<int> l = min_and_max(left);
        vector<int> r = min_and_max(right);
        int max = l[0] > r[0] ? l[0] : r[0];
        int min = l[1] < r[1] ? l[1] : r[1];
        return {max, min};
        
    }
}
int main(){
    int arr[7] = {1,45,-1,4,6,50,10};
    
    vector<int> v;
    for(int i = 0; i < 7; i++)
        v.push_back(arr[i]);
    int min = min_and_max(v)[1];
    int max = min_and_max(v)[0];

    cout << "Max = "<< max << " " << "Min = "<< min << endl;
    
}




