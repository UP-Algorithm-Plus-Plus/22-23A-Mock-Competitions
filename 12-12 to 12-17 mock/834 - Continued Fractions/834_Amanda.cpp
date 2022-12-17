/*
*OnlineJudge
*834 - Continued Fractions
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int numerator, denominator;
    while (cin >> numerator >> denominator) {
        cout << '[';
        
        cout << numerator/denominator << ';';

        numerator = numerator%denominator;
        swap(numerator,denominator);

        bool first = true;
        while (numerator > denominator) {
            if (first)
                first = false;
            else
                cout << ',';
                
            cout << numerator/denominator;   
                   
            numerator = numerator%denominator;
            swap(numerator,denominator);

            if (numerator == 1)
                break;
        }

        cout << ']' << endl;
    }
    return 0;
}
