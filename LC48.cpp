class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix.size(), vector<int>(matrix.size(),0));
        int n= matrix.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v[i][j]= (matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            int start=0, end= n-1;
            while(start<=end){
                swap(v[i][start], v[i][end]);
                start++, end--;
            }
        }

        matrix= v;
    }
};