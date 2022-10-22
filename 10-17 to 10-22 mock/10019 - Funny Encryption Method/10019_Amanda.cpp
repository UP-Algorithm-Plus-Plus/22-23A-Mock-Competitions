/*
*OnlineJudge
*10019 - Funny Encryption Method
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int B, B1, B2;
        cin >> B;
        B1 = B;
        B2 = B;

        int powah;
        int b1 = 0;
        for (int i = 1; ;i++) {
            if (B1 == 0)
                break;
            int powah = pow(2,i);
            int mod = B1%powah;
            if (mod) {
                B1 -= (mod);
                b1++;
            }
        }
        
        int b2 = 0;
        while (1) {
            if (B == 0)
                break;
            
            B2 = B%10;
            for (int i = 0; ;i++) {
                if (B2 == 0)
                    break;
                int powah = pow(2,i);
                int mod = B2%powah;
                if (mod) {
                    B2 -= mod;
                    b2++;
                }
            }

            B /= 10;
        }

        cout << b1 << " " << b2 << endl;
    }
    return 0;
}
