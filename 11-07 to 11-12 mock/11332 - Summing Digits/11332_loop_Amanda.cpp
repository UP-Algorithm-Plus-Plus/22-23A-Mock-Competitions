/*
*OnlineJudge
*11332 - Summing Digits
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (1) {
        cin >> N;
        if (!N)
            break;
        
        while (N >= 10) {
            int sum = 0;
            while (N) {
                sum += (N%10);
                N /= 10;
            }
            N = sum;
        }

        cout << N << endl;
    }
    return 0;
}
