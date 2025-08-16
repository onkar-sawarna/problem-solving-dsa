// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int attack = 0;

// int monster_attack(int h) {
//     if (h == 1) {
//         attack += 1;
//         return attack;
//     }
//     if (h <= 0) {
//         return attack;
//     }
//     attack++;
//     monster_attack(h / 2);
//     monster_attack(h / 2);
//     return attack;
// }

// signed main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int h;
//     cin >> h;
//     monster_attack(h);
//     cout << attack << endl;
// }


#include <bits/stdc++.h>
using namespace std;


long long monster_attack(long long h) {
    if (h == 1) {
        return 1;
    }
    return 1+2*monster_attack(h/2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h;
    cin >> h;
    cout << monster_attack(h) << endl;
}