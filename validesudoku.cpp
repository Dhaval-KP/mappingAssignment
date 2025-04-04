#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<std::unordered_set<char>> rows(9), cols(9), boxes(9);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];
            if (num == '.') continue;
            
            int boxIndex = (i / 3) * 3 + (j / 3);
            
            if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                return false;
            }
            
            rows[i].insert(num);
            cols[j].insert(num);
            boxes[boxIndex].insert(num);
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(9, std::vector<char>(9));
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> board[i][j];
        }
    }
    
    if (isValidSudoku(board)) {
        std::cout << "The board is valid." << std::endl;
    } else {
        std::cout << "The board is not valid." << std::endl;
    }
    
    return 0;
}