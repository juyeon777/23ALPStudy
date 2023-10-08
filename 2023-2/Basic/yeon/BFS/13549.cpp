#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
bool visit[100001];
int res = 0;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    queue <pair<int, int>> q;
    q.push(make_pair(n, 0));
    visit[n] = true;
    
    while(!q.empty()){
        
        int Loc = q.front().first;
        int Tim = q.front().second;
        q.pop();
        
        visit[Loc] = true;
        
        if(Loc == k && res == 0) res = Tim;
        else if(Loc == k && res != 0){
            if(res > Tim) res = Tim;
            else res = res;
        }
        
        if(Loc*2 <= 100001 && !visit[Loc*2]){
            q.push(make_pair(Loc*2, Tim));
            visit[Loc*2] = visit[Loc];
        }
        if(Loc-1 >= 0 && !visit[Loc-1]){
            q.push(make_pair(Loc-1, Tim+1));
            visit[Loc-1] = visit[Loc]+1;
        }
        if(Loc+1 <= 100001 && !visit[Loc+1]){
            q.push(make_pair(Loc+1, Tim+1));
            visit[Loc+1] = visit[Loc]+1;
        }
    }
    
    cout << res;
    
    return 0;
}
