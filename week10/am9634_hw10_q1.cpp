#include <iostream>
using namespace std;
string* createWordsArray(string sentence, int& outWordsArrSize);
// [”You” , ”can” , ”do” , ”it”],
int main()
{
    string sentence;
    string* words;
    int outWordsArrSize = 0;
    cout <<"Please enter a sentence: "<<endl;
    getline(cin >> ws, sentence);
    words = createWordsArray(sentence, outWordsArrSize);
    cout <<"Words array size "<<outWordsArrSize <<" contains:\n";
    cout << "[";
    for(int i = 0; i <outWordsArrSize; i++){
        cout << "\"" <<words[i] << "\"";
        if ( i!= outWordsArrSize - 1)
            cout << ", ";
        
    }
    cout << "]";
    cout << endl;
    return 0;
}
string* createWordsArray(string sentence, int& outWordsArrSize)
{
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i]== ' ')
            outWordsArrSize++;
    }
    outWordsArrSize++;
    string*words = new string[outWordsArrSize];
    int wordCounter = 0;
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] ==' '){
            wordCounter++;
            i++;
        }
        words[wordCounter] += sentence[i];
    }
    return words;
}



