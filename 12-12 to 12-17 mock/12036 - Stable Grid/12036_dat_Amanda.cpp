/*
*OnlineJudge
*12036 - Stable Grid
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "Case " << t+1 << ": ";

        int N;
        cin >> N;
        bool valid = true;
        int numbers[100] = {0};
        for (int n = 0; n < N; n++)
            for (int m = 0; m < N; m++) {
                int x;
                cin >> x;
                numbers[x]++;
                
                if (numbers[x] > N)
                    valid = false;
            }

        if (valid)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}