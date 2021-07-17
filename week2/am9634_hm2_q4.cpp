/*
 Question    4:
 Write    a    program    that    reads    from    the    user    two positive    integers,    and    prints    the    result    of
 when    we add,    subtract    multiply, divide,    div    and    mod    them.
 Your    program    should    interact    with    the    user    exactly as    it    shows    in    the    following    example:
 Please    enter    two    positive    integers,    separated    by    a    space:
 14            4
 14    +    4    =    18
 14 – 4    =    10
 14    *    4    =    56
 
 14    /    4    =    3.5
 
 14    div    4    =    3
 14    mod    4    =    2
 */
#include <iostream>
using namespace std;
int main(){
    int num1, num2;
    
    cout <<"Please    enter    two    positive    integers,    separated    by    a    space: "<<endl;
    cin >>num1 >>num2;
    
    cout <<num1 <<" + " <<num2 <<" = "<<(num1 + num2)<<endl;
    cout <<num1 <<" - " <<num2 <<" = "<<(num1 - num2)<<endl;
    cout <<num1 <<" * " <<num2 <<" = " <<(num1 * num2)<<endl;
    cout <<num1 <<" / " <<num2 <<" = "<<(float)num1 / num2 <<endl;
    cout <<num1 <<" dev " <<num2 <<" = " <<(num1 / num2) <<endl;
    cout <<num1 <<" mod " <<num2 <<" = "<<(num1 % num2)<<endl;
    
}

