/*
*OnlineJudge
*10935 - Throwing cards away I
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (1) {
        cin >> N;
        if (!N)
            break;
        
        queue <int> deck;
        for (int n = 1; n <= N; n++)
            deck.push(n);
        
        bool first = true;
        cout << "Discarded cards:";
        while (deck.size() > 1) {
            if (first)
                first = false;
            else
                cout << ",";
            cout << " ";

            cout << deck.front();
            deck.pop();

            int move = deck.front();
            deck.pop();
            deck.push(move);
        }

        cout << endl;
        cout << "Remaining card: " << deck.front() << endl;
    }
    return 0;
}