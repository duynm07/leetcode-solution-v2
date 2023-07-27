#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        int n = nums.size();
        int suma = 0;
        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            suma += nums[i];
            f[0] += i * nums[i];
            if (i == 0)
                f[1] += i * nums[n - 1];
            else
                f[1] += i * nums[i - 1];
        }
        cout << f[0] << endl;
        cout << f[1] << endl;
        int ans = max(f[0], f[1]);
        for (int i = 2; i < n; i++) {
            f[i] = suma + f[i - 1] - n * nums[n - i];
            cout << f[i] << endl;
            ans = max(ans, f[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> a = {4, 3, 2, 6};
    int ans = sol.maxRotateFunction(a);
    cout << ans;
}