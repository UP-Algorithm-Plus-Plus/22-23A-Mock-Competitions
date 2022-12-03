/*
*OnlineJudge
*10684 - The jackpot
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (1) {
        cin >> N;
        if (!N)
            break;
            
        int arr[N];
        for (int n = 0; n < N; n++) {
            cin >> arr[n];
        }

        int max_here = 0;
        int ans = 0;
        for (int n = 0; n < N; n++) {
            max_here += arr[n];
            if (max_here < 0)
                max_here = 0;
            ans = max(ans, max_here);
        }

        if (ans > 0)
            cout << "The maximum winning streak is " << ans << "." << endl;
        else
            cout << "Losing streak." << endl;
    }
    return 0;
}