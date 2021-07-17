#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int x1,x2,x3,x4;
    cout << "I thought of a number between 1 and 100! Try to guess it.";
    cout <<x1 <<x2 <<x3 <<x4;
    cout << "Range:    [1,    100],    Number of    guesses  ";
    //cin >> x2;
    x4 = (rand()% 100)+1;
    
    do
    {
        cout << "Try to guess it: ";
        cin >> x3;
        if (x3> x4)
            cout << "Your guess is too high\n";
        else if (x3 < x4)
            cout << "Your guess is too low\n";
        else
            cout << "You got it!\n";
    } while (x3 != x4);
    
    return 0;
}


