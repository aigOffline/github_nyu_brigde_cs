#include<iostream>
using namespace std;

/* Part 1 ~~~~~~~~~~~~~~~~~~~~~
 int minInArray(int arr[],int n);
 int main() {
 
 int num, min;
 
 //Input from the user is saved into array size
 cout<<"Please enter the array size: \n";
 cin>>num;
 int arr[num], i;
 //Input from the user is saved into elements of the array
 cout<<"Enter the elements of the array: \n";
 for(i = 0; i < num; i++) {
 cin>>arr[i];
 }
 
 //Output elements in the array back to user
 cout<<"Your array elements are: ";
 for(i = 0; i < num; i++)
 cout<<arr[i]<<" ";
 
 //Calling the minInArray() function
 min = minInArray(arr, num);
 
 //Output the minimum integer element in the array
 cout <<"\nThe minimum value in your array is: "<<min<<endl;
 
 return 0;
 }
 //minInArray function
 //Input: two parameters - 1) array 2) integer
 //Output: minimum integer in the array
 int minInArray(int arr[],int num){
 int i, min = 999999;
 //Iterate through each element of the array
 for(i = 0; i < num; i++){
 //Finding the new minimum integer value
 if(arr[i] < min)
 min = arr[i];
 }
 
 return min;
 }
 END OF PART 1
 */

int minInArray(int arr[],int num);
void minIndex(int arr[],int num);

int main() {
    
    //Fixed user input to 20 elements in an array
    int num = 20;
    int arr[num], i;
    
    //Input from the user is saved into each element in the array
    cout<<"Please enter 20 integers separated by a space:\n";
    for (i = 0; i < num; i++) {
        cin>>arr[i];
    }
    
    //Output the minimum integer element in the array & index of where the minimum value is located in the array
    minIndex(arr, num);
    
    return 0;
}
int minInArray(int arr[],int num){
    int i, min = 999999;
    //Iterate through each element of the array
    for(i = 0; i < num; i++){
        //Finding the new minimum integer value
        if(arr[i] < min)
            min = arr[i];
    }
    
    return min;
}

void minIndex(int arr[],int num) {
    
    int min;
    
    //Calling the minInArray() function
    min = minInArray(arr, num);
    
    //Output the minimum integer element in the array
    cout <<"The minimum value is "<<min<<", and it is located in the following indices: ";
    
    //Output the index of where the minimum value is located in the array
    for (int i = 0; i < num; i++) {
        if (arr[i] == min)
            cout<<i<<" ";
    }
    
    cout<<endl;
}
