/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * @Date: 12-18-2023 10:04:06 
 * @Description: 10-Copy string program
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

void stringCopy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int main() {
    char source[] = "Hello, Embedded World!";
    char destination[30]; // Ensure this is large enough to hold the source string

    stringCopy(destination, source);

    printf("Copied String: %s\n", destination);

    return 0;
}

/*

In this program:

The stringCopy function takes two pointers: dest (destination) and src (source). It copies each character 
from the source to the destination, incrementing both pointers until the end of the source string is reached, 
indicated by the null character '\0'.

The main function demonstrates the usage of stringCopy. It defines a source string and a destination array (sized to ensure 
it can hold the source string).

The copied string is then printed to the standard output.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringCopy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int main() {
    char source[] = "Hello, Embedded World!";
    char *destination;

    // Allocate memory for the destination based on the size of the source
    destination = (char *)malloc(strlen(source) + 1); // +1 for the null terminator
    if (destination == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    stringCopy(destination, source);

    printf("Copied String: %s\n", destination);

    // Free the allocated memory
    free(destination);

    return 0;
}


/*

Changes made:

Included <stdlib.h> and <string.h> for malloc, free, and strlen.

Allocated memory for destination using malloc, ensuring it's large enough to hold the source string plus the null terminator.

Added a check to ensure malloc successfully allocated memory.

Used free to release the memory allocated to destination at the end of main.

Note:

Memory allocation with malloc can fail, so it's important to check if the returned pointer is NULL.

Always free dynamically allocated memory when it's no longer needed to prevent memory leaks.

This approach assumes that your embedded system supports dynamic memory allocation, which is not always the case in 
constrained environments. 

If dynamic allocation is not supported, you would need to declare destination with a fixed size, ensuring it's large enough 
for any expected input.

*/