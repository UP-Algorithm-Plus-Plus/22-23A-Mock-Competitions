/*
*OnlineJudge
*12626 - I Love Pizza
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        string pizza;
        cin >> pizza;

        int letters[26] = {0};
        for (int i = 0; i < (int) pizza.size(); i++)
            letters[pizza[i] - 'A']++;

        int margletters[26] = {0};
        string margarita = "MARGARITA";
        for (int i = 0; i < (int) margarita.size(); i++)
            margletters[margarita[i] - 'A']++;

        int ans = letters['M'-'A']/margletters['M'-'A'];
        for (int i = 0; i < (int) margarita.size(); i++)
            ans = min(ans, letters[margarita[i] - 'A']/margletters[margarita[i] - 'A']);

        cout << ans << endl;
    }
    return 0;
}