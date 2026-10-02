// class Solution {
// public:
//     long long TimeFunc(int mid, vector<int>& piles) {
//         long long sum = 0;

//         for (int i = 0; i < piles.size(); i++) {
//             if (mid >= piles[i]) {
//                 sum += 1;
//             }
//             else {
//                 double num1 = (double)piles[i] / mid;
//                 long long num2 = (long long)piles[i] / mid;

//                 if (num1 > num2) {
//                     sum += num2 + 1;
//                 }
//                 else {
//                     sum += num2;
//                 }
//             }
//         }

//         return sum;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1, high = *max_element(piles.begin(), piles.end());
//         int ans = 0;
//         while(low <= high){
//             int mid =(low+high)/2;
//             int time  = TimeFunc(mid, piles);
//             if(time <= h){
//                 ans = mid;
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:

    long long TimeFunc(int mid, vector<int>& piles) {
        long long sum = 0;

        for (int i = 0; i < piles.size(); i++) {
            sum += (piles[i] + (long long)mid - 1) / mid;
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long time = TimeFunc(mid, piles);

            if (time <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};