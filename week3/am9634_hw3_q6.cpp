
#include <iostream>
#include <string>
using namespace std;
int main() {
    int callStartHour, callStartMin;
    int callEndHour, callEndMin;
    double rate=0;
    string day;
    char colon;
    int totalminute = 0;
    
    
    cout<<"What day of the week you started the call ( e.g. If Monday, enter Mo): "<<endl;
    cin>>day;
    cout<<"Please eneter the time  you started the call: (e.g 8:00 P.M. is 20:00)?"<<endl;
    cin>>callStartHour>>colon>>callStartMin;
    cout<<"Please enter the time you ended the call:(e.g 12:45 A.M P.M. is 00:45)?"<<endl;
    cin>>callEndHour>>colon>>callEndMin;
    
    totalminute = callEndMin - callStartMin + (callEndHour - callStartHour) * 60;
    
    if((day == "Mo") || (day == "Tu") || (day == "We") || (day == "Th") || (day == "Fr")){
        if( (callStartHour >= 8) && (callStartHour < 18)){
            rate = totalminute * 0.40;
            }
        else
        {
            rate = totalminute * 0.25;
        }
    }
    else if ((day == "Sa") || (day == "Su")){
        rate = totalminute * 0.15;
    }
    else
    {
        cout << "Wrong day. Day format should be one of Mo, Tu, We, Th, Fr, Sa, Su" << endl;
        return 0;
    }
    
    cout << "Your total is "<<rate << endl;
    return 0;
}
