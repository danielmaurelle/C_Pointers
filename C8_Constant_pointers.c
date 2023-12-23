/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * Youtube: https://youtube.com/playlist?list=PLDqCEJxpkYKCzZSwAz-2PpzcwMDY11NGp&si=HRSvwoUxsEBtFsfI
 * @Date: 12-18-2023 18:20:55 
 * @Description: 8-Constant pointers.
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
    int value = 10;
    int another_value = 20;

    // Constant pointer
    int *const const_ptr = &value;
    printf("Value pointed to by const_ptr: %d\n", *const_ptr);
    // const_ptr = &another_value; // This line would cause a compile-time error

    // Pointer to constant value
    const int *ptr_to_const = &value;
    printf("Value pointed to by ptr_to_const: %d\n", *ptr_to_const);
    // *ptr_to_const = 15; // This line would cause a compile-time error
    ptr_to_const = &another_value; // This is allowed

    // Constant pointer to constant value
    const int *const const_ptr_to_const = &value;
    printf("Value pointed to by const_ptr_to_const: %d\n", *const_ptr_to_const);
    // const_ptr_to_const = &another_value; // This line would cause a compile-time error
    // *const_ptr_to_const = 15; // This line would also cause a compile-time error

    // Checking for NULL using if(!ptr)
    if(!const_ptr) {
        printf("const_ptr is NULL\n");
    } else {
        printf("const_ptr is not NULL\n");
    }

    // The same check can be applied to other pointers
    // if(!ptr_to_const) ...
    // if(!const_ptr_to_const) ...

    return 0;
}

/*

In this program:

const_ptr is a constant pointer. You cannot change the address it points to.

ptr_to_const is a pointer to a constant value. You cannot change the value at the pointed location, but you can change the pointer 
to point somewhere else.

const_ptr_to_const is a constant pointer to a constant value. You cannot change the address it points to nor the value at that address.

The if(!ptr) construct is a common idiom in C for checking if a pointer is NULL. It is equivalent to if(ptr == NULL). 
This is often preferred for its brevity and clarity.

*/
