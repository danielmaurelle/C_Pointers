/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * @Date: 12-18-2023 10:30:09 
 * @Description: 12-Programs using pointers as func params
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

QSORT ASCENDING

*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort()
int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    displayArray(array, n);

    int choice;
    printf("\nSelect Sorting Option:\n");
    printf("1: Sort in Ascending Order\n");
    printf("2: Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(array, n, sizeof(int), compareIntegers);
            printf("Sorted array in ascending order:\n");
            displayArray(array, n);
            break;
        case 2:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

/*

This program:

Declares an array of integers.

Provides a user menu to select the sorting option.

Uses qsort() for sorting the array in ascending order.

Includes a custom comparison function compareIntegers() passed to qsort().

You can modify the array and add more functionality as needed. For an embedded system, ensure that the standard library functions l
ike qsort() and printf() are supported, or replace them with equivalent functionality suitable for your specific system.

*/

/*

QSORT ASCENDING / DESCENDING

*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for ascending order
int compareAscending(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for descending order
int compareDescending(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(array) / sizeof(array[0]);
    int (*compareFunc)(const void*, const void*); // Pointer to comparison function

    printf("Original array:\n");
    displayArray(array, n);

    int choice;
    printf("\nSelect Sorting Option:\n");
    printf("1: Sort in Ascending Order\n");
    printf("2: Sort in Descending Order\n");
    printf("3: Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            compareFunc = compareAscending;
            qsort(array, n, sizeof(int), compareFunc);
            printf("Sorted array in ascending order:\n");
            displayArray(array, n);
            break;
        case 2:
            compareFunc = compareDescending;
            qsort(array, n, sizeof(int), compareFunc);
            printf("Sorted array in descending order:\n");
            displayArray(array, n);
            break;
        case 3:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

/*

This program:

Contains two comparison functions: compareAscending and compareDescending.

Uses a function pointer compareFunc to point to the appropriate comparison function.

Allows the user to select whether to sort the array in ascending or descending order.

Uses qsort() with the selected comparison function to sort the array.

*/

/*

DISPATCH TABLES

*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for ascending order
int compareAscending(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for descending order
int compareDescending(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Dispatch table for sorting functions
typedef int (*CompareFunc)(const void*, const void*);
CompareFunc sortOptions[] = {compareAscending, compareDescending};

// Main function
int main() {
    int array[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    displayArray(array, n);

    int choice;
    printf("\nSelect Sorting Option:\n");
    printf("1: Sort in Ascending Order\n");
    printf("2: Sort in Descending Order\n");
    printf("3: Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 2) {
        qsort(array, n, sizeof(int), sortOptions[choice - 1]);
        printf("Sorted array:\n");
        displayArray(array, n);
    } else if (choice == 3) {
        printf("Exiting program.\n");
        return 0;
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

/*

In this program:

I've defined two comparison functions, compareAscending and compareDescending.
A dispatch table sortOptions is created, which is an array of function pointers. Each element in this array points 
to a comparison function.
The user's choice determines which function pointer is used in the qsort() call.
This approach allows easy extension of the program. You can add more sorting options (like sorting by specific criteria) 
just by adding more functions to the sortOptions array and updating the user menu accordingly.

This example demonstrates the power and flexibility of function pointers and dispatch tables in C programming, 
especially in scenarios where the behavior of a program needs to change dynamically based on user input or other runtime conditions.

*/