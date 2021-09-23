#include<iostream>
#include<queue>

using namespace std;

bool check[10001];

int D(int a){
    return (a*2)%10000;
}

int S(int a){
    if(a) return a-1;
    else return 9999;
}

int L(int a){
    int n[4];
    int m=3;
    while(a){
        n[m] = a%10;
        a /= 10;
        m--;
    }
    return ((n[1]*10 + n[2]) * 10 + n[3]) * 10 + n[0];
}

int R(int a){
    int n[4];
    int m=3;
    while(a){
        n[m] = a%10;
        a /= 10;
        m--;
    }
    return ((n[3]*10 + n[0]) * 10 + n[1]) * 10 + n[2];
}

string bfs(int start, int fin){
    queue< pair<int, string> > q;
    q.push( make_pair(start, ""));

    while(!q.empty()){
        int cur_num = q.front().first;
        string cur_str = q.front().second;
        q.pop();
        int next_num;

        next_num = D(cur_num);
        if(!check[next_num]){
            q.push( make_pair(next_num, cur_str+"D") );
            if(next_num == fin) return q.back().second;
        }

        next_num = S(cur_num);
        if(!check[next_num]){
            q.push( make_pair(next_num, cur_str+"S") );
            if(next_num == fin) return q.back().second;
        }

        next_num = L(cur_num);
        if(!check[next_num]){
            q.push( make_pair(next_num, cur_str+"L") );
            if(next_num == fin) return q.back().second;
        }

        next_num = R(cur_num);
        if(!check[next_num]){
            q.push( make_pair(next_num, cur_str+"R") );
            if(next_num == fin) return q.back().second;
        }
    }
}


int main(void){
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        int a,b;
        cin >> a >> b;
        
        cout << bfs(a,b) << '\n';
        fill(check, check+10000, false);
    }
}