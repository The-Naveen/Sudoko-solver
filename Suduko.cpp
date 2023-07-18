#include <bits/stdc++.h>
using namespace std;

#define empty 0
#define N 9

class Sudoku{
    public:
        bool Empty(int A[N][N]){
            for (int row = 0; row < N; row++)
                for (int col = 0; col < N; col++)
                    if (A[row][col] == empty)
                        return true;
            return false;
        }

        bool RowUsage(int A[N][N], int rp, int number){
            for (int col = 0; col < N; col++)
                if (A[rp][col] == number)
                    return true;
            return false;
        }

        bool ColumnUsage(int A[N][N], int cp, int number){
            for (int row = 0; row < N; row++)
                if (A[row][cp] == number)
                    return true;
            return false;
        }

        bool BoxUsage(int A[N][N], int boxBeginRow, int boxBeginCol, int number){
            bool tf = false;
            for (int row = 0; row < 3; row++)
                for (int col = 0; col < 3; col++)
                    if (A[row + boxBeginRow][col + boxBeginCol] == number)
                        tf = true;
            return tf;
        }

        bool Check(int A[N][N], int rp, int cp, int number){
            return !RowUsage(A, rp, number) && !ColumnUsage(A, cp, number) &&
                !BoxUsage(A, rp - rp % 3, cp - cp % 3, number);
        }

        bool SolveSudoku(int A[N][N]){
            int row, col;
            if (!Empty(A))
                return true;
            for (int num = 1; num <= 9; num++){
                if (Check(A, row, col, num)){
                    A[row][col] = num;
                    if (SolveSudoku(A))
                        return true;
                    A[row][col] = empty;
                }
            }
            return false;
        }

        void printResult(int A[N][N]){
            for (int row = 0; row < N; row++){
                for (int col = 0; col < N; col++)
                    cout << A[row][col] << "  ";
                cout << endl;
            }
        }
};





int main(){
    cout << "SUDOKO CHALLENGE" << endl;
    cout << "Enter Unsolved Sudoko with empty spaces as 'ZERO':" << endl;

    int A[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> A[i][j];
    }

    Sudoku Quest;

    if (Quest.SolveSudoku(A))
        Quest.printResult(A);
    else
        cout << "No solution found" << endl;
    return 0;
}