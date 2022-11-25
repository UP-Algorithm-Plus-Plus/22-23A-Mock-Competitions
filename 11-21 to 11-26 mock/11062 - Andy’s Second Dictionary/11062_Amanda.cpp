/*
*OnlineJudge
*11062 - Andy’s Second Dictionary
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    set <string> dictionary;
    char c;
    string word;
    while (1) {
        c = getchar();
        if (c == EOF) {
            if (!word.empty()) {
                dictionary.insert(word);
                word.clear();
            }
            break;
        }

        if (c == '\n') {
            if (word.back() == '-')
                word.pop_back();
            else if (!word.empty()) {
                dictionary.insert(word);
                word.clear();
            }
            continue;
        }

        if ((c != '-') && !isalpha(c)) {
            if (!word.empty()) {
                dictionary.insert(word);
                word.clear();
            }
            continue;
        }
        
        word.push_back(tolower(c)); // tolower is only for alpha char
    }

    for (auto& it : dictionary)
        cout << it << endl;
    return 0;
}