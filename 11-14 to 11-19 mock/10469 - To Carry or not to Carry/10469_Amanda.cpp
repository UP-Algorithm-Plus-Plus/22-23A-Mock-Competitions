/*
*OnlineJudge
*10469 - To Carry or not to Carry
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A, B;
    while (cin >> A >> B) {
        int bits[4][8];
        for (int n = 0; n < 4; n++) // init to zero
            for (int m = 0; m < 8; m++)
                bits[n][m] = 0;

        int n = 0, m = 0;
        while (A) { // get A in bitwise
            int powah = pow(2,(8*n)+(m+1));
            if (A%powah) {
                bits[n][m] = 1;
                A -= (A%powah);
            }
            if (m < 8)
                m++;
            else {
                m = 0;
                n++;
            }
        }
        
        n = 0; m = 0;
        while (B) { // "add" (actually XOR) B
            int powah = pow(2,(8*n)+(m+1));
            if (B%powah) {
                bits[n][m] ^= 1;
                B -= (B%powah);
            }
            if (m < 8)
                m++;
            else {
                m = 0;
                n++;
            }
        }

        int ans = 0;
        n = 0; m = 0;
        for (n = 0; n < 4; n++) { // bit to decimal
            for (m = 0; m < 8; m++) {
                if (bits[n][m] == 1)
                    ans += pow(2,(8*n)+m);
            }
        }

        cout << ans << endl;
    }
    return 0;
}