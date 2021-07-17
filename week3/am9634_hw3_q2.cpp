
#include <iostream>
using namespace std;
int main() {
    string fisrtName;
    int graduationYear, currentYear, year;
    
    cout<<"Please enter your name: ";
    cin>>fisrtName;
    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;
    cout<<"Please enter current year: ";
    cin>>currentYear;
    
    year = graduationYear - currentYear;
    if(year == 4){
        cout<<fisrtName<<", you are a Freshman"<<endl;
    }else if(year == 3 ){
        cout<<fisrtName<<", you are a Sohhomore"<<endl;
    }else if(year == 2){
        cout<<fisrtName<<", you are a Junior"<<endl;
    }else if(year == 1 ){
        cout<<fisrtName<<", you are a Senior"<<endl;
    }else if(year <= 0){
        cout<<fisrtName<<", you are a Graduated"<<endl;
    }else
        cout<<"Not in collage yet!";
    
    
    return 0;
}
