#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int input_pin(int arr []){
    cout << "Please enter your PIN according to the following mapping: " << endl;
    cout << "PIN\t";
    for (int i = 0; i < 10; i++)
        cout << i << " ";
    cout << "\n";
    cout << "NUM\t";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";
    int pass;
    cin >> pass;
    return pass;
}

bool compare(int arr[], int pass, int PIN){
    
    
    while(pass > 0){
        if (pass % 10 != arr[PIN % 10])
            return false;
        pass /= 10;
        PIN /= 10;
    }
    if (pass == 0 && PIN == 0)
        return true;
    else
        return false;
}


void generate_array(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 3 + 1;
}

int main() {
    
    int PIN = 12345;
    int arr[10];
    generate_array(arr);
    int pass = input_pin(arr);
    if (compare(arr, pass, PIN))
        cout << "Your PIN is correct";
    else
        cout << "Your PIN is not correct";
    return 0;
}
