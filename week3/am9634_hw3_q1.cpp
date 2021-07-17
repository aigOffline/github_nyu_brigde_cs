#include <iostream>
#include <string>
using namespace std;
const double clubDiscount = .1;
int main() {
    int item1, item2;
    int basePrice;
    double tax, totalPrice, memberDiscount, priceAfterDiscount;
    string clubMember;
    
    cout<<" Enter price of first item: ";
    cin>>item1;
    cout<<"Enter price of second item: ";
    cin>>item2;
    cout<<"Does customer have a club card?(Y/N) ";
    cin>>clubMember;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>tax;
    
    basePrice = item1 + item2;
    if(item1 < item2)
        priceAfterDiscount = item2 + item1/2;
    else
        priceAfterDiscount = item1 + item2/2;
    
    memberDiscount = priceAfterDiscount - (priceAfterDiscount * clubDiscount);
    
    cout<<"Base Price: "<<basePrice<<endl;
    cout<<"Price after discount: "<<memberDiscount<<endl;
    
    if((clubMember == "yes") || (clubMember == "y") || (clubMember == "Y")){
        totalPrice = memberDiscount + memberDiscount *(tax / 100);
        cout<<"Total Price "<<totalPrice<<endl;
    }
    else if( (clubMember == "no" )||( clubMember == "n") || (clubMember == "N")){
        totalPrice = priceAfterDiscount + priceAfterDiscount * (tax / 100);
        cout<<"Total Price "<<totalPrice<<endl;
    }
    else{
        cout<<"Please enter yes or no."<<endl;
    }
    
    return 0;
}
