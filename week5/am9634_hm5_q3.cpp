#include <iostream>
using namespace std;


int printMonthCalender(int numOfDays, int startingDay);
int checkLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    
    int numOfDays, startingDay;
    cout<<"Please enter number of days in the month: ";
    cin>>numOfDays;
    
    cout<<"Please enter the starting day of the month (e.g. 4 is the first Sunday of the calendar month): ";
    cin>>startingDay;
    
    printMonthCalender(numOfDays, startingDay);
    
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    int week, day;
    
    cout<<"Mon"<<'\t'<<"Tue"<<'\t'<<"Wed"<<'\t'<<"Thu"<<'\t'<<"Fri"<<'\t'<<"Sat"<<'\t'<<"Sun"<<endl;
    
    for (week = 1; week <= (numOfDays / 7); week++) {
        for (day = 1; day <= (numOfDays / 7); day++) {
            cout<<day<<'\t';
        }
        cout<<endl;
    }
    
    return numOfDays;
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

void printYearCalender(int year, int startingDay) {
    
}
