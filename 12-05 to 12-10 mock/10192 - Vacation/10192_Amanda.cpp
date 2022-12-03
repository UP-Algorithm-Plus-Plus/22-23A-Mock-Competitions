/*
*OnlineJudge
*10192 - Vacation
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string A, B;
    int C = 1;
    while (getline(cin,A)) {
        if (A == "#")
            break;

        getline(cin,B);
        
        int m = A.size();
        int n = B.size();

        int LCS[m+1][n+1];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                LCS[i][j] = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }

        printf("Case #%d: you can visit at most %d cities.\n", C++, LCS[m][n]);
    }
    return 0;
}