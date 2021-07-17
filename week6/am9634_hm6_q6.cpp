#include <iostream>
#include <sstream>
using namespace std;

int main() {
    
    string sentence;
    cout<<"Please enter a line of text:\n";
    getline(cin, sentence);
    
    istringstream iss(sentence);
    string characters;
    string x_sentence="";
    
    while(iss >> characters) {
        if(characters.find_first_not_of("0123456789") == string::npos) {
            for(int i = 0; i < characters.size(); i++)
                x_sentence += 'x';
        } else
            x_sentence.append(characters);
        x_sentence += ' ';
    }
    
    cout<<x_sentence<<endl;
    
    return 0;
}
