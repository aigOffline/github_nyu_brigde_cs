#include <iostream>
#include <cmath>

using namespace std;

void analyzeDividors(const int num, int &outCountDivs, int &outSumDivs)
{
    outCountDivs = 0;
    outSumDivs = 0;
    for (int i=1; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            outCountDivs++;
            outSumDivs += i;
        }
    }
    for (int i=sqrt(num); i > 1; i--)
        if (num % i == 0)
        {
            outCountDivs++;
            outSumDivs += num / i;
        }
}
bool isPerfect(int num)
{
    int outSumDivs, outCountDivs;
    analyzeDividors(num, outCountDivs, outSumDivs);
    if (num == outSumDivs)
        return true;
    else
        return false;
}
int main()
{
    int M, count_i, count_j, y, z, w=0;
    cout << "Please enter a positive integer >= 2: ";
    cin >> M;
    cout << "Perfect numbers: ";
    for (int i=2; i<=M; i++)
        if (isPerfect(i) == true)
            cout << i << " ";
    cout << endl << "Amicable numbers: " << endl;
    
    for (int x = 2; x <= M; x++)
    {
        analyzeDividors(x, count_i, y); // y = sum of div x
        analyzeDividors(y, count_j, z); // z = sum of div y
        if (x == z && w != x && x != y) // y == z => amicable
        {
            w = y;
            cout << x << " " << y << endl;
        }
    }
    
    return 0;
}

