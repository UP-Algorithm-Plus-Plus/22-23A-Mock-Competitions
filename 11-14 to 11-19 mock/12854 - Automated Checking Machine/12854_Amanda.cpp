/*
*OnlineJudge
*12854 - Automated Checking Machine
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A[5], B[5];
    while (cin >> A[0]) { // ugh, so annoying
        for (int i = 1; i < 5; i++)
            cin >> A[i];
        for (int i = 0; i < 5; i++)
            cin >> B[i];

        bool valid = true;
        for (int i = 0; i < 5; i++)
            if (A[i] == B[i])
                valid = false;
        
        if (valid)
            printf("Y\n");
        else
            printf("N\n");
    }   
    return 0;
}