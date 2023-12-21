/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * @Date: 12-17-2023 10:39:17 
 * @Description: 4-NULL,malloc,calloc,realloc,free
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
#include <stdlib.h>
#include <string.h>

int main() {
    // Pointer initialization to NULL
    int *ptr = NULL;

    // Allocating memory using malloc
    ptr = (int*) malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the allocated memory with zeros
    memset(ptr, 0, 5 * sizeof(int));

    // Printing the values to show they are initialized to zero
    printf("Values after malloc and memset:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Reallocating memory using realloc
    ptr = (int*) realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        free(ptr);
        ptr = NULL; // Set pointer to NULL after freeing
        return 1;
    }

    // Allocating memory using calloc
    int *cptr = (int*) calloc(5, sizeof(int));
    if (cptr == NULL) {
        printf("Memory allocation with calloc failed\n");
        free(cptr);
        cptr = NULL; // Set pointer to NULL after freeing
        return 1;
    }

    // Printing the values to show they are initialized to zero
    printf("Values after calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", cptr[i]);
    }
    printf("\n");

    // Freeing the memory and setting pointers to NULL
    free(ptr);
    ptr = NULL; // Set pointer to NULL after freeing

    free(cptr);
    cptr = NULL; // Set pointer to NULL after freeing

    return 0;
}

/*

In this program:

Pointer Initialization: int *ptr = NULL; initializes a pointer to NULL, ensuring it doesn't point to a random memory location.

Memory Allocation with malloc: malloc allocates uninitialized memory. The allocated memory is then manually initialized to zero 
using memset.

Memory Re-allocation with realloc: realloc is used to resize the allocated memory. It's important to handle the case where realloc 
may fail and return NULL.

Memory Allocation with calloc: calloc allocates memory and automatically initializes it to zero. This is shown with the allocation 
and printing of the cptr array.

Freeing Memory: Both ptr and cptr are freed at the end of the program to prevent memory leaks.

After each free call, the pointer is immediately set to NULL. This prevents the pointer from becoming a dangling pointer.

It's important to note that setting a pointer to NULL after freeing doesn't affect the freed memory itself; it only ensures 
that the pointer doesn't point to an invalid memory location anymore. 

This practice enhances the safety and maintainability of the code, especially in large and complex applications.

Remember, in a real embedded system, you should always check the return values of malloc, calloc, and realloc to ensure 
that memory allocation was successful. 

Additionally, memory allocation functions behave slightly differently on different systems, especially in constrained environments 
like embedded systems. 

It's crucial to understand your system's characteristics and limitations when working with dynamic memory allocation.

*/

