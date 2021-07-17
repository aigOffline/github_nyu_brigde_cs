/*
 Question    2:
 Write    a    program    that    asks the    user    to    enter    an    amount    of    money    in    the    format    of    dollars    and
 remaining    cents.    The    program    should    calculate    and    print    the    minimum    number    of    coins
 (quarters,    dimes,    nickels    and    pennies)    that    are    equivalent    to    the    given    amount.
 Hint:    In    order    to    find    the    minimum    number    of    coins,    first    find    the    maximum    number    of
 quarters    that    fit    in    the    given    amount    of    money,    then    find    the    maximum    number    of    dimes
 that    fit    in    the    remaining    amount,    and    so    on.
 Your    program    should    interact    with    the    user    exactly as    it    shows    in    the    following    example:
 Please    enter    your    amount    in    the    format    of    dollars    and    cents    separated    by    a    space:
 4        37
 4    dollars    and    37    cents    are:
 17    quarters,    1    dimes,    0    nickels    and    2    pennies
 */
 
 #include <iostream>
 using namespace std;
 
 int main() {
 
 int dollar, cent;
 int dollarToCent, totalCent;
 int minQuarter, minDime, minNickel, minPenny;
 
 cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
 cin>>dollar >>cent;
 
 cout<<dollar<<" dollars and "<<cent<<" cents are:"<<endl;
 
 dollarToCent = dollar * 100;
 
 totalCent = dollarToCent + cent;
 
 minQuarter = totalCent / 25;
 minDime = (totalCent - minQuarter * 25 )/ 10;
 minNickel = (totalCent - minQuarter * 25 - minDime * 10) / 5;
 
 minPenny = (totalCent - minQuarter * 25 - minDime * 10 - minNickel * 5) / 1;
 
 // Print-out of the coins
 cout<<minQuarter<<" quarters, "<<minDime<<" dimes, "<<minNickel<<" nickels";
 cout<<" and "<<minPenny<<" pennies"<<endl;
 
 return 0;
 }

