/*
*OnlineJudge
*13034 - Solve Everything :-)
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int S;
    cin >> S;
    for (int s = 1; s <= S; s++) {
        cout << "Set #" << s << ": ";
        int yes = 1;
        int temp;
        for (int i = 0; i < 13; i++) {
            cin >> temp;
            if (!temp)
                yes = 0;
        }

        if (yes)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
