#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ret(m,vector<int>(n,0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> pos = {i,j}
            for (int t = 0; t < k; t++) {
                pos = getnextpos(pos,m,n);
            }
            ret[i][j] = matrix[pos[0]][pos[1]];
        }
    }
    return ret;
}

vector<int> getnextpos(vector<int> pos, int m, int n) {
    int x = pos[0];
    int y = pos[1];
    int tot = x;
    int tob = m - 1 - x;
    int tol = y;
    int tor = n - 1 - y;
    if (tot == tob) {
        if (tol < tot) {
            return {x + 1, y};
        } else if (tor < tot) {
            return {x - 1, y};
        } else {
            return {x , y};
        }
    }
    if (tol == tor) {
        if (tot < tol) {
            return {x, y - 1};
        } else if (tob <tol) {
            return {x, y + 1};
        } else {
            return {x, y};
        }
    }
    if (tot > tob) {//靠下
        if (tol > tor) {//靠右
            if (tob >= tor) {//更右
                return {x - 1, y};
            } else {//更下
                return {x, y + 1};
            }
        } else {//靠左
            if (tob > tol) {//更左
                return {x + 1, y};
            } else {//更下
                return {x, y + 1};
            }
        }
    } else {//靠上
        if (tol > tor) {//靠右
            if (tot > tor) {//更右
                return {x - 1, y};
            } else {//更上
                return {x, y - 1};
            }
        } else {//靠左
            if (tot >= tol) {//更左
                return {x + 1, y};
            } else {//更上
                return {x, y - 1};
            } 
        }      
    }
}



void display(vector<vector<int>> prt) {
    for (int i = 0; i < prt.size(); i++) {
        for (int j = 0; j < prt[0].size(); j++) {
            cout << prt[i][j] ;
        }
        cout << endl;
    }
}

int main () {
    vector<vector<int>> input = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0},
        {3, 7, 8, 4, 6}
    }
    display(rotate(input,1));
    system("pause");
}