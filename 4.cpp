#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Pair {
    int first;
    int second;
};

vector<int> findFourElements(vector<int>& nums, int x) {
    int n = nums.size();
    unordered_map<int, vector<Pair>> pairSumMap;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = nums[i] + nums[j];
            pairSumMap[sum].push_back({i, j});
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int currentSum = nums[i] + nums[j];
            int remainingSum = x - currentSum;
            if (pairSumMap.find(remainingSum) != pairSumMap.end()) {
                for (Pair p : pairSumMap[remainingSum]) {
                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        return {i + 1, j + 1, p.first + 1, p.second + 1};
                    }
                }
            }
        }
    }

    return {};
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = findFourElements(nums, x);
    if (result.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
