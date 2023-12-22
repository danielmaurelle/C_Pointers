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
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;
    int **array = NULL;
    int i, j;

    // Allocate memory for rows, each element is a pointer to int
    array = (int **)malloc(rows * sizeof(int *));
    if(array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // For each row, allocate memory for cols
    for(i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if(array[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d\n", i);
            return 1;
        }
    }

    // Fill the 2D array with values
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
        }
    }

    // Print the 2D array
    printf("2D Array:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for(i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

/*

This program does the following:

Dynamically allocates memory for a 2D array using double pointers.

Fills the array with consecutive integers.

Prints the array in a matrix format.

Frees the dynamically allocated memory.

Remember to always check the return value of malloc to ensure that the memory allocation was successful. Also, it's important to free 
the allocated memory to avoid memory leaks.

*/


// #include <stdio.h>
// #include <stdlib.h>

// // Function to allocate memory and modify the double pointer
// void allocateAndInitialize(int **ptr, int size) {
//     int i;
    
//     // Allocate memory for the array
//     *ptr = (int *)malloc(size * sizeof(int));
//     if(*ptr == NULL) {
//         fprintf(stderr, "Memory allocation failed\n");
//         return;
//     }

//     // Initialize the array with values
//     for (i = 0; i < size; i++) {
//         (*ptr)[i] = i * 10; // Example initialization
//     }
// }

// int main() {
//     int *array = NULL;
//     int size = 5, i;

//     // Call function to allocate and initialize the array
//     allocateAndInitialize(&array, size);

//     // Check if memory allocation was successful
//     if (array == NULL) {
//         fprintf(stderr, "Memory allocation failed in main\n");
//         return 1;
//     }

//     // Print the values in the array
//     printf("Array values:\n");
//     for (i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     // Free the allocated memory
//     free(array);

//     return 0;
// }

/*

In this program:

The allocateAndInitialize function takes a double pointer int **ptr and an int size as arguments. It allocates memory 
for an integer array of the specified size and initializes it.

The double pointer allows the function to modify the address in the caller's scope (in main).

After the function call in main, array points to the newly allocated and initialized memory.

The program prints the values in the array and then frees the memory.

This technique is particularly useful when you need to modify a pointer (like reallocating it or changing 
what it points to) inside a function.

*/
