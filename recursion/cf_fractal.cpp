#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 
void generateFractal(vector<string>& fractal, const vector<string>& model, int row_start, int col_start, int size, int step) {
    if (step == 0)
        return;

    int n = model.size();
    int next_size = size / n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (model[i][j] == '*') {
                for (int r = row_start + i * next_size; r < row_start + (i + 1) * next_size; ++r) {
                    for (int c = col_start + j * next_size; c < col_start + (j + 1) * next_size; ++c) {
                       fractal[r][c] = '*';
                    }
                }
            } else {
                generateFractal(fractal, model, row_start + i * next_size, col_start + j * next_size, next_size, step - 1);
            }
        }
    }
}

  signed main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
        IOS;
        int n, k;
    cin >> n >> k;

    vector<string> model(n);
    for (int i = 0; i < n; ++i) {
        cin >> model[i];
    }

    int final_size = 1;
    for (int i = 0; i < k; ++i) {
        final_size *= n;
    }

    vector<string> fractal(final_size, string(final_size, '.'));

    generateFractal(fractal, model, 0, 0, final_size, k);

    for (int i = 0; i < final_size; ++i) {
        cout << fractal[i] << endl;
    }

    return 0;
    }