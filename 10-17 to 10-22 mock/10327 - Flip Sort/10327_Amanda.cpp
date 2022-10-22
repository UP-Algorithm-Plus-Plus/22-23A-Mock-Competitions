/*
*OnlineJudge
*10327 - Flip Sort
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (cin >> N) {
        int sort_me[N];

        for (int n = 0; n < N; n++)
            cin >> sort_me[n];
        
        int ans = 0;
        while (1) {
            int idx = 0;
            int swapped = 0;
            while (idx < (N-1)) {
                if (sort_me[idx] > sort_me[idx+1]) {
                    swap(sort_me[idx], sort_me[idx+1]);
                    swapped = 1;
                    ans++;
                } else
                    idx++;
            }
            if (swapped == 0)
                break;
        }

        cout << "Minimum exchange operations : " << ans << endl;
    }
    return 0;
}
