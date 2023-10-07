#include <iostream>
#include <queue>

//1초에 이동할 수 있는 경우의 수: 3가지
//1초동안 갈 수 있는 곳은 n+1, n-1, n*2

int visit[100001] = {0, };

using namespace std;

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    //수빈이가 있는 위치, 동생이 있는 위치
    
    int x = 0;
    queue <int> q;
    
    q.push(n); //수빈이가 있는 위치가 곧 탐색 시작할 위치
    
    while(!q.empty()){
        
        x = q.front(); //수빈이의 이동
        q.pop();
        
        if(x<0 || x>100000) continue; //위치가 범위내에 있지 않을 경우
        
        if(x == k){ //동생을 찾은 경우 -> 종료
            cout << visit[x];
            break;
        }
        
        //수빈이가 1초동안 이동할 수 있는 경우의 수
        if(x-1>=0 && visit[x-1] == 0){
            visit[x-1] = visit[x]+1; //동생을 찾는 가장 빠른 시간 탐색
            q.push(x-1);
        }
        if(x+1<=100000 && visit[x+1] == 0){
            visit[x+1] = visit[x]+1;
            q.push(x+1);
        }
        if(2*x<=100000 && visit[x*2] == 0){
            visit[2*x] = visit[x]+1;
            q.push(2*x);
        }
    }
    
    return 0;
}
