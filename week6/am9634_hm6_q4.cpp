#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int ACTUAL_PIN_NUM[5] = {1, 2, 3, 4, 5};

int main() {
    
    srand(time(0));
    
    string user_entered_PIN;
    
    int pinArrSize = 10;
    int pinArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout<<"PIN:\t";
    for (int i = 0; i < pinArrSize; i++) {
        cout<<pinArr[i]<<" ";
    }
    
    cout<<endl;
    
    int rand_array[10];
    
    for(int i = 0; i < 10; i++) {
        rand_array[i] = rand() % 3 + 1;
    }
    
    cout<<"NUM:\t";
    for (int i=0; i<10; i++)
        cout << rand_array[i] << " ";
    
    cout <<endl;
    
    cout<<"Enter your 5 digit passcode: \n";
    cin>>user_entered_PIN;
    

    bool is_PIN_Matched = true;
    
    for (int i = 0; i < user_entered_PIN.length(); i++) {
       
        if( (user_entered_PIN[i] - '0') != rand_array[ACTUAL_PIN_NUM[i]])
            is_PIN_Matched = false;
    }
    
    
    if (is_PIN_Matched == true)
        cout<<"Your PIN is correct"<<endl;
    else
        cout<<"Your PIN is not correct"<<endl;
    
    return 0;
}
