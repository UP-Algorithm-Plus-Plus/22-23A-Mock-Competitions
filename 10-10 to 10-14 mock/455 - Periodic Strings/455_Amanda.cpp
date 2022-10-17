/*
*OnlineJudge
*455 Periodic Strings
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    string str;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;

        int len = str.size();
        int period = 0;

        string sub, rep;
        for (int j = 1; j <= str.size(); j++) {
            if (str.size()%j == 0) { // divisible
                sub = str.substr(0,j);
                rep = "";
                for (int k = 0; k < len/j; k++) {
                    rep += sub;
                }

                if (rep == str) {
                    period = j;
                    break;
                }
            }
        }
        
        cout << period << endl;

        if (i < N-1)
            cout << endl;

    }
    return 0;
}
