#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> g;
unordered_map<int,int> dist;

void addEdeges(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void BFS(int src){
     
    queue<int> q;
    for(auto adj_node:g){
        int nbr=adj_node.first;
        dist[nbr]=INT_MAX;
    }
    dist[src]=0;
    q.push(src);
     
  
    while(!q.empty()){
        //this if sec code extra only for to print elements in level order with diffrent line
        
        int frnt=q.front();
        //cout<<frnt<<" ";
        q.pop();

        for(int nbr:g[frnt]){
            if(dist[nbr]==INT_MAX){
                q.push(nbr);
                dist[nbr]=dist[frnt]+1;
            }
        }
    }
  for(auto all:g){
      int nbr=all.first;
      cout<<"node "<<nbr<<" at dist from src "<<dist[nbr]<<endl;
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
