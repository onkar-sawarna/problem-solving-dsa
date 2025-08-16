/*Given a list of scores of different students, 
return the average score of each student's top five scores in the order of each student's id.
Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  
The average score is calculated using integer division.*/

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

vector<vector<int>> highFive(vector<vector<int>>& items) {
    map<int, vector<int>> studentScores;

    for (const auto& item : items) {
        int studentId = item[0];
        int score = item[1];
        studentScores[studentId].push_back(score);
    }

    vector<vector<int>> result;

    for (auto const& [studentId, scores] : studentScores) {
        vector<int> currentScores = scores;

        sort(currentScores.rbegin(), currentScores.rend());

        long long sumTopFive = 0;
        for (int i = 0; i < 5; ++i) {
            sumTopFive += currentScores[i];
        }

        int average = static_cast<int>(sumTopFive / 5);

        result.push_back({studentId, average});
    }

    return result;
}

void solve(){
  vvi input = {{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}};
  vvi output = highFive(input);

  // Print the result for this test case
  for (const auto& student_avg_pair : output) {
    cout << student_avg_pair[0] << " " << student_avg_pair[1] << endl;
}
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