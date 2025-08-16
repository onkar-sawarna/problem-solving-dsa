

// bool canMakeBouquets(int day,vector<int>& bloomDay,int m,int k){
//  int current_adjacent_flowers=0;
//  int bouquets_made = 0;
//     for(int bloom_time : bloomDay){
//         if(bloom_time <= day){
//             current_adjacent_flowers++;
//             if(current_adjacent_flowers == k){
//                 bouquets_made++;
//                 current_adjacent_flowers = 0;
//                 if(bouquets_made>=m)return true;
//             }
//         }else{
//             current_adjacent_flowers = 0;
//         }
//     }
//     return false;
// }
// int minDays(vector<int>& bloomDay, int m,int k){
//     int n = bloomDay.size();
    
//     if(m*k > n)return -1;
//     int low=INT_MAX;
//     int high = INT_MIN;
//     for(int i=0;i<n;i++){
//         low = min(low,bloomDay[i]);
//         high = max(max,bloomDay[i]);
//     }
//     int ans = high;

//     while(low <= high){
//         int mid = (high+low)/2;

//         if(canMakeBouquets(mid,bloomDay,m,k)){
//             ans=mid;
//             high = mid-1;
//         }else{
//             low = mid+1;
//         }
//     }
//     return ans;
// }