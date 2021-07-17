
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    
    string str;
    
    cout<<"Please enter any word to check for palindrome: ";
    cin>>str;
    

    isPalindrome(str);
    
    return 0;
}

bool isPalindrome(string str) {
    

    bool flag = false;

    long wordLength = str.length();
    
    for (int i = 0; i < wordLength; i++) {
        if(str[i] == str[wordLength - i - 1]) {

            flag = true;
        }
        else {
            
            flag = false;
            break;
        }
    }
    
  
    
    if (flag == false) {
        cout<<str<<" is not a palindrome \n";
    } else {
        cout<<str<<" is a palindrome \n";
    }
    
    
    return flag;
}
