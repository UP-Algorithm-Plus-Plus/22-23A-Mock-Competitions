/*
*OnlineJudge
*11850 - Alaska
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    while (n) {
        int station;
        priority_queue <int, vector<int>, greater<int>> to;

        for (int i = 0; i < n; i++) {
            cin >> station;
            to.push(station);
        }

        int arrived = 1;
        int prev_station = 0;
        int curr_station = 0;
        while (!to.empty()) {//not empty
            curr_station = to.top();
            to.pop();

            if ((curr_station - prev_station) > 200)
                arrived = 0;

            prev_station = curr_station;
        }

        if (((1422-curr_station)*2) > 200)
            arrived = 0;

        if (arrived)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;

        cin >> n;
    }
    return 0;
}
