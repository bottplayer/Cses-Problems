#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    map<pair<int,int>, pair<pair<int,int>, char>> parent;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    char dir[4] = {'R', 'L', 'U', 'D'};

    pair<int, int> start, end;
    bool foundA = false, foundB = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                start = {i, j};
                foundA = true;
            }
            if(grid[i][j] == 'B') {
                end = {i, j};
                foundB = true;
            }
        }
    }

    if(!foundA || !foundB) {
        cout << "NO\n";
        return 0;
    }

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool pathFound = false;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(x == end.first && y == end.second) {
            pathFound = true;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                if(grid[nx][ny] == '.' || grid[nx][ny] == 'B') {
                    visited[nx][ny] = true;
                    parent[{nx, ny}] = {{x, y}, dir[i]};
                    q.push({nx, ny});
                }
            }
        }
    }

    if(!pathFound) {
        cout << "NO\n";
    } else {
        vector<char> path;
        pair<int, int> cur = end;
        while(cur != start) {
            path.push_back(parent[cur].second);
            cur = parent[cur].first;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << path.size() << '\n';
        for(char c : path) cout << c;
        cout << '\n';
    }

    return 0;
}
