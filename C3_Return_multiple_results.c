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

// Function prototype
void performCalculations(int a, int b, int *sum, int *product, int *difference, float *quotient);

int main() {
    int a = 10, b = 5;
    int sum, product, difference;
    float quotient;

    // Call the function
    performCalculations(a, b, &sum, &product, &difference, &quotient);

    // Display the results
    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);
    printf("Difference = %d\n", difference);
    printf("Quotient = %.2f\n", quotient);

    return 0;
}

// Function to perform calculations
void performCalculations(int a, int b, int *sum, int *product, int *difference, float *quotient) {
    *sum = a + b;
    *product = a * b;
    *difference = a - b;

    if(b != 0) {
        *quotient = (float)a / b;
    } else {
        *quotient = 0; // Avoid division by zero
    }
}

/*

In this program:

Function Definition: A function that takes two integer inputs and returns multiple results (e.g., sum, product, difference, and quotient) 
using pointer arguments.

Main Program: Calls the function with sample inputs and displays the results.

The performCalculations function takes two integers a and b and four pointers (sum, product, difference, quotient) to store 
the results of the calculations.

The function calculates the sum, product, difference, and quotient of a and b, and stores the results in the respective variables 
via pointers.

The main function initializes two numbers, calls performCalculations, and then prints the results.

This is a simple example, but it demonstrates the use of pointers to return multiple values from a function, a technique 
that's very useful in embedded programming. 

In a real-world embedded system, such functions might be used to read sensor data or perform calculations on hardware inputs.

*/

/*

#include <stdio.h>

// Define a structure to hold the results
typedef struct {
    int sum;
    int product;
    int difference;
    float quotient;
} Calculations;

// Function prototype
Calculations performCalculations(int a, int b);

int main() {
    int a = 10, b = 5;
    Calculations result;

    // Call the function
    result = performCalculations(a, b);

    // Display the results
    printf("Sum = %d\n", result.sum);
    printf("Product = %d\n", result.product);
    printf("Difference = %d\n", result.difference);
    printf("Quotient = %.2f\n", result.quotient);

    return 0;
}

// Function to perform calculations
Calculations performCalculations(int a, int b) {
    Calculations calc;

    calc.sum = a + b;
    calc.product = a * b;
    calc.difference = a - b;

    if(b != 0) {
        calc.quotient = (float)a / b;
    } else {
        calc.quotient = 0; // Avoid division by zero
    }

    return calc;
}


*/


/*

In this program no pointers had been used: 

Define a Structure: Create a structure that holds all the return values (sum, product, difference, and quotient).

Function Modification: Change the function to return this structure.

Main Program: Call the function and access the results from the returned structure.

A structure Calculations is defined to hold the sum, product, difference, and quotient.

The performCalculations function now returns an instance of Calculations containing the results.

In the main function, we call performCalculations and then access each member of the structure to display the results.

However, it's important to note that with these advantages come certain risks and complexities. Pointers can lead to complex and 
difficult-to-debug issues like memory leaks, dangling pointers, and undefined behavior if not used carefully. 

Therefore, while powerful, pointers require a good understanding and careful handling to be used effectively and safely.

/*

Program Using Pointers:

Memory Efficiency: When dealing with large data, passing pointers to a function is more memory-efficient than passing a whole struct. 

This is because only the address is passed, not the entire data set.

Flexibility in Function Outputs: Pointers allow functions to directly modify the input variables, making it easy to return multiple values. This can be more intuitive when the function needs to update existing variables.

Performance: There's a potential performance benefit in using pointers for large data structures since copying large structures 
(as done when returning a struct) can be more costly in terms of time and memory.

Program Using Struct:
Code Readability and Maintenance: Returning a struct makes the function's purpose and return values clearer. This can improve readability 
and maintainability of the code, as the function signature directly shows what it returns.

Safety and Simplicity: Using structs can be safer, as it avoids common pitfalls with pointers such as dereferencing null 
or invalid pointers. It's also simpler for those less familiar with pointer arithmetic and memory management.

Encapsulation: Structs encapsulate related data, which can make code more organized and coherent. It's easier to manage and pass 
around a single struct rather than multiple separate variables.

Ease of Return Value Management: When a function returns a struct, it's straightforward to manage the return value as a single entity, 
which can simplify function calls and value handling.

Conclusion:

Use Pointers When: You're dealing with large data structures, need to modify existing data directly, or are working in 
memory-constrained environments like embedded systems.

Use Structs When: Code readability, safety, and simplicity are priorities, especially when dealing with complex data 
that logically belongs together.

The choice between using pointers or structs depends on the specific requirements and constraints of your project, 
including performance considerations, memory usage, and code maintainability.

*/




