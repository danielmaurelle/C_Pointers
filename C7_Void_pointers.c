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
    int i;
    float f;
    char c;
    
    void *ptr;  // Declare a void pointer

    // Use the void pointer to read an integer
    ptr = &i;  // Point to the integer
    printf("Enter an integer: ");
    scanf("%d", (int *)ptr);  // Cast to int* for scanf
    printf("You entered integer: %d\n", *(int *)ptr);  // Cast to int* to access the value

    // Use the void pointer to read a float
    ptr = &f;  // Point to the float
    printf("Enter a float: ");
    scanf("%f", (float *)ptr);  // Cast to float* for scanf
    printf("You entered float: %f\n", *(float *)ptr);  // Cast to float* to access the value

    // Use the void pointer to read a character
    ptr = &c;  // Point to the char
    printf("Enter a character: ");
    scanf(" %c", (char *)ptr);  // Cast to char* for scanf (note the space before %c)
    printf("You entered character: %c\n", *(char *)ptr);  // Cast to char* to access the value

    return 0;
}


/*

In this program:

ptr is a void pointer used to point to variables of different types.

When using scanf, the void pointer is cast to the appropriate type (int*, float*, char*).

To print the values, the void pointer is cast again to the appropriate type and then dereferenced.

Note that when reading a character with scanf, a space is added before %c. This is to ensure that any leftover whitespace 
in the input buffer (like a newline from previous input) is not mistakenly read as the character input.

*/