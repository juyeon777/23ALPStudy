#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[205][205];
int nxt[205][205];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1;i<=n;i++) fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c); // 양방향 통행
    d[b][a] = min(d[b][a], c);
    nxt[a][b] = b;
    nxt[b][a] = a;
  }
  for(int i = 1;i<=n;i++) d[i][i] = 0;
  for(int k = 1;k<=n;k++)
    for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++){
        if(d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
            nxt[i][j] = nxt[i][k];
        }
      }

  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++){
      if(i == j) cout << "- ";
      else cout << nxt[i][j] << " ";
    }
    cout << "\n";
  }
  // 경로복원 문제
}
