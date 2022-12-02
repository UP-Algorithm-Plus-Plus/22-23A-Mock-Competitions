#include <bits/stdc++.h>

using namespace std;

map <char, vector<char> > connect;
map <char, int> dist;

void bfs(){
  dist.clear();
  queue <char> q;
  q.push('*');
  dist['*'] = 0;

  char curr_node, next_node;
  while(!q.empty()){
    curr_node = q.front();
    q.pop();

    for(int i = 0; i < (int)connect[curr_node].size(); i++){
      next_node = connect[curr_node][i];

      if(!dist.count(next_node)){
        dist[next_node] = dist[curr_node] + 1;
        q.push(next_node);
      }
    }
  }

  return;
}

int main(void){
  int N;

  while(cin >> N){
    char planet[N];
    string temp;
    double value[N];
    connect.clear();

    for(int i = 0; i < N ; i++){
      cin >> planet[i] >> value[i] >> temp;

      for(int j = 0; j < (int)temp.size();j++){
        connect[planet[i]].push_back(temp[j]);
        connect[temp[j]].push_back(planet[i]);
      }
    }

    bfs();

    double most = 0;
    int choose = -1;
    for(int i = 0; i < N; i++){
      if(!dist.count(planet[i]))
        continue;
      int distance = dist[planet[i]];
      double curr_val = value[i];

      for(int j = 1; j < distance; j++){
        curr_val = curr_val - (curr_val*0.05);
      }

      if(most < curr_val){
        choose = i;
        most = curr_val;
      }else if (most == curr_val){
        if(planet[choose] > planet[i])
          choose = i;
      }
    }
    printf("Import from %c\n", planet[choose]);
  }

  return 0;
}
