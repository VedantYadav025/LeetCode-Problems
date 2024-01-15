class Solution {
private:
void make_row_zero(vector<vector<int>>& matrix, int row){
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < n; i++){
        matrix[row][i] = 0; 
    }
    return;
}

void make_column_zero(vector<vector<int>>& matrix, int column){
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++){
        matrix[i][column] = 0; 
    }
    return;
}

public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> og_zeros;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0)og_zeros.push(make_pair(i, j));
            }
        }
        cout << matrix[0][0] << endl;
        cout << og_zeros.front().first << " " << og_zeros.front().second << endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0 && og_zeros.front() == make_pair(i,j)){
                    cout << i << " " << j << endl;
                    // make row zero
                    make_row_zero(matrix, i);
                    // make column zero
                    make_column_zero(matrix, j);
                    og_zeros.pop();
                }
            }
        }
        return;
    }
};
