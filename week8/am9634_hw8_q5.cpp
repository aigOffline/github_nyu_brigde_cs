
#include <iostream>
using namespace std;


int main() {
    
    string first_name, middle_name, last_name;
    string middle_initial;
    string full_name;
    
    cout<<"Please enter your full name (i.e. Mary Average User):\n";
    cin>>first_name>>middle_name>>last_name;
    
    middle_initial = middle_name.substr(0, 1) + ".";
    
    if (middle_name == middle_initial)
        full_name = last_name + ", " + first_name + " " + middle_name;
    else
        full_name = last_name + ", " + first_name + " " + middle_initial;
    
    cout<<full_name<<endl;
    
    return 0;
}

