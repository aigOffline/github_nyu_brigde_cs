#include <iostream>
using namespace std;
//My userID is john17 and my 4 digit pin is 1234 which is secret
bool all_digits(string str) {
    for (int i = 0; i < str.length(); i++)
        if ( !(str[i] >= '0' && str[i] <= '9') )
            return false;
    return true;
}
int main(){
    string sentence;
    cout<<"Please enter a line of text:";
    getline(cin >> ws, sentence );
    int i = 0;
    int word_begin = 0;
    int size = sentence.length();
    while (i < size) {
        while (sentence[i] == ' ') {
            i++;
        }
        string s = "";
        if (i < size ) {
            word_begin = i;
            while (i < size && sentence[i] != ' ') {
                s += sentence[i];
                i++;
            }
        }
        if ( all_digits(s) )
            for(int j = word_begin; j < word_begin + s.length(); j++)
                sentence[j] = 'x';
        i++;
    }
    cout << sentence;
}

