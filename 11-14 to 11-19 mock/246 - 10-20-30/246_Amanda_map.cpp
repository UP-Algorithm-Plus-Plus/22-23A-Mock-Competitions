/*
*OnlineJudge
*246 - 10-20-30
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// note: slow runtime
int main ()
{
    while (1) {
        queue <int> deck;
        int card;
        for (int i = 0; i < 52; i++) {
            cin >> card;
            if (!card)
                break;
            deck.push(card);
        }
        if (!card)
            break;

        int ans = 0;
        vector <deque <int>> pile (7);
                      
        // initialize piles
        for (int i = 0; i < 7; i++) {
            card = deck.front();
            deck.pop();
            pile[i].push_back(card);
            ans++;
        }

        int skipped = 0;
        map <vector <deque <int>>, queue <int>> oldpile;
        int same = 0;
        while (1) {
            skipped = 0;
            same = 0;
            for (int i = 0; i < 7; i++) {
                if (pile[i].empty())
                    skipped++;
                else {
                    if (deck.empty())
                        break;
                        
                    card = deck.front();
                    deck.pop();
                    pile[i].push_back(card);

                    auto it = oldpile.find(pile);
                    if (it != oldpile.end()) {
                        if (oldpile[pile] == deck) {
                            same = 1;
                            break;
                        }
                    } else
                        oldpile[pile] = deck;
                    
                    ans++;

                    while (pile[i].size() >= 3) {
                        int a, b, c;
                        
                        // case 1: first two, last one
                        // get cards
                        a = pile[i].front();
                        b = pile[i][1];
                        c = pile[i].back();
                        
                        // check cards
                        if ((a + b + c)%10 == 0) { // max sum is 30
                            deck.push(a);
                            deck.push(b);
                            deck.push(c);
                            pile[i].pop_front();
                            pile[i].pop_front();
                            pile[i].pop_back();
                            continue;
                        }

                        // case 2: first one, last two
                        // get cards
                        c = pile[i].back();
                        b = pile[i][pile[i].size() -2];
                        a = pile[i].front();

                        // check cards
                        if ((a + b + c)%10 == 0) { // max sum is 30
                            deck.push(a);
                            deck.push(b);
                            deck.push(c);
                            pile[i].pop_front();
                            pile[i].pop_back();
                            pile[i].pop_back();
                            continue;
                        }

                        // case 3: last three
                        // get cards
                        c = pile[i].back();
                        b = pile[i][pile[i].size() - 2];
                        a = pile[i][pile[i].size() - 3];

                        // check cards
                        if ((a + b + c)%10 == 0) { // max sum is 30
                            deck.push(a);
                            deck.push(b);
                            deck.push(c);
                            pile[i].pop_back();
                            pile[i].pop_back();
                            pile[i].pop_back();
                            continue;
                        }

                        break;
                    }
                }

            }

            if (skipped == 7)
                break;

            if (deck.empty())
                break;
                  
            if (same)
                break;
        }

        if (skipped == 7)
            cout << "Win : " << ans << endl;
        else if (deck.empty())
            cout << "Loss: " << ans << endl;
        else if (same)
            cout << "Draw: " << ans << endl;
    }
    return 0;
}