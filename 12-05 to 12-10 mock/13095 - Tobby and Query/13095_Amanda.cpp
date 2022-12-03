/*
*OnlineJudge
*13095 - Tobby and Query
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (cin >> N) {
        N++;
        int arr[N];
        
        int nums[10][N];
        // initialize 10x10 encoding matrix
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < N; j++)
                nums[i][j] = 0;

        for (int n = 1; n < N; n++) {
            cin >> arr[n];
            for (int i = 0; i < 10; i++) {
                if (i == arr[n])
                    nums[i][n] = nums[i][n-1] + 1;
                else
                    nums[i][n] = nums[i][n-1];
            }
        }
        
        int Q;
        cin >> Q;
        
        int start, end;
        for (int q = 0; q < Q; q++) {
            cin >> start >> end;
            int ans = 0;
            for (int i = 0; i < 10; i++) {
                if ((nums[i][end]-nums[i][start-1]) > 0)
                    ans++;
            }
            cout << ans << endl;
        }
        
    }
    return 0;
}