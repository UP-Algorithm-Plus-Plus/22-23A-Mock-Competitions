/*
*OnlineJudge
*10344 - 23 Out of 5
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int arr[5];
int is23 (int ctr, int output, int used[5]) {
    if (ctr == 5) {
        if (output == 23)
            return 1;
        return 0;
    }

    int retval = 0;
    if (!ctr) {
        for (int i = 0; i < 5; i++) {
            used[i] = 1;
            retval = max(retval, is23(ctr + 1, arr[i], used));
            used[i] = 0;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            if (used[i] != 1) {
                used[i] = 1;
                retval = max(retval, is23(ctr + 1, output + arr[i], used));
                retval = max(retval, is23(ctr + 1, output - arr[i], used));
                retval = max(retval, is23(ctr + 1, output * arr[i], used));
                used[i] = 0;
            }
        }
    }

    return retval;
}

int main ()
{
    int a, b, c, d, e;
    while (1) {
        cin >> a >> b >> c >> d >> e;
        if (!a && !b && !c && !d && !e) // if all are 0
            break;
        
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        arr[4] = e;

        int used[5] = {0};
        if (is23(0,0,used))
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
    
    return 0;
}
