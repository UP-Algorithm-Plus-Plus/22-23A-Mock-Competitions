/*
*OnlineJudge
*11849 - CD
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// trivia: this took longer than the set solution
// this is because of the high memory
int main ()
{
    int N, M;
    while (1) {
        cin >> N >> M;
        if (!N && !M)
            break;

        bool Jack[1000000000] = {0};
        int ans = 0;
        for (int n = 0; n < N; n++) { // list Jack's CDs
            int CD;
            cin >> CD;
            Jack[CD-1] = true;
        }

        for (int m = 0; m < M; m++) { // check if Jill owns a duplicate
            int CD;
            cin >> CD;
            if (Jack[CD-1])
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}