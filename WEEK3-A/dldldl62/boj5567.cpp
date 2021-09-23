#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> friends[501];
bool check[501] = {false, };
int ans = 0;

void dfs(int fr, int depth){
    if(depth == 2) return;

    for(int j = 0 ; j< friends[fr].size(); ++j){
        if(!check[friends[fr][j]]){
            ans++;
            check[friends[fr][j]] = true;
        }
        dfs(friends[fr][j], depth+1);
    }

}

int main(void){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; ++i){
        int u,v;
        cin >> u >> v;

        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    check[1] = true;
    dfs(1, 0);
    cout << ans;
}