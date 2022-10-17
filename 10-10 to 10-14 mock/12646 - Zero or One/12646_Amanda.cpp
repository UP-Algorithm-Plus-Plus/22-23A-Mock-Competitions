/*
*OnlineJudge
*12646 - Zero or One
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A, B, C;
    while (cin >> A >> B >> C) {
        if ((A == B) && (B == C)) // all same
            cout << '*' << endl;
        else if (A == B)
            cout << 'C' << endl;
        else if (A == C)
            cout << 'B' << endl;
        else if (B == C)
            cout << 'A' << endl;
    }
    return 0;
}
