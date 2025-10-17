#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

// Count visible boxes from left to right in a line
int count_visible(int line[SIZE]) {
    int count = 0;
    int max_height = 0;
    for (int i = 0; i < SIZE; i++) {
        if (line[i] > max_height) {
            count++;
            max_height = line[i];
        }
    }
    return count;
}

// Check if placing num at (row, col) is valid
bool is_valid_placement(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if number already exists in row
    for (int c = 0; c < SIZE; c++) {
        if (grid[row][c] == num) {
            return false;
        }
    }
    
    // Check if number already exists in column
    for (int r = 0; r < SIZE; r++) {
        if (grid[r][col] == num) {
            return false;
        }
    }
    
    return true;
}

// Check if a complete line satisfies the visibility clues
bool check_line_clues(int line[SIZE], int left_clue, int right_clue) {
    // Check if line is complete
    for (int i = 0; i < SIZE; i++) {
        if (line[i] == 0) {
            return true; // Line not complete, assume valid
        }
    }
    
    // Check left view
    if (left_clue != 0 && count_visible(line) != left_clue) {
        return false;
    }
    
    // Check right view (reverse)
    if (right_clue != 0) {
        int reversed[SIZE];
        for (int i = 0; i < SIZE; i++) {
            reversed[i] = line[SIZE - 1 - i];
        }
        if (count_visible(reversed) != right_clue) {
            return false;
        }
    }
    
    return true;
}

// Check if current partial solution is still promising
bool is_promising(int grid[SIZE][SIZE], int top[SIZE], int right[SIZE], 
                  int bottom[SIZE], int left[SIZE]) {
    // Check each row
    for (int r = 0; r < SIZE; r++) {
        if (!check_line_clues(grid[r], left[r], right[r])) {
            return false;
        }
    }
    
    // Check each column
    for (int c = 0; c < SIZE; c++) {
        int col[SIZE];
        for (int r = 0; r < SIZE; r++) {
            col[r] = grid[r][c];
        }
        if (!check_line_clues(col, top[c], bottom[c])) {
            return false;
        }
    }
    
    return true;
}

// Solve the skyscraper puzzle using backtracking
bool solve_skyscraper(int grid[SIZE][SIZE], int top[SIZE], int right[SIZE],
                      int bottom[SIZE], int left[SIZE], int pos) {
    if (pos == SIZE * SIZE) {
        return is_promising(grid, top, right, bottom, left);
    }
    
    int row = pos / SIZE;
    int col = pos % SIZE;
    
    for (int num = 1; num <= SIZE; num++) {
        if (is_valid_placement(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (is_promising(grid, top, right, bottom, left)) {
                if (solve_skyscraper(grid, top, right, bottom, left, pos + 1)) {
                    return true;
                }
            }
            
            grid[row][col] = 0;
        }
    }
    
    return false;
}

// Print the grid
void print_grid(int grid[SIZE][SIZE]) {
    printf("\nSolution:\n");
    printf("  ");
    for (int i = 1; i <= SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int r = 0; r < SIZE; r++) {
        printf("%d ", r + 1);
        for (int c = 0; c < SIZE; c++) {
            if (grid[r][c] == 0) {
                printf(". ");
            } else {
                printf("%d ", grid[r][c]);
            }
        }
        printf("\n");
    }
}

// Solve a puzzle with given clues
bool solve_puzzle(int top[SIZE], int right[SIZE], int bottom[SIZE], int left[SIZE]) {
    int grid[SIZE][SIZE] = {0};
    
    printf("Solving puzzle with clues:\n");
    printf("Top:    ");
    for (int i = 0; i < SIZE; i++) printf("%d ", top[i]);
    printf("\nRight:  ");
    for (int i = 0; i < SIZE; i++) printf("%d ", right[i]);
    printf("\nBottom: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", bottom[i]);
    printf("\nLeft:   ");
    for (int i = 0; i < SIZE; i++) printf("%d ", left[i]);
    printf("\n");
    
    if (solve_skyscraper(grid, top, right, bottom, left, 0)) {
        print_grid(grid);
        return true;
    } else {
        printf("\nNo solution found!\n");
        return false;
    }
}

int main() {
    // Example 1: Easy puzzle
    printf("========================================\n");
    printf("Example 1: Easy Puzzle\n");
    printf("========================================\n");
    int top1[] = {4, 3, 2, 1};
    int right1[] = {1, 2, 3, 4};
    int bottom1[] = {1, 2, 3, 4};
    int left1[] = {4, 3, 2, 1};
    solve_puzzle(top1, right1, bottom1, left1);
    
    return 0;
}
