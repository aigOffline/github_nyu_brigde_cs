#include <iostream>
using namespace std;
bool isAnagram(string s, string s2){
    
    bool check = true;
    string s1 = "abcdefghijklmnopqrstuvwxyz";//s1 comparing 
    for (int i = 0; i < s1.length(); i++) { //alphabet
        int lcount = 0;
        for(int j = 0; j < s.length(); j++) { //sentence
            if ( tolower(s1[i]) == tolower(s[j]) ) //
                lcount++;
        }
        int lcount2 = 0;
        for(int j = 0; j < s2.length(); j++) { //sentence
            if ( tolower(s1[i]) == tolower(s2[j]) ) //
                lcount2++;
        }
        if (lcount != lcount2) {
            check = false;
            break;
        }
    }
    return check;
}
int main(){
    cout<<"Please enter a text: "<<endl;
    string s;
    string s2;
    getline(cin >> ws, s); //including symbols and whitespace
    getline(cin >> ws, s2);
    if (isAnagram(s, s2))
        cout << "Anagrams";
    else
        cout << "Not anagrams";
}

