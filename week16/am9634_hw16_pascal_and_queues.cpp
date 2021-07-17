/*
 //Part I
 
 #include <iostream>
 #include <fstream>
 #include <string>
 
 using namespace std;
 
 bool match(ifstream& file) {
 char symbol;
 int round_brackets = 0;
 int square_brackets = 0;
 int curle_brackets = 0;
 string s = "";
 for (size_t i = 0; file >> symbol && i < 5; i++)
 s += symbol;
 if (s != "begin")
 return false;
 s = "";
 while(file >> symbol) {
 if (symbol == '(')
 round_brackets++;
 if (symbol == '[')
 square_brackets++;
 if (symbol == '{')
 curle_brackets++;
 if (symbol == ')') {
 if (round_brackets > 0)
 round_brackets--;
 else
 return false;
 }
 if (symbol == ']') {
 if (square_brackets > 0)
 square_brackets--;
 else
 return false;
 }
 if (symbol == '}') {
 if (curle_brackets > 0)
 curle_brackets--;
 else
 return false;
 }
 s += symbol;
 if (s.size() > 3) {
 s = s.substr(s.size() - 3, s.size() - 1);
 }
 }
 if (s != "end")
 return false;
 
 return (round_brackets == 0 &&
 curle_brackets == 0 &&
 square_brackets == 0);
 }
 
 
 
 int main() {
 
 ifstream f;
 cout << "Enter file path: ";
 string s;
 getline(cin >> ws, s);
 f.open(s);
 if (match(f))
 cout << "Matches" << endl;
 else
 cout << "Doesn't match" << endl;
 
 return 0;
 }
 */
//Part II;
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
class MyQueue {
private:
    size_t size;
    size_t start;
    size_t end;
    vector<T> v;
    
public:
    bool is_empty() {
        return (size == 0);
    }
    
    MyQueue() {
        size = 0;
        start = 0;
        end = -1;
    }
    
    void add(T data) {
        v.push_back(data);
        end++;
        size++;
    }
    T  pop() {
        if(!is_empty()){
            T temp = v[start];
            start++;
            size--;
            if (is_empty()) {
                v.resize(0);
                start = 0;
                end = -1;
            }
            return temp;
        } else
            return 0;
        
    }
    
    void print() {
        if (!is_empty()) {
            for (size_t i = start; i <= end; i++)
                cout << v[i] << " ";
            cout << endl;
        }
        else
            cout << "The list is empty." << endl;
    }
    //1 2 3 4 5
};
int main() {
    
    const size_t N = 10;
    MyQueue<int> q;
    srand(time(NULL));
    for (size_t i = 0; i < N; i++)
        q.add(rand() % 20);
    
    q.print();
    
    for (size_t i = 0; i < N; i++) {
        int del = q.pop();
        cout << "Deleted element = " << del << endl;
        q.print();
    }
    
    for (size_t i = 0; i < N; i++)
        q.add(rand() % 20);
    q.print();
    
    for (size_t i = 0; i < N; i++) {
        int del = q.pop();
        cout << "Deleted element = " << del << endl;
        q.print();
    }
    
    return 0;
}




