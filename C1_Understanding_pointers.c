/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * Linkedin: linkedin.com/in/daniel-maurelle-717bb9256
 * Youtube: https://youtube.com/playlist?list=PLDqCEJxpkYKCzZSwAz-2PpzcwMDY11NGp&si=HRSvwoUxsEBtFsfI
 * @Date: 12-18-2023 18:20:55 
 * @Description: 1-Sample code basic banking system
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

int main() {
    int data = 10;        // A regular integer variable
    int *ptr = &data;     // A pointer variable that holds the address of 'data'

    // Accessing the data using the pointer
    printf("Value of data: %d\n", data);    // Direct access
    printf("Value via ptr: %d\n", *ptr);    // Access via pointer

    // Modifying the data using the pointer
    *ptr = 20;  // Changing the value of 'data' using the pointer

    // Accessing the modified data
    printf("Value of data after modification: %d\n", data);
    printf("Value via ptr after modification: %d\n", *ptr);

    return 0;
}


/*

This program demonstrates how to access and modify the value of data through the pointer ptr.

An integer variable data is declared and initialized.

A pointer ptr is declared and initialized to point to data.

printf("Address of data: %p\n", (void *)&data); prints the address of the data variable. 

The &data provides the address of data, and the cast to (void *) is a common practice to ensure portability 
across different systems when printing addresses.

printf("Address stored in ptr: %p\n", (void *)ptr); prints the address stored in the ptr pointer, 
which should be the same as the address of data.

printf("Value of data after modification: %d\n", data); prints the value of data through the variable.

printf("Value via ptr after modification: %d\n", *ptr); prints the value of data through the pointer.

*/


/*

#include <stdio.h>

int main() {
    int data = 10;  // A regular integer variable

    // Printing the address of data
    printf("Address of data: %p\n", (void *)&data);  // Address of the variable 'data'

    // Accessing the data directly
    printf("Value of data: %d\n", data);  // Direct access

    // Modifying the data directly
    data = 20;  // Changing the value of 'data' directly

    // Accessing the modified data
    printf("Value of data after modification: %d\n", data);

    return 0;
}


*/

/*

In this version of the program:

The pointer ptr is removed.

The program prints the address of data using &data. This demonstrates that even without pointers, 
we can still obtain the address of a variable.

The value of data is accessed and modified directly, without the use of pointers.

*/