/*
*OnlineJudge
*11917 - Do Your Own Homework!
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

        unordered_map <string, int> commission;
        for (int n = 0; n < N; n++) {
            string subject;
            int days;
            cin >> subject >> days;
            commission[subject] = days;
        }

        int D;
        cin >> D;

        string subject;
        cin >> subject;

        if ((commission.find(subject) == commission.end()) || (commission[subject] > (D + 5)))
            cout << "Do your own homework!" << endl;
        else if (commission[subject] > D)
            cout << "Late" << endl;
        else
            cout << "Yesss" << endl;
    }
    return 0;
}