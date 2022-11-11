/*
*OnlineJudge
*524 - Prime Ring Problem
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// sieve for primes is unneeded since you can list it
// but this was the cause of my WA hahaha
int prime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0};
int ring[20]; // rounded up to 20 just because

// see those weird output sequence? that's because of PE
void prime_ring (int num, int maxsize, int ringsize, int used[20])
{
    if (ringsize == maxsize) {
        if (prime[1 + ring[ringsize-1]] == 1) {
            cout << endl;
            for (int i = 0; i < maxsize-1; i++)
                cout << ring[i] << " ";
            cout << ring[ringsize-1];
        }
        return;
    }

    for (int i = 2; i <= maxsize; i++) {
        if ((used[i] != 1) && (prime[num + i] == 1)) {
            used[i] = 1;
            ring[ringsize] = i;
            prime_ring(i, maxsize, ringsize+1,used);
            used[i] = 0;
            ring[ringsize] = 0;
        }
    }

    return;
}

int main ()
{
    int case_num = 1;
    int N;
    while (cin >> N) {
        if (case_num != 1)
            cout << endl;

        cout << "Case " << case_num << ":";
        case_num++;

        int used[20] = {0};
        used[1] = 1;
        ring[0] = 1;

        prime_ring(1, N, 1, used);
        cout << endl;
    }
    
    return 0;
}
