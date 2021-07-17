#include <iostream>
#include <cmath>
using namespace std;
#include <climits>

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    outCountDivs = 1;
    outSumDivs = 1;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) {
            outCountDivs += 2;
            outSumDivs += i;
            outSumDivs += num / i;
        }
        
    }
}
bool isPerfect(int num){
    int count = 0, sum = 0;
    analyzeDividors(num, count, sum);
    if(num == sum)
        return true;
    else
        return false;
}

int main() {
    
    int M, count = 0, sum=0;
    cout << "Please enter a positive integer = ";
    while (!(cin >> M) || M <= 2) {
        cout <<  "Please enter a positive integer = ";
    }
    
    
    cout << "Perfect numbers: " << endl;
    for (int i = 2; i <= M; i++)
        if(isPerfect(i))
            cout << i << " ";
    
    cout << "\nAmicable numbers: " << endl;
    for(int i = 2; i <= M; i++) {
        analyzeDividors(i, count, sum);
        int sum1 = 0;
        if (i < sum) {
            analyzeDividors(sum, count, sum1);
            if(i == sum1)
                cout << i << " and " << sum << endl;
        }
    }
}
