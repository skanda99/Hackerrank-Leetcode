
// problem: "https://leetcode.com/problems/spiral-matrix-ii/"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n, vector<int> (n, 0));
        populateMatrix(0, 0, 1, matrix, n, 0);
        return matrix;
    }
    
private:
    void populateMatrix(int i, int j, int num, vector<vector<int>> &matrix, int n, int direction) {
        matrix[i][j] = num;
        
        if (direction == 0 && j+1 < n && matrix[i][j+1] == 0) {
            populateMatrix(i, j+1, num+1, matrix, n, 0);
        } else if (direction == 1 && i+1 < n && matrix[i+1][j] == 0) {
            populateMatrix(i+1, j, num+1, matrix, n, 1);
        } else if (direction == 2 && j-1 >= 0 && matrix[i][j-1] == 0) {
            populateMatrix(i, j-1, num+1, matrix, n, 2);
        } else if (direction == 3 && i-1 >= 0 && matrix[i-1][j] == 0) {
            populateMatrix(i-1, j, num+1, matrix, n, 3);
        }
        
        if (j+1 < n && matrix[i][j+1] == 0) {
            populateMatrix(i, j+1, num+1, matrix, n, 0);
        } else if (i+1 < n && matrix[i+1][j] == 0) {
            populateMatrix(i+1, j, num+1, matrix, n, 1);
        } else if (j-1 >= 0 && matrix[i][j-1] == 0) {
            populateMatrix(i, j-1, num+1, matrix, n, 2);
        } else if (i-1 >= 0 && matrix[i-1][j] == 0) {
            populateMatrix(i-1, j, num+1, matrix, n, 3);
        }
    }
};
