#include <bits/stdc++.h>

using namespace std;

// function for getting input
// returns v: a vector of integers from stdin
vector<int> getline_to_vector(void) {
    vector<int> v;
    string inp;
    stringstream take;
    int n;

    if (!getline(cin, inp)) return v;

    take << inp;
    while (take >> n) {
        v.push_back(n);
    }

    return v;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    bool first = true;
    vector<int> v;

    while (true) {

        if (first) {
            first = false;
            v = getline_to_vector();
        }

        if (v.empty()) {
            break;
        }

        int N = v[0];
        v = getline_to_vector();
		
        vector<int> rank(N+1, 0);
        for (int i = 0; i < N; ++i) {
            rank[i+1] = v[i]; // rank of event i+1 is c[i]
        }

        while (true) {
            v = getline_to_vector();
            if (v.size() <= 1) // Next test case or end of input
                break;

			// rank_student[i] = (student's rank of event i, event i)
            vector< pair<int,int> > rank_student(N);
            for (int i = 0; i < N; ++i) {
                rank_student[i] = make_pair(v[i], i+1);
            }

			// sort based on the student's rank of events
            sort(rank_student.begin(), rank_student.end());
            vector<int> memo(v.size());

            // perform LIS on the rank of events
			// i.e. rank[rank_student[i].second]
            int ans = 0;
            for (int i = 0; i < N; ++i) {
                memo[i] = 1;
                for (int j = 0; j < i; ++j) {
					// 
                    if (rank[rank_student[j].second] < rank[rank_student[i].second]) {
                        memo[i] = max(memo[i], memo[j] + 1);
                    }
                }
                ans = max(memo[i], ans);
            }

            cout << ans << endl;
        }


    }

    return 0;
}
