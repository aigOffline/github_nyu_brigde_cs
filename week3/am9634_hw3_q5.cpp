#include <iostream>
using namespace std;

int main() {
    double weight, height;
    double convertedPoundsToKilogram , convertedInchesToMeter, bmi;
    
    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    cout<<"Please enter height (in inches): ";
    cin>>height;
    
    convertedPoundsToKilogram  = weight * 0.453592;
    convertedInchesToMeter = height * 0.0254;
    bmi = convertedPoundsToKilogram / (convertedInchesToMeter * convertedInchesToMeter);
    
    if(bmi < 18.5){
        cout<<" Underweight ";
    }
    else if(bmi >=18.5 && bmi < 25){
        cout<<"The weight status is Normal "<<endl;
    }
    else if (bmi >= 25 && bmi < 30){
        cout<<"The weight status is Overweight "<<endl;
    }
    else if(bmi>=30 ){
        cout<<"The weight status is Obese "<<endl;
    }
    else
        cout<<"Unfound!"<<endl;
    
    return 0;
}


