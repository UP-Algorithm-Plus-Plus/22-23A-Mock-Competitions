/*
*OnlineJudge
*12640 - Largest Sum Game
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string S;
    while (getline(cin, S)) {
        stringstream ss(S);
        vector <int> X;
        int x;
        while (ss >> x)
            X.push_back(x);
        
        int ans = 0;
        int max_here = 0;
        for (int i = 0; i < (int) X.size(); i++) {
            max_here += X[i];
            if (max_here < 0)
                max_here = 0;
            ans = max(ans, max_here);
        }

        cout << ans << endl;

    }
    return 0;
}