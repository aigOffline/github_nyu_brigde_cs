#include <iostream>
#include <cmath>

using namespace std;

double eApprox(int n){
    double e = 1, f =1 ;
    for( int i =1; i < n; i++)
    {
        f *= i;
        e += 1/ f;
    }
    return e;
}
int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

