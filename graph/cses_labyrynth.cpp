#include <bits/stdc++.h>
using namespace std;

// Standard input/output optimization
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Define int as long long for potentially larger values, though not strictly necessary for N,M <= 1000
#define int long long

// A large value to represent infinity for distances (unvisited cells)
#define INF 1e9

// Alias for pair<int, int> to represent coordinates (row, column)
using state = pair<int, int>;

// Global variables for labyrinth dimensions
int n, m;

// Labyrinth map
vector<string> arr;

// dist[r][c] stores the shortest distance from 'A' to (r,c)
// Initialized to INF for unvisited cells
vector<vector<int>> dist;

// parent[r][c] stores the coordinates of the cell from which (r,c) was visited
// Used for reconstructing the path
vector<vector<state>> parent;

// parent_char[r][c] stores the character ('U', 'D', 'L', 'R') representing the direction
// taken to reach (r,c) from its parent.
vector<vector<char>> parent_char;

// Arrays for movement in 4 directions: Down, Right, Up, Left
// Matches the order for dir_chars
int dx[] = {1, 0, -1, 0}; // Change in row: D, R, U, L
int dy[] = {0, 1, 0, -1}; // Change in column: D, R, U, L
char dir_chars[] = {'D', 'R', 'U', 'L'}; // Corresponding direction characters

/*
 * BFS function to find shortest distances and parent information
 * from a given start node to all reachable nodes.
 */
void bfs(state start) {
    // Initialize distance matrix with INF and parent matrix with invalid states
    dist = vector<vector<int>>(n, vector<int>(m, INF));
    parent = vector<vector<state>>(n, vector<state>(m, {-1, -1})); // {-1,-1} indicates no parent
    parent_char = vector<vector<char>>(n, vector<char>(m)); // Default char value will be fine

    queue<state> q;

    // Start BFS from the 'A' node
    q.push(start);
    dist[start.first][start.second] = 0; // Distance to start is 0

    while (!q.empty()) {
        state curr = q.front();
        q.pop();

        // Explore all 4 neighbors
        for (int i = 0; i < 4; ++i) {
            int nr = curr.first + dx[i]; // New row
            int nc = curr.second + dy[i]; // New column
            state nbr = {nr, nc};

            // Check if the neighbor is within labyrinth boundaries
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                // Check if the neighbor is not a wall ('#')
                // And if it has not been visited yet (distance is INF)
                if (arr[nr][nc] != '#' && dist[nr][nc] > dist[curr.first][curr.second] + 1) {
                    dist[nr][nc] = dist[curr.first][curr.second] + 1; // Update distance
                    parent[nr][nc] = curr; // Set current cell as parent of neighbor
                    parent_char[nr][nc] = dir_chars[i]; // Store the direction character
                    q.push(nbr); // Add neighbor to queue for further exploration
                }
            }
        }
    }
}

/*
 * Main solve function to read input, run BFS, and print output.
 */
void solve() {
    cin >> n >> m; // Read labyrinth dimensions

    arr.resize(n); // Resize labyrinth map
    state start, end; // Store start 'A' and end 'B' positions

    // Read labyrinth map and find 'A' and 'B'
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 'A') {
                start = {i, j};
            } else if (arr[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    // Run BFS starting from 'A'
    bfs(start);

    // Check if 'B' was reachable
    if (dist[end.first][end.second] != INF) {
        cout << "YES" << "\n";
        cout << dist[end.first][end.second] << "\n"; // Print shortest path length

        string path = "";
        state curr_path_node = end;

        // Reconstruct path by backtracking from 'B' to 'A'
        while (curr_path_node != start) {
            char d = parent_char[curr_path_node.first][curr_path_node.second];
            path += d; // Append the direction character

            // Move to the parent node based on the direction taken to reach curr_path_node
            // This is the inverse of the dx/dy movement
            if (d == 'U') { // If we came UP to curr, parent was DOWN relative to curr
                curr_path_node.first++;
            } else if (d == 'D') { // If we came DOWN to curr, parent was UP relative to curr
                curr_path_node.first--;
            } else if (d == 'L') { // If we came LEFT to curr, parent was RIGHT relative to curr
                curr_path_node.second++;
            } else if (d == 'R') { // If we came RIGHT to curr, parent was LEFT relative to curr
                curr_path_node.second--;
            }
        }
        reverse(path.begin(), path.end()); // Reverse the path to get it from A to B
        cout << path << "\n"; // Print the path string
    } else {
        cout << "NO" << "\n"; // 'B' is not reachable
    }
}

// Main function
signed main() {
    IOS; // Apply input/output optimizations
    solve(); // Call the solve function
    return 0;
}