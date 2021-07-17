#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double quadRoot, addQuadRoot, subQuadRoot, QuadRoot;
    cout<<"Please enter value of a: ";
    cin>>a;
    cout<<"Please enter value of b: ";
    cin>>b;
    cout<<"Please enter value of b: ";
    cin>>c;
    quadRoot = b*b - 4*a*c;
    if ((a == 0) && (b == 0) && (c == 0)){
        cout<<"Infinity number of solutions."<<endl;
    }
    else if((a== 0) && (b == 0) && (c != 0)){
        cout<<"No solution."<<endl;
    }
    
    else if(quadRoot < 0){
        cout << "No real solution" << endl;
        return 0;
    }
    else if(quadRoot == 0){
        QuadRoot = -b/(2*a);
        cout<<"One real solution"<<QuadRoot<<endl;
    }
    else if(quadRoot > 0){
        addQuadRoot = (-b+sqrt(quadRoot))/(2*a);
        subQuadRoot = (-b-sqrt(quadRoot))/(2*a);
        cout<<"Two real solution solutions "<<subQuadRoot<<" "<<addQuadRoot<<endl;
    }
    return 0;
}
