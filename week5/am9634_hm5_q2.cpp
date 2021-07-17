#include <iostream>
#include <cmath>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol); //a
void printPineTree(int n, char symbol);//b

int main() {
    printPineTree(3, '#');
    return 0;
}
void printShiftedTriangle(int n, int m, char symbol)
{
    int k = 1, p =1;
    for( int i = 0; i<n; i++) //lines
    {
        for(int j = 0; j<m; j++)
            cout <<' ';
        for(int j = 0; j<n - k; j++) //print space before symbols
            cout << ' ';
        for(int j =0; j<p; j++) //print symbols
            cout <<symbol;
        cout <<endl;
        k++;
        p+=2;
    }
}
void printPineTree(int n, char symbol)
{
    int shift_to_space = 1;
    for(int i = 0; i<n;i++)//print n triangles
    {
        printShiftedTriangle(i+2,n - shift_to_space, symbol);
        shift_to_space++;
    }
    
}


