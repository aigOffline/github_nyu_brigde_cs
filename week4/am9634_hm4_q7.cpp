
 #include <iostream>
 using namespace std;
 int main(){
 int n;
 cout <<"Enter a positive integer: ";
 cin >>n;
 for( int row = 0; row < n; row++ )
 {
 for( int column = 0; column < 10; column++ )
 {
 cout << ( column + 1 ) * ( row + 1 ) << '\t';
 }
 cout << endl;
 }
 }
 

