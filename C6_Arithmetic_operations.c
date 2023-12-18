/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
 * @Date: 12-17-2023 12:38:08 
 * @Description: 6-Arithmetic operations
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
    int array[] = {10, 20, 30, 40, 50};
    int *ptr = array; // Pointer to the first element of the array

    printf("Original pointer points to %d\n", *ptr);

    // Using ++ with pointers (pre-increment)
    ++ptr;
    printf("After pre-increment, pointer points to %d\n", *ptr);

    // Using -- with pointers (pre-decrement)
    --ptr;
    printf("After pre-decrement, pointer points to %d\n", *ptr);

    // Using ptr++ (post-increment)
    printf("Using post-increment, pointer points to %d and then moves to ", *ptr++);
    printf("%d\n", *ptr);

    // Using ptr-- (post-decrement)
    printf("Using post-decrement, pointer points to %d and then moves back to ", *ptr--);
    printf("%d\n", *ptr);

    // Using + with pointers
    ptr = ptr + 3; // Moving the pointer 3 elements forward
    printf("After adding 3, pointer points to %d\n", *ptr);

    // Using - with pointers
    ptr = ptr - 2; // Moving the pointer 2 elements backward
    printf("After subtracting 2, pointer points to %d\n", *ptr);

    return 0;
}

/*

In this program, ptr is a pointer to an integer and it initially points to the first element of the array. Then, it is manipulated 
using various pointer arithmetic operations. 

Note how the ptr++ and ptr-- operations work: they return the value before the increment/decrement, and then the pointer is moved. 
This behavior is different from ++ptr and --ptr, which move the pointer first and then return the value.

Remember, while this code provides a basic demonstration, real-world applications of these concepts often involve 
more complex scenarios, such as dynamic memory allocation and pointer arithmetic for multi-dimensional arrays.

*/

/*

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 4;
    int i, j;

    // Dynamically allocate memory for a 2D array
    int **array = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Populate the array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
        }
    }

    // Access and modify elements using pointer arithmetic
    printf("Original 2D array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Incrementing all elements by 1 using pointer arithmetic
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(*(array + i) + j) += 1; // Equivalent to array[i][j] += 1
        }
    }

    // Display the modified array
    printf("\nModified 2D array (all elements incremented by 1):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}


*/

/*

In this example, we first allocate memory for a 2D array using malloc(). The array is then populated with values in a nested loop. 

We use pointer arithmetic to increment each element of the 2D array. Note the use of *(*(array + i) + j) for accessing and 
modifying elements, which is equivalent to using array[i][j].

Finally, it's crucial to free the dynamically allocated memory using free() to prevent memory leaks. This example provides a glimpse 
into the power and complexity of pointer operations in C, especially in scenarios involving dynamic memory allocation 
and multi-dimensional data structures.

*/

/*

In C, adding one pointer to another directly is not allowed and does not make sense conceptually. Pointers represent memory addresses, 
and adding two addresses together doesn't yield a meaningful or valid result in the context of most programming tasks. 

This is why C standard does not support this operation.

However, there are valid scenarios in pointer arithmetic where you might add or subtract an integer from a pointer, or subtract 
one pointer from another, under certain conditions. Here's a brief explanation:

Adding or Subtracting an Integer to/from a Pointer: This moves the pointer forwards or backwards in memory. The amount it moves 
depends on the size of the data type the pointer is pointing to.

int *ptr;
ptr + 1; // Moves the pointer to the next integer

Subtracting Two Pointers: This is valid if both pointers point to elements of the same array (or one past the last element). It gives 
the number of elements between the two pointers.

int array[5];
int *ptr1 = &array[1];
int *ptr2 = &array[4];
int distance = ptr2 - ptr1; // Yields 3

If you need to perform some kind of operation involving two pointers, it typically involves either calculating the distance between them 
(as in the subtraction example) or adjusting one pointer based on the value or position of another (using integer addition/subtraction).

For any other type of computation involving pointers, you would usually first dereference the pointers 
(i.e., access the values they point to), perform the computation on these values, and possibly store the result in another pointer 
or variable as appropriate.

Multiplication and division are not allowed with pointers in C. Pointer arithmetic in C is limited to the following operations:

Addition of a Pointer and an Integer: Moves the pointer forward by a number of elements equal to the integer. For instance, 
ptr + 3 moves ptr forward by 3 elements of the type to which it points.

Subtraction of an Integer from a Pointer: Moves the pointer backward by a number of elements. For example, ptr - 2 moves ptr backward 
by 2 elements.

Subtraction of One Pointer from Another: Valid when both pointers are of the same type and point to elements of the same array 
(or one past the end). This operation yields the number of elements between the two pointers.

Increment (++) and Decrement (--) Operators: These can be used to increment or decrement a pointer by one element. They come in both pre- and post-increment/decrement forms.
Multiplication and division, however, do not have a defined or meaningful behavior in the context of pointers in C. 

Pointers represent memory addresses, and multiplying or dividing these addresses doesn't produce a result that is useful or valid 
within the language's memory model.

If you need to perform multiplication or division, it is usually done on the values pointed to by the pointers (after dereferencing), 
or on the integer values used in pointer arithmetic calculations. 

For instance:

int a = 5;
int b = 10;
int *ptrA = &a;
int *ptrB = &b;
int result = (*ptrA) * (*ptrB); // Dereferencing and then multiplying

In this example, ptrA and ptrB are pointers, and we dereference them using * to get the values they point to, which are then multiplied 
together.

*/