#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int MAX_N = 2500;
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int row_num;
int col_num;
string building[MAX_N];
bool visited[MAX_N][MAX_N];

void floodfill(int r, int c)
{
    stack<pair<int, int>> qu;
    qu.push({r, c});
    while (!qu.empty())
    {
        r = qu.top().first;
        c = qu.top().second;
        qu.pop();

        if (r < 0 || r >= row_num || c < 0 || c >= col_num ||
            building[r][c] == '#' || visited[r][c])
            continue;

        visited[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            qu.push({r + R_CHANGE[i], c + C_CHANGE[i]});
        }
    }
}

int main()
{
    cin >> row_num >> col_num;
    for (int i = 0; i < row_num; i++)
    {
        cin >> building[i];
    }
    int room_num = 0;
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            if (building[i][j] == '.' && !visited[i][j])
            {
                floodfill(i, j);
                room_num++;
            }
        }
    }
    cout << room_num << endl;
}