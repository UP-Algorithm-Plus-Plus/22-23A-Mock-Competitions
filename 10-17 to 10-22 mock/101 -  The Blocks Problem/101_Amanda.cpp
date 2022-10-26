/*
*OnlineJudge
*101 - The Blocks Problem
*Code by: Amanda Lim
*/

/*
Note:
Yes, the removal of blocks could've been a function,
I just ended up copy-pasting it
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    int spaces[25][25]; // 25 max blocks
    int where[25];      // where the blocks are
    int pile[25];       // how many blocks are in every space
    
    // init arrays
    for (int i = 0; i < 25; i++)
        spaces[i][0] =  i;
    for (int i = 0; i < 25; i++)
        where[i] = i;
    for (int i = 0; i < 25; i++)
        pile[i] = 1;

    string cmd1, cmd2;
    int A, B;
    while (1) {
        cin >> cmd1;
        if (cmd1 == "quit")
            break;
        
        cin >> A >> cmd2 >> B;
        
        if ((where[A] == where[B]) || (A == B)) // invalid cmd
            continue;

        if (cmd1 == "move") {
            // already checked no move cases above, so sure move
            if (cmd2 == "onto") {      
                int prevblock = -1;
                int topblock = -1;
                while (1) { // return blocks on top of B
                    prevblock = topblock;
                    topblock = spaces[where[B]][pile[where[B]]-1];
                    if (topblock == B) // don't move B
                        break;
                    
                    spaces[where[B]][pile[where[B]]-1] = 0;
                    pile[where[B]]--;
                    spaces[topblock][pile[topblock]] = topblock;
                    pile[topblock]++;
                    where[topblock] = topblock;
                }
            }

            int prevblock = -1;
            int topblock = -1;
            while (1) { // return blocks on top of A
                prevblock = topblock;
                topblock = spaces[where[A]][pile[where[A]]-1];
                if (topblock == A) // don't move A (yet)
                    break;
                
                spaces[where[A]][pile[where[A]]-1] = 0;
                pile[where[A]]--;
                spaces[topblock][pile[topblock]] = topblock;
                pile[topblock]++;
                where[topblock] = topblock;
            }

            // actual moving
            spaces[where[A]][pile[where[A]]-1] = 0;
            pile[where[A]]--;
            spaces[where[B]][pile[where[B]]] = A;
            pile[where[B]]++;
            where[A] = where[B];
        }

        if (cmd1 == "pile") {
            stack <int> to_move;
            int prevblock = -1;
            int topblock = -1;
            while (1) {
                prevblock = topblock;
                if (prevblock == A) // moved A into stack
                    break;
                topblock = spaces[where[A]][pile[where[A]]-1];
                to_move.push(topblock);

                spaces[where[A]][pile[where[A]]-1] = 0;
                pile[where[A]]--;
                where[topblock] = -1; // not in any space
            }

            if (cmd2 == "onto") {   
                int prevblock = -1;
                int topblock = -1;
                while (1) { // return blocks on top of B
                    prevblock = topblock;
                    topblock = spaces[where[B]][pile[where[B]]-1];
                    if (topblock == B) // don't move B
                        break;
                    
                    spaces[where[B]][pile[where[B]]-1] = 0;
                    pile[where[B]]--;
                    spaces[topblock][pile[topblock]] = topblock;
                    pile[topblock]++;
                    where[topblock] = topblock;
                }
            }

            while (!to_move.empty()) {
                topblock = to_move.top();
                to_move.pop();

                spaces[where[B]][pile[where[B]]] = topblock;
                pile[where[B]]++;
                where[topblock] = where[B];
            }
        }
    }

    for (int n = 0; n < N; n++) {
        cout << n << ":";
        for (int m = 0; m < pile[n]; m++) {
            cout << " " << spaces[n][m];
        }
        cout << endl;
    }

    return 0;
}
