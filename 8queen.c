#include <stdio.h>
#include <stdbool.h>

#define N 8

int col[N]; // col[i] is the column where the queen in row i is placed

// Returns true if a queen can be placed in row r, column c.
bool is_safe(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (col[i] == c || 
            abs(col[i] - c) == abs(i - r))
            return false;
    }
    return true;
}

// Prints the solution
void print_solution()
{
    static int num_solutions = 0;
    printf("Solution %d:\n", ++num_solutions);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (col[i] == j)
                printf("Q ");
            else
                printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// Solves the 8 Queens problem using recursive backtracking
void solve(int row)
{
    if (row == N)
    {
        print_solution();
        return;
    }

    for (int c = 0; c < N; c++)
    {
        if (is_safe(row, c))
        {
            col[row] = c;
            solve(row + 1);
        }
    }
}

int main(void)
{
    solve(0);
    return 0;
}
