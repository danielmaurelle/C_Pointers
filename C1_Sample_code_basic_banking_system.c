/*
 * @Author: Daniel Maurelle 
 * @Email: daniel.maurelle@gmail.com
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

int varMyvar = 10;

int main() {
    int accountBalance = 1000; // Initial balance in the account
    int *balancePtr = &accountBalance; // Pointer to the account balance
    int transactionAmount; // Amount for deposit or withdrawal
    int transactionType; // 1 for deposit, 2 for withdrawal

    printf("Welcome to the Simple Banking System\n");
    printf("Initial Account Balance: $%d\n", accountBalance);
    
    // Ask the user for the transaction type
    printf("Choose transaction type (1 for Deposit, 2 for Withdrawal): ");

    scanf("%d", &transactionType);

    // Ask for the amount
    printf("Enter the amount: $");
    scanf("%d", &transactionAmount);

    if (transactionType == 1) { // Deposit
        printf("Depositing $%d to account...\n", transactionAmount);
        *balancePtr += transactionAmount;
        printf("Account Balance after deposit: $%d\n", accountBalance);
    } else if (transactionType == 2) { // Withdrawal
        printf("Withdrawing $%d from account...\n", transactionAmount);
        if (*balancePtr >= transactionAmount) {
            *balancePtr -= transactionAmount;
            printf("Account Balance after withdrawal: $%d\n", accountBalance);
        } else {
            printf("Insufficient funds for withdrawal. Current Balance: $%d\n", accountBalance);
        }
    } else { // Invalid transaction type
        printf("Invalid transaction type selected.\n");
    }

    return 0;
}
