#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> g;
unordered_map<int,bool> visited;

void addEdeges(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void BFS(int src){
     queue<int> q;
     visited[src]=true;
     q.push(src);
     q.push(INT_MAX);
     
  
  while(!q.empty()){
      //this if sec code extra only for to print elements in level order with diffrent line
      if(q.front()==INT_MAX){
          if(q.back()==INT_MAX) break;
          cout<<endl;
          q.pop();
          q.push(INT_MAX);
          continue;
      }
      int frnt=q.front();
      cout<<frnt<<" ";
      q.pop();

      for(int nbr:g[frnt]){
          if(!visited[nbr]){
              q.push(nbr);
              visited[nbr]=true;
          }
      }
  }

}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        addEdeges(a,b);
    }
    BFS(1);
    
}
