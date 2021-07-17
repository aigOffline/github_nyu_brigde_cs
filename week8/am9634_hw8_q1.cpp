
#include <iostream>
using namespace std;
//14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6
//PART 1!
/*
 int minInArray(int arr[], int arrSize);
 
 int main(){
 int arrSize = 20;
 int arr[arrSize];
 
 cout<<"Please enter 20 integers separated by a space: ";
 for(int i = 0; i < arrSize; i++){
 cin>>arr[i];
 }
 cout<<"The minimum value is: "<<endl;
 cout<<minInArray(arr, arrSize)<<endl;
 
 return 0;
 }
 
 
 int minInArray(int arr[], int arrSize)
 {
 int min = arr[0];
 for(int i = 0; i < arrSize; i++){
 if(min > arr[i]){
 min = arr[i];
 }
 }
 return min;
 }
 */
//Part 2!


int minInArray(int arr[], int arrSize);
void minIndex(int arr[], int num);
int main(){
    int arrSize = 20;
    int arr[arrSize];
    
    cout<<"Please enter 20 integers separated by a space: ";
    for(int i = 0; i < arrSize; i++){
        cin>>arr[i];
    }
    
    minIndex(arr, arrSize);
    
    return 0;
}
int minInArray(int arr[], int arrSize)
{
    int min = arr[0];
    for(int i = 0; i < arrSize; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    
    return min;
}
void minIndex(int arr[], int num){
    int min = arr[0];
    min = minInArray(arr, num);
    cout<<"The minimum value is "<<min<<" and it is located in the following indices: ";
    for(int i = 0; i < num; i++){
        if(arr[i] == min)
            cout<<i<<" ";
    }
    cout<<endl;
}

