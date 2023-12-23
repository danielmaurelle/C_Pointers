/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * Youtube: https://youtube.com/playlist?list=PLDqCEJxpkYKCzZSwAz-2PpzcwMDY11NGp&si=HRSvwoUxsEBtFsfI
 * @Date: 12-18-2023 18:20:55 
 * @Description: 2-Pointers and functions.
 * 
 * MIT License
 * 
 * Copyright 2023 Daniel Maurelle
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>

// Function prototype
void modifyValue(int *ptr);

int main() {
    int value = 10;
    printf("Value before modification: %d\n", value);

    // Pass the address of 'value' to the function
    modifyValue(&value);

    printf("Value after modification: %d\n", value);
    return 0;
}

// Function definition
void modifyValue(int *ptr) {
    // Modify the value at the address pointed to by ptr
    *ptr = 20;
}


/*

In this program:

modifyValue is a function that takes a pointer to an integer (int *ptr).

In the main function, we declare an integer value and initialize it to 10.

We then call modifyValue and pass the address of value using &value.

Inside modifyValue, the value at the address pointed to by ptr is modified. This is achieved by dereferencing the pointer 
using the * operator and assigning a new value (20 in this case).

When we return to main, we see that the original value has been changed, demonstrating how pointers can be used 
to modify data outside their defining scope.


*/