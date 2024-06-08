#include<bits/stdc++.h>
using namespace std;
struct Cell {
    int x, y;
};
bool isValid(int x, int y, int n, int m, vector<string> &input) {
    return x >= 0 && x < n && y >= 0 && y < m && input[x][y] != '#';
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> input(n);
    Cell start, end;
    vector<Cell> directions = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> dirChars = {'U', 'D', 'L', 'R'};
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        for (int j = 0; j < m; ++j) {
            if (input[i][j] == 'A'){
              start = {i, j};
            }
            if (input[i][j] == 'B'){
              end = {i, j};
            }
        }
    }

    queue<Cell> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<Cell>> parent(n, vector<Cell>(m, { -1, -1}));
    vector<vector<char>> direction(n, vector<char>(m));

    q.push(start);
    dist[start.x][start.y] = 0;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + directions[i].x;
            int newY = current.y + directions[i].y;

            if (isValid(newX, newY, n, m, input) && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[current.x][current.y] + 1;
                parent[newX][newY] = current;
                direction[newX][newY] = dirChars[i];
                q.push({newX, newY});

                if (newX == end.x && newY == end.y) {
                    string path;
                    Cell p = end;
                    while (p.x != start.x || p.y != start.y) {
                        path += direction[p.x][p.y];
                        p = parent[p.x][p.y];
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES"<<endl;
                    cout << path.length() <<endl;
                    cout << path <<endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO"<<endl;
}
