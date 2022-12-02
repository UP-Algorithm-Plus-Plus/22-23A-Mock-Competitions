#include <bits/stdc++.h>

using namespace std;

void connect(int head[], int i, int j, int n){
	if(head[i] == head[j])
		return;

	int buf = head[i];
	head[i] = head[j];

	for (int k = 0; k <= n; k++){
		if(head[k] == buf)
			head[k] = head[j];
	}

	return;
}

int main(void){
	int n, m, cases = 1;

	while(cin >> n >> m){
		if(!n && !m)
			break;

		int i, j;
		int head[n + 1];

		for(int k = 0; k <= n; k++)
			head[k] = k;

		for(int k = 0; k < m; k++){
			cin >> i >> j;

			connect(head, i, j, n);
		}

		set <int> reli;
		for(int k = 1; k <= n; k++)
			reli.insert(head[k]);

		cout << "Case " << cases << ": " << reli.size() << endl;
		cases++;
	}

	return 0;
}
