/*
 
 a)    First    read    the    length    of    the    sequence.
 For    example,    an    execution    would    look    like:
 Please    enter    the    length    of    the    sequence: 3
 Please    enter    your    sequence:
 1
 2
 3
 The    geometric    mean    is:    1.8171
 b)    Keep    reading    the    numbers    until    -1    is    entered.
 For    example,    an    execution    would    look    like:
 Please    enter    a    non-empty    sequence    of    positive    integers,    each    one    in    a    separate    line.    End    your
 sequence    by    typing    -1:
 1
 2
 3
 -1
 The    geometric    mean    is:    1.8171
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int currElement;
    int count;
    //double lengthOfSequence, numSequence;
    double result, geometricMean;
    bool seenEndOfSeq;
    double lengthOfSequence;
    cout<<"section a"<<endl;
    
    cout<<"Please enter the length of the sequence: ";
    cin>>lengthOfSequence;
    
    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. ";
    cout<<"End your sequence by typing -1:"<<endl;
    
    count = 0;
    geometricMean = 0;
    result = 1;
    
    
    cout<<"section b"<<endl;
    
    seenEndOfSeq = false;
    
    // If user inputs -1, the while loop will break and output the geometric mean
    while (seenEndOfSeq == false) {
        // Store user input
        cin>>currElement;
        if (currElement == -1)
            seenEndOfSeq = true; // Break loop
        else {
            // Elements will multiply each other after each successive loop
            result *= currElement;
            // The result will be raised to the 1/n-th power to find the geometric mean
            geometricMean = pow(result, 1/lengthOfSequence);
            // Counter will keep track of loop iteration
            count++;
        }
    }
    
    // Output to user
    cout<<"The geometric mean is: "<<geometricMean<<endl;
    
    return 0;
}



