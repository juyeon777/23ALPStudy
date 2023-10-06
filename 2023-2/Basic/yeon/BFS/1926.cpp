#include <iostream>
#include <queue>

using namespace std;

int board[501][501]; //1이 파란 칸, 0이 빨간 칸에 대응
bool visit[501][501]; //방문 여부

//상하좌우 네 방향
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  int max = 0; // 그림의 최댓값
  int cnt = 0; // 그림의 수

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){

      if(board[i][j] == 0 || visit[i][j]) continue;
      //해당 칸이 색칠이 안된 부분이거나 이미 방문했을 경우

      // (i,j)는 새로운 그림에 속해있는 시작점
      cnt++; // 그림의 수 1 증가

      queue<pair<int,int> > q;

      visit[i][j] = 1; // 시작점 (i,j)로 BFS

      q.push({i,j});

      int res = 0; // 그림의 넓이

      while(!q.empty()){

        res++; //큐에 들어있는 원소를 하나 뺄 때마다 넓이 증가

        pair<int,int> qq = q.front();

        q.pop();

        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸

          int nx = qq.first + dx[dir];
          int ny = qq.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감

          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우

          if(visit[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우

          visit[nx][ny] = 1;

          q.push({nx,ny});

        }
      }

      if(res > max) max = res;
    
    }
  }

  cout << cnt << '\n' << max;

  return 0;

}
