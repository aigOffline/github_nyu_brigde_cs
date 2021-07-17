
#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeap(int year);
void printYearCalender(int year, int startingDay);
int main() {
    cout << "year = ";
    int year;
    cin>>year;
    cout<<"Starting day spaces = ";
    int day;
    cin>>day;
    
    printYearCalender(year, day);
    return 0;
}
int printMonthCalender(int numOfDays, int startingDay){
    cout << "Mon\t";
    cout << "Tue\t";
    cout << "Wed\t";
    cout << "Thu\t";
    cout << "Fri\t";
    cout << "Sat\t";
    cout << "Sun\t";
    cout << endl;
    for(int i = 1; i < startingDay; i++)
        cout << "\t";
    int daysOfWeek = startingDay;
    for(int days = 1; days <= numOfDays; days++){
        if(daysOfWeek == 8){
            cout<<endl;
            daysOfWeek = 1;
        }
        cout << days <<"\t";
        daysOfWeek++;
       
    }
    cout<<endl;
    return daysOfWeek-1;
}
bool isLeap( int year){
    bool check = false;
    if(year % 4 == 0)
        check = true;
    if(year % 100 == 0)
        check = false;
    if(year % 400 == 0)
        check = true;
    return check;
}

void printYearCalender(int year, int startingDay) {
    char *months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
        "October", "November", "December" };
    int sdm = startingDay;
    for (int i = 1; i <= 12; i++) {
        cout << months[i - 1] << " " << year << endl;
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            sdm = printMonthCalender(31, sdm);
        else {
            if (i != 2)
                sdm = printMonthCalender(30, sdm);
            else {
                if (isLeap(year))
                    sdm = printMonthCalender(29, sdm);
                else
                    sdm = printMonthCalender(28, sdm);
            }
        }
        sdm++;
        if (sdm == 8)
            sdm = 1;
    }
}
