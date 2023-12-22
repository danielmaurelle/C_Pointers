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

/*

In C, there is no standard function provided by the language or its libraries to directly check if a memory location pointed to 
by a pointer is allocated and set (initialized). This is largely due to how memory management works in C. However, there are 
some methods and best practices you can employ to manage this issue:

Initialization of Pointers: Always initialize your pointers. If a pointer is not pointing to a valid memory allocation, 
it should be set to NULL. This way, you can check if a pointer is NULL before using it, which can prevent using uninitialized 
or freed pointers.

*/

#include <stdio.h>

int main() {

    int *ptr = NULL;
    // Allocation
    ptr = malloc(sizeof(int));
    if (ptr != NULL) {
        // Pointer is allocated
        *ptr = 5; // Set value
    }

}


/*

Checking for Successful Allocation: After calling memory allocation functions like malloc(), calloc(), or realloc(), 
you should always check if the allocation was successful by verifying the pointer is not NULL.

*/

int main() {

    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        // Allocation failed
    } else {
        // Allocation was successful
    }


}

/*

Use of Flags or Structs: In some cases, you might use a structure that contains a flag or status field along with the pointer, 
indicating whether the pointer has been allocated and set.

*/

int main() {

    typedef struct {
        int *ptr;
        int is_allocated;
    } IntPointer;

    IntPointer ip;
    ip.ptr = malloc(sizeof(int));
    ip.is_allocated = (ip.ptr != NULL);


}

/*

Valgrind and Other Memory Debugging Tools: Tools like Valgrind can be used to detect memory leaks, use of uninitialized memory, 
and other memory-related issues. They are very useful during the development phase to ensure proper memory management.
Custom Memory Management Functions: In some scenarios, you might implement custom allocation and deallocation functions 
that internally track allocations, initializations, and deallocations.

Remember, in C, direct memory management is the programmer's responsibility, and it requires careful handling to avoid issues 
like memory leaks, dangling pointers, and undefined behavior. The language itself does not provide built-in mechanisms 
for checking if a memory location is allocated and set. It's important to follow best practices to avoid common pitfalls 
related to dynamic memory management.

*/