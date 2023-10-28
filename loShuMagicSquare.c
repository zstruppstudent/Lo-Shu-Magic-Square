#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "loShuMagicSquare.h"

// Function to check if a 2D array is a Lo Shu Magic Square
int isLoShuMagicSquare(int square[SIZE][SIZE]) 
{
    // Calculate the expected sum (the sum of any row, column, or diagonal)
    int expectedSum = (SIZE * SIZE * (SIZE * SIZE + 1)) / 2;

    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < SIZE; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != expectedSum || colSum != expectedSum) {
            return 0; // Not a Lo Shu Magic Square
        }
    }

    // Check diagonals
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        diag1Sum += square[i][i];
        diag2Sum += square[i][SIZE - 1 - i];
    }

    if (diag1Sum != expectedSum || diag2Sum != expectedSum) 
    {
        return 0; // Not a Lo Shu Magic Square
    }

    return 1; // It's a Lo Shu Magic Square
}

int main() 
{
    srand(time(NULL));
    int square[SIZE][SIZE];
    int count = 0;

    do 
    {
        // Create a random arrangement of numbers from 1 to 9
        int numbers[SIZE * SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = SIZE * SIZE - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }

        // Fill the square
        int k = 0;
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                square[i][j] = numbers[k++];
            }
        }

        count++;

    } while (!isLoShuMagicSquare(square));

    // Print the results
    printf("Lo Shu Magic Square found after %d attempts:\n", count);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }

    return 0;
}