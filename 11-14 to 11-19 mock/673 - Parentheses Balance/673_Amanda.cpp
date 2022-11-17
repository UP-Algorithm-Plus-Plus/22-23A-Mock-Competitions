/*
*OnlineJudge
*673 - Parentheses Balance
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    getchar(); // remove \n or EOF
    for (int n = 0; n < N; n++) {
        string s;
        getline(cin, s); // getline because we need to know if it's empty

        if (s.empty())
            cout << "Yes" << endl;
        else {
            bool valid = true;
            stack <char> parentheses;
            for (unsigned int i = 0; i < s.size(); i++) {
                if ((s[i] == '(') || (s[i] == '['))
                    parentheses.push(s[i]);
                else {
                    if (parentheses.empty())
                        valid = false;
                    else if ((s[i] == ')') && (parentheses.top() == '('))
                        parentheses.pop();
                    else if ((s[i] == ']') && (parentheses.top() == '['))
                        parentheses.pop();
                    else
                        valid = false;
                }
            }

            if ((parentheses.empty()) && valid)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}