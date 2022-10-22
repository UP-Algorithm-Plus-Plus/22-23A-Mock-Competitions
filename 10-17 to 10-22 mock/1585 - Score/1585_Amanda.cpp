/*
*OnlineJudge
*1585 - Score
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string str;
        cin >> str;

        int score = 0;
        int increment = 1;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'O') {
                score += increment;
                increment++;
            } else
                increment = 1;
        }

        cout << score << endl;
    }
    return 0;
}
