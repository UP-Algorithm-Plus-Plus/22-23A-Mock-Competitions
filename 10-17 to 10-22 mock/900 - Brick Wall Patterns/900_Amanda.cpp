/*
*OnlineJudge
*900 - Brick Wall Patterns
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int fib[51];
    fib[0] = 1;
    fib[1] = 1;
    for (int f = 2; f < 51; f++)
        fib[f] = fib[f-2] + fib[f-1];

    int N;
    cin >> N;
    while (N) {
        cout << fib[N] << endl;
        cin >> N;
    }
    return 0;
}
