/*
Question    3:
Suppose    John    and    Bill    worked    for    some    time    and    we    want    to    calculate    the    total    time    both    of
them    worked.    Write    a    program    that    reads    number    of    days,    hours, minutes    each    of    them
worked,    and    prints    the    total    time    both    of    them    worked    together    as    days,    hours,    minutes.
Hint: Try    to    adapt    the    elementary    method    for    addition    of    numbers    to    this    use.
Your    program    should    interact    with    the    user    exactly as    it    shows    in    the    following    example:
Please    enter    the    number    of    days    John    has    worked: 2
Please    enter    the    number    of    hours    John    has    worked: 12
Please    enter    the    number    of    minutes    John    has    worked: 15
Please    enter    the    number    of    days    Bill    has    worked: 3
Please    enter    the    number    of    hours    Bill    has    worked: 15
Please    enter    the    number    of    minutes    Bill    has    worked: 20
The    total    time    both    of    them    worked    together    is:    6    days,    3    hours    and    35 minutes.
*/
#include <iostream>
using namespace std;
int main(){
    int daysJohn, hoursJohn, minutesJonh;
    int daysBill, hoursBill, minutesBill;
    int totalDays, totalHours, totalMinutes;
    int minutesRemaining, minutesCarryOver, hoursRemaining , hoursCarryOver;
    
    cout <<"Please    enter    the    number    of    days    John    has    worked:" <<endl;
    cin >>daysJohn;
    cout <<"Please    enter    the    number    of    hours    John    has    worked:" <<endl;
    cin >>hoursJohn;
    cout <<"Please    enter    the    number    of    minutes    John    has    worked:"<<endl;
    cin >>minutesJonh;
    
    cout <<"Please    enter    the    number    of    days    Bill    has    worked:" <<endl;
    cin >>daysBill;
    cout <<"Please    enter    the    number    of    hours    Bill    has    worked: "<<endl;
    cin >>hoursBill;
    cout <<"Please    enter    the    number    of    minutes    Bill    has    worked:"<<endl;
    cin >>minutesBill;
    
    
    
    totalMinutes = minutesJonh + minutesBill;
    
    minutesRemaining = totalMinutes % 60;
    minutesCarryOver = totalMinutes / 60; // Find how many hours gets carried over from total minutes from John and Bill
    
    totalHours = hoursJohn+ hoursBill + minutesCarryOver; // Total hours work also include both hours work and the minutesCarryOver
    
    hoursRemaining = totalHours % 24; // Find the remaining hours leftover
    hoursCarryOver = totalHours / 24; // Find if any hours are carried over to days because 24 hours = 1 day
    
    totalDays = daysJohn + daysBill+ hoursCarryOver;
    
    
    cout<<"The total time both of them worked together is: "<<totalDays<<" days, "<<hoursRemaining<<" hours and "<<minutesRemaining<<" minutes."<<endl;
    
    return 0;
    
}
