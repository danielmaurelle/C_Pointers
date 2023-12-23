/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * Linkedin: linkedin.com/in/daniel-maurelle-717bb9256
 * Youtube: https://youtube.com/playlist?list=PLDqCEJxpkYKCzZSwAz-2PpzcwMDY11NGp&si=HRSvwoUxsEBtFsfI
 * @Date: 12-18-2023 18:20:55 
 * @Description: 11-Passing by value vs passing by reference.
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


/*


In C programming, the concepts of "passing by value" and "passing by reference" are fundamental to understanding 
how functions handle data. Here's a comparison of the two:

### Passing by Value
1. **Definition**: When a function is called, the values of the arguments are copied into the function's parameters. In other words, 
the function works with copies of the data.
2. **Implication**: Any changes made to the parameters inside the function have no effect on the original data. The original variables 
remain unchanged.
3. **Usage**: Commonly used for simple data types like `int`, `char`, `float`, etc.
4. **Memory**: Each call to the function creates new storage space for the parameters.
5. **Example**: If you pass an integer to a function, the function gets a copy of the integer's value.

### Passing by Reference
1. **Definition**: Instead of passing the actual value, the function is given the address (reference) of the variable. In C, 
this is done using pointers.
2. **Implication**: Any changes made to the parameters inside the function affect the original data, since both the parameter and 
the original variable refer to the same memory location.
3. **Usage**: Preferred for passing complex data types like arrays, structures, or large variables to avoid the overhead of copying.
4. **Memory**: No new storage space is created for the passed data; the function operates directly on the original data's memory.
5. **Example**: If you pass the address of an integer (a pointer) to a function, the function can change the value of the original integer.

### Key Differences
- **Effect on Original Data**: Changes in the function affect the original data in passing by reference, but not in passing by value.
- **Memory Overhead**: Passing by value can use more memory due to copying, while passing by reference is more memory efficient.
- **Safety**: Passing by value is safer since it does not allow unintended modifications to the original data, whereas passing 
by reference can lead to such issues if not handled carefully.

In summary, choosing between passing by value and passing by reference depends on the requirements of your program, 
particularly considering efficiency and safety.


*/

/*

PASSING BY VALUE

*/


#include <stdio.h>

// Function to square a number
int square(int n) {
    n = n * n;
    return n;
}

int main() {
    int number = 5;
    int result = square(number);

    printf("Original number: %d\n", number);
    printf("Squared number: %d\n", result);

    return 0;
}

/*

The function square receives a copy of number.

Any changes made to n inside square do not affect number in main.

The original number remains 5, and result is 25.

*/

/*

PASSING BY REFERENCE

*/

/*

#include <stdio.h>

// Function to multiply each element by 2
void modifyArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    modifyArray(array, size);

    printf("Modified array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

*/

/*

The modifyArray function receives a pointer to the first element of array.

Changes made to arr inside the function are reflected in array in main.

The original array elements are modified.

*/


/*

ADDITIONAL EXAMPLE OF PASSING BY REFERENCE

*/

/*

#include <stdio.h>

// Function to swap the values of two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

*/

/*

swap takes pointers to x and y.

Changes to *a and *b in swap directly affect x and y in main.

x and y are effectively swapped.

*/

/*

IMPORTANT:

Even when passing a pointer (i.e., passing by reference) to a function in C, what is actually being passed is 
a copy of the pointer's value, which is the address of the data it points to. 

This copied pointer is pushed onto the stack when the function is called.

Let's break this down:

Pointer as Argument: When you pass a pointer to a function, you're passing the address of a variable. This address is the value 
held by the pointer.

Copy of Pointer in Function: Inside the function, this address is copied into the function's parameter (which is another pointer). 
This new pointer in the function's scope points to the same memory location as the original pointer.

Stack Memory: The copied pointer (with the address) is stored in the stack memory as part of the function's stack frame.

Indirect Manipulation of Data: Although the pointer is copied, the copied pointer still points to the original memory location. 
Therefore, any changes made through this copied pointer inside the function will affect the original data.

*/

/*

EXAMPLE ILLUSTRATION

*/

/*

#include <stdio.h>

void modifyValue(int *ptr) {
    // ptr is a copy of the pointer passed to the function
    *ptr = 10; // Modifies the value at the memory address pointed to by ptr
}

int main() {
    int value = 5;
    printf("Before: %d\n", value);

    modifyValue(&value); // Passing the address of value

    printf("After: %d\n", value); // The original value is modified
    return 0;
}

*/

/*

modifyValue receives a copy of the address of value.

The ptr in modifyValue is a different pointer (in terms of being a separate instance), but it points to the same address as &value.

Changes through ptr affect value because they both reference the same memory location.

Thus, even though the pointer itself is passed by value, the effect is similar to passing by reference, as the function can modify the data 
at the pointed-to address.

*/
