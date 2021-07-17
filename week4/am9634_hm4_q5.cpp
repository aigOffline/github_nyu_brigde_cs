/*
 Question    5:
 Write    a    program    that    asks    the user    to    input    a    positive    integer    n,    and    prints a    textual    image    of    an
 hourglass    made    of    2n lines    with    asterisks.
 For    example    if    n=4,    the    program    should    print:
 *******
 *****
 ***
 *
 *
 ***
 *****
 *******
 */
#include <iostream>
using namespace std;
int main() {
    
    int row, col;
    int size;
    int diagA, diagB;
    
    cout << "Enter height of the hourglass "<<endl;
    cin >> size;
    
    for ( row=0; row<size; row++ ) {
        for ( col=0; col<size; col++ ) {
            
            diagA = row;
            diagB = size-row-1;
            
            if ( diagA <= diagB ){
                if ( col >= diagA && col <= diagB )
                    cout << "*";
                else
                    cout << " ";
            }
            else {
                if (  col >= diagB && col <= diagA  )
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << std::endl;
    }
    
    cout << std::endl;
    
    return 0;
}



