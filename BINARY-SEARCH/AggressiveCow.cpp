#include <iostream>
#define mod 1000000007
#include<vector>
#define ll long long int
using namespace std;
bool canPlace(vector<int> &nums, int cows, int m){
    int cntCows = 1;
    int lastPos = nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i] - lastPos >= m){
            cntCows++;
            lastPos = nums[i];
        }
    }
    return cntCows >= cows;
}
int main()
{
    vector<int> nums;
    int n, cows;
    cin >> n >> cows;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int l = 1;
    int r = nums[n-1] - nums[0];
    int ans = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(canPlace(nums, cows, m)){
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}