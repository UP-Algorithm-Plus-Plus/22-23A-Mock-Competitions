/*
*OnlineJudge
*272 - TEX Quotes
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    bool first = true;
    char c;
    while (1) {
        c = getchar();
        if (c == EOF)
            break;
        
        if (c == '"') {
            if (first) {
                printf("``");
                first = false;
            } else {
                printf("''");
                first = true;
            }
        } else
            printf("%c", c);
    }
    return 0;
}
