/*
*OnlineJudge
*160 - Factors and Factorials
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    // sieve for primes
    int is_prime[101] = {0};
    vector <int> primes;
    for (int i = 2; i <= 100; i++) {
        if (is_prime[i] == 0) {
            is_prime[i] = 1;
            primes.push_back(i);

            for (int j = i; j <= 100; j += i) {
                is_prime[j] = -1;
            }
        }
    }

    int N;
    while (1) {
        cin >> N;
        if (!N)
            break;
        
        cout << setw(3) << N << "! =";

        int prime_fac[101] = {0};
        int highest_prime = 0;
        for (int i = 2; i <= N; i++) {
            int I = i;
            while (I > 1) {
                for (int j = 0; j < primes.size(); j++) {
                    if (primes[j] > I)
                        break;
                    while ((I%primes[j] == 0) && (I > 1)) {
                        prime_fac[primes[j]]++;
                        I /= primes[j];
                        highest_prime = max(highest_prime, primes[j]);
                    }
                }
            }
        }

        int printed = 0;
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > highest_prime)
                break;
            if (printed < 15) {
                cout << setw(3) << prime_fac[primes[i]];
                printed++;
            } else {
                cout << endl;
                cout << setw(9) << prime_fac[primes[i]];
                printed = 0;
            }
        }

        cout << endl;
    }

    return 0;
}
