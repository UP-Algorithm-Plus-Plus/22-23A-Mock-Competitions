#include <bits/stdc++.h>

using namespace std;


int main(void){
  int T, P, D;
  cin >> T;
  for(; T > 0; T--){
    cin >> P >> D;

    vector<int> giov(P, INT_MAX);
    vector<vector<int> > dance(P);
    int p1, p2;

    for(; D > 0; D--){
      cin >> p1 >> p2;
      dance[p1].push_back(p2);
      dance[p2].push_back(p1);
    }

    queue <int> q;
    giov[0] = 0;
    q.push(0);

    int cur, next;
    while(!q.empty()){
      cur = q.front();
      q.pop();

      for(int i = 0; i < (int)dance[cur].size(); i++){
        next = dance[cur][i];
        if(giov[next] == INT_MAX){
          giov[next] = giov[cur] + 1;
          q.push(next);
        }
      }
    }

    for(int i = 1; i < P; i++)
      printf("%d\n", giov[i]);
    if(T > 1)
      printf("\n");
  }

  return 0;
}
