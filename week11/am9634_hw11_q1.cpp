#include <iostream>
using namespace std;
void printTriangle(int n)
{
    if (n > 1)
        printTriangle(n - 1);
    for (int i = 0; i < n; i++)
        cout << '*';
    cout << '\n';
}
void printOpositeTriangles(int n){
    
    for( int i = 0; i < n; i++)
        cout << '*';
    cout <<'\n';
    if (n > 1)
        printOpositeTriangles(n - 1);
    for (int i = 0; i < n; i++)
        cout << '*';
    cout << '\n';
}
void printRuler(int n){
    if(n > 0) {
        printRuler(n-1);
        for(int i = 0; i < n; i++)
            cout << '-';
        cout << '\n';
        printRuler(n-1);
    }
    
}
int main()
{
    int n = 4;
    cout << "Part A: " << endl;
    printTriangle( n);
    
    cout <<endl;
    
    cout << "Part B: " << endl;
    printOpositeTriangles( n);
    cout << endl;
    
    cout << "Part C: " << endl;
    printRuler( n);
    
    return 0;
    
}

