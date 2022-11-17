/*
*OnlineJudge
*10189 - Minesweeper
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int F = 1;
    int N, M;
    while (1) {
        cin >> N >> M;
        if ((N || M) == 0)
            break;

        if (F != 1)
            cout << endl;

        printf("Field #%d:\n", F);
        F++;

        char field[N+2][M+2]; // +2 padding
        for (int n = 0; n <= N+1; n++)
            for (int m = 0; m <= M+1; m++) {
                if ((n == 0) || (m == 0) || (n == N+1) || (m == M+1))
                    field[n][m] = '.';
                else
                    cin >> field[n][m];
            }
            
        for (int n = 1; n <= N; n++) {
            for (int m = 1; m <= M; m++) {
                if (field[n][m] == '*')
                    cout << field[n][m];
                else {
                    int num = 0;
                    for (int i = -1; i <= 1; i++)
                        for (int j = -1; j <= 1; j++)
                            if (field[n+i][m+j] == '*')
                                num++;
                    cout << num;
                }
            }
            cout << endl;
        }
    }
    return 0;
}