// The MIT License (MIT)

// Copyright (c) 2021 Prabhu Hiremath

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

/* code */

#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    Rectangle r1; // no need to write struct keyword only in C++

    r1.length = 10;
    r1.breadth = 20;

    cout << sizeof(r1) << endl;
    cout << r1.length << endl;
    cout << r1.breadth << endl;

    struct Rectangle r2[5] = {{10, 20}, {1, 2}};

    for (int i = 0; i < 5; i++)
    {
        cout << r2[i].length << endl;
        cout << r2[i].breadth << endl;
    }

    struct Rectangle *p = &r1;

    cout << "(*p).breadth = " << (*p).breadth << endl;
    cout << "p->length = " << p->length << endl;

    return 0;
}