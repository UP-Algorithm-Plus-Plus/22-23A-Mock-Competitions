/*
*OnlineJudge
*10050 - Hartals
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T, N, P;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cin >> P;
        
        int hartalsparty[3651] = {0};
        int hartals = 0;
        int hp;

        // pwedeng through LCM keme, pero hassle

        for (int j = 0; j < P; j++) {
            cin >> hp;
             for (int k = hp; k <= N; k += hp) {
                if ((hartalsparty[k] == 0) && (k%7 != 0) && (k%7 != 6)) {
                    hartalsparty[k] = 1;
                    hartals++;
                }
            }
        }

        cout << hartals << endl;
    }

    return 0;
}
