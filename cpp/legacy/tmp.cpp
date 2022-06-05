class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int x = 0, y = 0;
        while (y < col) {
            if (matrix[0][y] == target) {
                return true;
            } else if (matrix[0][y] > target) {
                break;
            } else {
                y++;
            }
        }
        while (x >= 0 && x < row && y >=0 && y < col) {
            if (matrix[x][y] > target) {
                y--;
            } else if (matrix[x][y] < target) {
                x++;
            } else {
                return true;
            }
        }
        return false;
    }
};

[
[1,4,7,11,15],
[2,5,8,12,19],
[3,6,9,16,22],
[10,13,14,17,24],
[18,21,23,26,30]
]
5