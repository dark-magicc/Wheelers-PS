// Matrix Addition

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLOUMNS = 3;

void add_matrix(int mat1[ROWS][COLOUMNS], int mat2[ROWS][COLOUMNS], int res_mat[ROWS][COLOUMNS]){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLOUMNS; j++)
        {
            res_mat[i][j] = mat1[i][j] + mat2[i][j];
        }
        
    }
}
void display_matrix(int mat[ROWS][COLOUMNS]){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLOUMNS; j++)
        {
            cout << mat[i][j] << "  ";
        }
        
    }
}

int main() {
    int mat1[ROWS][COLOUMNS] = {
        {1,2,3},
        {4,5,6},
        {-1,-8,-4}
    };

    int mat2[ROWS][COLOUMNS] = {
        {17,22,-3},
        {4,-5,6},
        {-1,-8,-4}
    };

    int res_mat[ROWS][COLOUMNS];

    add_matrix(mat1, mat2, res_mat);
    display_matrix(res_mat);

    return 0;
}