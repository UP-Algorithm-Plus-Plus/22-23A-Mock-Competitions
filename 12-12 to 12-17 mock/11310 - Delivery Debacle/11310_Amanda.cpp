/*
*OnlineJudge
*11310 - Delivery Debacle
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long pattern[41];
    pattern[0] = 0;
    pattern[1] = 1;
    pattern[2] = 5;
    pattern[3] = 11;
    for (int i = 4; i <= 40; i++)
        pattern[i] = 2*pattern[i-3] + 4*pattern[i-2] + pattern[i-1];

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        cout << pattern[n] << endl;
    }
    return 0;
}