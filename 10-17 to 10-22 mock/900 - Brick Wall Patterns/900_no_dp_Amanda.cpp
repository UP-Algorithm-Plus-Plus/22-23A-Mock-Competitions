/*
*OnlineJudge
*900 - Brick Wall Patterns
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int fib (int f)
{
    if ((f == 0) || (f == 1))
        return 1;
    return fib(f-2) + fib(f-1);
}

int main ()
{
    int N;
    cin >> N;
    while (N) {
        cout << fib(N) << endl;
        cin >> N;
    }
    return 0;
}
