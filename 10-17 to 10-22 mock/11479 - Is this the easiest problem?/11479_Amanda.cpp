/*
*OnlineJudge
*11479 - Is this the easiest problem?
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";

        long long A, B, C;
        cin >> A >> B >> C;

        if ((A && B && C) == 0)
            cout << "Invalid" << endl;
        else {
            if (((A + B) > C) && ((A + C) > B) && ((B + C) > A)) { // triangle rule
                if ((A == B) && (B == C))
                    cout << "Equilateral" << endl;
                else if ((A == B) || (A == C) || (B == C))
                    cout << "Isosceles" << endl;
                else
                    cout << "Scalene" << endl;
            }
            else
                cout << "Invalid" << endl;
        }
    }
    return 0;
}
