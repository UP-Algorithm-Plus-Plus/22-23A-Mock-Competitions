#include <bits/stdc++.h>

using namespace std;

int counter;
int n;
vector<int> dist;

void trav(vector<vector<int> > par, int start){
  queue<int> q;
  dist.clear();

  dist.resize(n + 1, INT_MAX);
  //q.push(start);
  //dist[start] = 0;
  for(int i = 0; i <(int)par[start].size();i++){
    q.push(par[start][i]);
    dist[par[start][i]] = 0;
  }

  int cur;
  while(!q.empty()){
    cur = q.front();
    q.pop();
    counter++;

    for(int i = 0; i < (int)par[cur].size(); i++){
      if(dist[par[cur][i]] == INT_MAX){
        dist[par[cur][i]] = dist[cur] + 1;
        q.push(par[cur][i]);
      }
    }
  }

  return;
}

int main(void){
  while(cin >> n){
    if(n == 0)
      break;

    vector<vector<int> > par(n + 1);
    int buf, node;
    while(cin >> node){
      if(node == 0)
        break;
      while(cin >> buf){
        if(buf == 0)
          break;
        par[node].push_back(buf);
      }
    }

    int how, num;
    cin >> how;
    for(; how > 0; how--){
      cin >> num;
      counter = 0;
      trav(par, num);
      printf("%d", n - counter);
      for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX)
          printf(" %d", i);
      }
      printf("\n");
    }
  }

  return 0;
}
