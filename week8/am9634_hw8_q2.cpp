#include <iostream>
using namespace std;
bool isPalindrome(string str){
    bool check = false;
    long wordLength = str.length();
    for(int i = 0; i < wordLength; i++){
        if((str[i] == str[wordLength - i-1]) ||
           (int(str[i]) == int(str[wordLength - i-1])+32)|| (int(str[i]) == int(str[wordLength - i-1])-32)) {
            check = true;
        }else{
            check = false;
            break;
        }
    }
    if(check == false){
        cout<<str <<" is not  a Palindrome!";
    }else{
        cout<<str<< " is a Palindrome!";
    }
    return check;
}
int main(){
    cout<<"Please enter a word: ";
    string str;
    cin>>str;
    isPalindrome(str);
    cout<<endl;
    return 0;
}
