#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

//adjacency list
vector<int>adjList[N];

//booleen array
bool visited[N];

//level array
int level[N];

//parent track
int parent[N];

//bfs implementation
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    parent[s]=-1;
    if(!q.empty()){
        //pop a node from the queue and insert unvisited node of that queue
        int u= q.front();
        q.pop();
      
        //section 1: a node is being processed
        for(int v: adjList[u]){
            //section 2:child processing
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
            parent[v]=u;
            //section 3: child processing
        }
        //section 4: same as section one

    }

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }
    int s,d;
    cin>>s>>d;
    bfs(s);
    cout<<level[d]<<" ";

    //print parent
    for(int i=0; i<n; i++){
        cout<<"parent node "<<i<<": "<<parent[i]<<endl;
    }

    //calculate sortest path
    vector<int>path;
    int current=d;
    while(current!=-1){
        path.push_back(current);
        current=parent[current];
    }

    //revers
    reverse(path.begin(), path.end());
    
    //print path
    for(int single: path){
        cout<<"path :"<< single<<endl;
    }
    
    return 0;
}