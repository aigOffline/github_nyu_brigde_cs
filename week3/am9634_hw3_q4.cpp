#include <iostream>
using namespace std;


const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int floorfunc(double x);
int ceilfunc(double x);
int roundfunc(double x);

int main() {
    
    double realNum;
    int roundingMethod;
    int roundedNum;
    cout<<"Please enter a Real number:"<<endl;
    cin>>realNum;
    
    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    
    cin>>roundingMethod;
    
    switch (roundingMethod) {
        case FLOOR_ROUND:
            roundedNum = floorfunc(realNum);
            cout<<"Floor round number is "<<roundedNum<<endl;
            break;
        case CEILING_ROUND:
            roundedNum = ceilfunc(realNum);
            cout<<"Ceiling round number is "<<roundedNum<<endl;
            break;
        case ROUND:
            roundedNum = roundfunc(realNum);
            cout<<"Round number is "<<roundedNum<<endl;
            break;
        default:
            cout<<"Invalid input. Please choose your rounding method again (1, 2 or 3)"<<endl;
            break;
    }
    
    return 0;
}


int floorfunc(double x) {
    
    int res;
    if (x == int(x)) {
        res = int(x);
    }
    else if (x > 0) {
        res = int(x);
    }
    else {
        res = int(x) - 1;
    }
    return res;
}

int ceilfunc(double x) {
    
    int res;
    if (x == int(x)) {
        res = int(x);
    }
    else if (x > 0) {
        res = int(x) + 1;
    }
    else {
        res = int(x);
    }
    return res;
}

int roundfunc(double x) {
    int res;
    if (ceilfunc(x) - x >x - floorfunc(x)) {
        res = floorfunc(x);
    }
    else {
        res = ceilfunc(x);
    }
    return res;
}

