
/*
 Question    1:
 Write    a    program    that    asks the    user    to    enter    a    number    of    quarters,
 dimes,    nickels and
 pennies and
 
 
 then    outputs    the    monetary    value    of    the    coins    in    the    format    of
 dollars    and remaining    cents.
 Your    program    should    interact    with    the    user    exactly as    it    shows    in    the    following    example:
 Please    enter    number of    coins:
 #    of    quarters:    13
 #    of    dimes:    4
 #    of    nickels:    11
 #    of    pennies:    17
 The total    is    4 dollars    and    37 cents
 */

#include <iostream>
using namespace std;

int main(){
    int quarters, dimes, nickels, pennies; // coins
    int dollars, cents, total;
    cout<< "Please enter number of quarters: "<<endl;
    cin>>quarters;
    cout<<"Please enter number of dimes: "<<endl;
    cin>>dimes;
    cout<<"Please enter number of nickles: "<<endl;
    cin>> nickels;
    cout<<"Please enter number of pennies: "<<endl;
    cin>> pennies;
    
    dollars = (25 * quarters )+(10 * dimes)+(5*nickels)+(1* pennies);
    total = dollars /100;
    cents = dollars % 100;
    cout<<"The total is $ " << total <<" dollars and "<< cents<<" cents! ";
    
    return 0;
}

