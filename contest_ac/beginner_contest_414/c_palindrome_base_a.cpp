#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

bool is_palindrome(const string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

string to_base_a(int n, int a) {
    if (n == 0) {
        return "0";
    }
    string digits = "";
    while (n > 0) {
        digits += to_string(n % a);
        n /= a;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

vector<int> generate_decimal_palindromes(int limit) {
    set<int> palindromes_set;

    for (int i = 1; i <= 1000000; ++i) {
        string s_i = to_string(i);
        string p_str = s_i;
        string suffix = s_i.substr(0, s_i.length() - 1);
        reverse(suffix.begin(), suffix.end());
        p_str += suffix;

        long long p = stoll(p_str);
        if (p <= limit) {
            palindromes_set.insert(p);
        } else {
            break;
        }
    }

    for (int i = 1; i <= 1000000; ++i) {
        string s_i = to_string(i);
        string p_str = s_i;
        string suffix = s_i;
        reverse(suffix.begin(), suffix.end());
        p_str += suffix;

        long long p = stoll(p_str);
        if (p <= limit) {
            palindromes_set.insert(p);
        } else {
            break;
        }
    }

    vector<int> sorted_palindromes(palindromes_set.begin(), palindromes_set.end());
    sort(sorted_palindromes.begin(), sorted_palindromes.end());
    return sorted_palindromes;
}

void solve() {
    int A, N;
    cin >> A >> N;

    int total_sum = 0;
    vector<int> decimal_palindromes = generate_decimal_palindromes(N);

    for (int num : decimal_palindromes) {
        if (num == 0) {
            continue;
        }
        string base_a_rep = to_base_a(num, A);
        if (is_palindrome(base_a_rep)) {
            total_sum += num;
        }
    }
    cout << total_sum << endl;
}

signed main() {
    IOS;
    solve();
    return 0;
}

// Time Complexity: O(P log P + P log N)
// Space Complexity: O(P)
// Pattern: Brute Force - Palindrome seeds
// explanation:
/*
Odd-length decimal palindromes mirror a seed after dropping its last digit. Even-length ones mirror the whole seed.
Both loops walk seeds from 1, stop at 1000000, and also stop once the built value exceeds N.
A set stores every palindrome that fits, which sorts them and removes duplicates.
Each stored value is rewritten in base A by repeated division, then kept in the sum only when that digit string is a palindrome.
P is the number of decimal palindromes stored.
*/
