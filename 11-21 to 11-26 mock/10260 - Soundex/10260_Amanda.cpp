/*
*OnlineJudge
*10260 -  Soundex
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int letters[26] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};

    string word;
    while (cin >> word) {
        int prev_soundex = 0;
        int curr_soundex = 0;
        for (int i = 0; i < (int) word.size(); i++) {
            curr_soundex = letters[word[i]-'A'];
            
            if (curr_soundex && (curr_soundex != prev_soundex))
                cout << curr_soundex;

            prev_soundex = curr_soundex;
        }
        cout << endl;
    }
    return 0;
}