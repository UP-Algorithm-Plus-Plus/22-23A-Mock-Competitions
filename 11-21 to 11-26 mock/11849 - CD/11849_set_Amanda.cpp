/*
*OnlineJudge
*11849 - CD
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N, M;
    while (1) {
        cin >> N >> M;
        if (!N && !M)
            break;

        unordered_set <int> Jack;
        int ans = 0;
        for (int n = 0; n < N; n++) { // list Jack's CDs
            int CD;
            cin >> CD;
            Jack.insert(CD);
        }

        for (int m = 0; m < M; m++) { // check if Jill owns a duplicate
            int CD;
            cin >> CD;
            if (Jack.find(CD) != Jack.end())
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}