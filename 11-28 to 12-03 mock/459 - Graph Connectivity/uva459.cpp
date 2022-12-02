#include <bits/stdc++.h>

using namespace std;

map <char, char> head;

void connect(string in, char max){
	char x = in[0];
	char y = in[1];

	if(head[y] == head[x])
		return;

	char temp = head[y];
	head[y] = head[x];

	for (int i = 'A'; i <= (int)max; i++){
		char buf = (char) i;
		if (head[buf] == temp){
			head[buf] = head[x];
		}
	}

	return;
}

int main(void){
	int cases;
	char max;
	string edge;

	cin >> cases;
	for (;cases > 0; cases--){
		head.clear();

		cin >> max;
		for (int i = 'A'; i <= (int)max; i++){
			char buf = (char) i;
			head[buf] = buf;
		}

		cin.ignore();
		while(getline(cin, edge)){
			if(edge.empty())
				break;
			connect(edge, max);
		}

		int count = 0;
		for (int i = 'A'; i <= (int)max; i++){
			char buf = (char) i;
			if(head[buf] == buf)
				count++;
		}

		cout << count << endl;
		if (cases > 1)
			cout << endl;
	}
	
	return 0;
}
