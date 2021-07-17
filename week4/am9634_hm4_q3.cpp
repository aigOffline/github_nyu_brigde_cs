/*
 Question    3:
 Write    a    program    that    reads    from    the    user    a    positive    integer (in    a    decimal    representation),    and
 prints    its    binary    (base    2)    representation.
 Your    program    should    interact    with    the    user    exactly as    it    shows    in    the    following    example:
 Enter    decimal    number:
 76
 The    binary    representation    of    76    is    1001100
 


*/

#include <iostream>
using namespace std;
int main(){
    int dec,rem;
    int i=1,sum=0;
    cout<<"Enter the decimal to be converted:";
    cin>>dec;
    while(dec>0)
    {        rem = dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
       //cout <<rem;
    }
    cout<<"The binary of the given number is:"<<sum<<endl;

    return 0;
}


