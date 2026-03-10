// class Solution {
// public:
//     vector<int> maxOfSubarrays(vector<int>& arr, int k) {
//         vector<int> ans;
//         int n = arr.size();

//         int maxi = -1;

//         for(int i = 0; i <= n - k; i++) {

//             if(i == 0) {
//                 maxi = arr[0];
//                 for(int j = 1; j < k; j++)
//                     maxi = max(maxi, arr[j]);
//             }
//             else {
//                 if(arr[i-1] == maxi) {
//                     maxi = arr[i];
//                     for(int j = i+1; j < i+k; j++)
//                         maxi = max(maxi, arr[j]);
//                 }
//                 else {
//                     maxi = max(maxi, arr[i+k-1]);
//                 }
//             }

//             ans.push_back(maxi);
//         }

//         return ans;
//     }
// };