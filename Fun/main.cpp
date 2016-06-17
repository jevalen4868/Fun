//
//  main.cpp
//  Fun
//
//  Created by Jeremy Valenzuela on 4/13/16.
//  Copyright © 2016 Jeremy Valenzuela. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

/*
 In the case of large strings, using reference vs. value is more than twice as fast. Some cases it's three times as fast.
 */

// Prototypes.
string iconcatenate(const string& one, const string& two);
string concatenate( string one,  string two);

// Examples of templates.
template <class T, class U>
bool are_equal (T a, U b)
{
    return (a==b);
}

template <class T>
T concatenate (T one, T two)
{
    return one + two;
}

int main01(int argc, const char * argv[]) {
    // insert code here...
    string hello = "Hello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\nHello, World!\n";
    string goodbye = "GoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbye!";
    time_t now = time(0);
    int timesToRun = 100000;
    for(int i = 0; i < timesToRun; i++)
    {
        iconcatenate(hello, goodbye);
    }
    cout << time(0) - now << endl;
    
    now = time(0);
    for(int i = 0; i < timesToRun; i++)
    {
        concatenate(hello, goodbye);
    }
    cout << time(0) - now << endl;
    return EXIT_SUCCESS;
}

// inline vs. Inline is not as fast.
string iconcatenate(const string& one, const string& two)
{
    return one + two;
}

string concatenate(string one, string two)
{
    return one + two;
}

template <class T>
T add (T one, T two)
{
    
}