/*
*OnlineJudge
*12463 - Little Nephew
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e) {
        if (!a && !b && !c && !d && !e)
            break;
        
        cout << a*b*c*d*d*e*e << endl;
    }
    return 0;
}