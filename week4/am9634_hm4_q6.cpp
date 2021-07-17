/*
 Question    6:
 Write    a    program    that    asks    the user    to    input    a    positive    integer    n,    and    print    all    of    the    numbers
 from    1    to    n that    have    more    even    digits    than    odd    digits.
 For    example,    if    n=30,    the    program    should    print:
 2
 4
 6
 8
 20
 22
 24
 26
 28
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cout <<"Enter a positive integer: (n) ";
    cin >>n;
    int count;
    for (count = 1; count <n; count++)
        if(count % 2 == 0){
            cout <<count<<endl;
            
        }
    
}
