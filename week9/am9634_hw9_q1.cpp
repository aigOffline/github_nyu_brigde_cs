#include <iostream>
using namespace std;
void countWords(string s){
    int count = 0;
    int i = 0;
    while(i < s.length() ) {
        while ( s[i] == ' ' or s[i] == '.' or s[i] == ',') //skip
            i++;
        if (i < s.length() && isalpha(s[i])) { //isalpha code for checking is alphabet or not.
            count++;
            while(i < s.length() && isalpha(s[i]))
                i++;
        }
    }
    cout << count << "\twords" << endl;
    
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s1.length(); i++) { //alphabet
        int lcount = 0;
        for(int j = 0; j < s.length(); j++) { //sentence
            if ( tolower(s1[i]) ==  tolower(s[j]) )             //
                lcount++;
        }
        if (lcount > 0) {
            cout << lcount << "\t" << s1[i] << endl;
        }
    }
}
int main(){
    cout<<"Please enter a line of text: "<<endl;
    string s;
    getline(cin >> ws, s);
    
    countWords(s);
    return 0;
    
}

