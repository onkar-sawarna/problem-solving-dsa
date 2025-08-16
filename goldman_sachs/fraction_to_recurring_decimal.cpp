/*
Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
*/

#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;

string fractionToDecimal(int numerator_int, int denominator_int) {
    if (numerator_int == 0) {
        return "0";
    }

    string result = "";

    if ((numerator_int < 0) != (denominator_int < 0)) {
        result += "-";
    }

    long long numerator = abs(static_cast<long long>(numerator_int));
    long long denominator = abs(static_cast<long long>(denominator_int));

    result += to_string(numerator / denominator);

    long long remainder = numerator % denominator;

    if (remainder == 0) {
        return result;
    }

    result += ".";

    unordered_map<long long, int> remainder_map;

    while (remainder != 0) {
        if (remainder_map.count(remainder)) {
            int repeating_start_pos = remainder_map[remainder];
            result.insert(repeating_start_pos, "(");
            result += ")";
            return result;
        }

        remainder_map[remainder] = result.length();

        remainder *= 10;
        result += to_string(remainder / denominator);
        remainder %= denominator;
    }

    return result;
}

void solve(){
    cout<<fractionToDecimal(1,3)<<endl;
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}