/*
 The Fibonacci numbers sequence, Fn, is defined as follows:
 F0 is 1, F1 is 1,and Fn = Fn-1 +Fn-2   for n = 2,3,4,...
 In other words, each number is the sum of the previous two numbers. The first 10 numbers in Fibonacci sequence are: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
 
 Note: Background of Fibonacci sequence: https://en.wikipedia.org/wiki/Fibonacci_number
 1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
 sequence.
 2. Write a program that prompts the user to enter a positive integer num, and then
 prints the num’s elements in the Fibonacci sequence.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter a positive integer: 7
 13
 */
#include <iostream>

using namespace std;

int fib(int n){
    int num1 = 1, num2 = 1, fibonacci = 0;
    if(n == 0 || n == 1)
        return 1;
    else
        for(int i = 2; i < n; i++){
            fibonacci = num1 + num2;
            num1 = num2;
            num2 = fibonacci;
        }
    return fibonacci;
}
int main(){
    int num;
    cout <<"Please enter a positive integer: ";
    cin >>num;
    cout <<fib(num)<<endl;
    return 0;
}
