#include<iostream>
#include<queue>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        int a_abs = a;
        int b_abs = b;
        if (a_abs<0) a_abs *= -1;
        if (b_abs<0) b_abs *= -1;

        if(a_abs > b_abs) return true;
        else if (a_abs == b_abs){
            if(a>b) return true;
            else return false;
        }
        else return false;
    }
};

int main(void){
    int n, x;
    priority_queue<int, vector<int>, compare> abs_q;

    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> x;
        if(x) abs_q.push(x);
        else {
            if(abs_q.empty()){
                cout << 0 << '\n';
                continue;
            }
            cout << abs_q.top() << '\n';
            abs_q.pop();
        }
    }

    return 0;
}