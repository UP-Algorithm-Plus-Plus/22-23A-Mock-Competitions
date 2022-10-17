/*
*OnlineJudge
*10193 - All You Need Is Love
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        string S1, S2;
        cin >> S1 >> S2;
        
        int b1 = 0;
        int b2 = 0;
        // convert to decimal
        for (int i = 0; i < S1.size(); i++) {
            if (S1[i] == '1') {
                b1 += (pow(2,S1.size() - i - 1));
            }
        }
        for (int i = 0; i < S2.size(); i++) {
            if (S2[i] == '1')
                b2 += (pow(2,S2.size() - i - 1));
        }

        if (__gcd(b1,b2) > 1) // gcd = 1 if no gcd
            cout << "Pair #" << n+1 << ": All you need is love!" << endl;
        else
            cout << "Pair #" << n+1 << ": Love is not all you need!" << endl;

    }
    return 0;
}
