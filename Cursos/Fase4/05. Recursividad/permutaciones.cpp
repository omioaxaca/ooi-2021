#include <bits/stdc++.h>

using namespace std;

void permutacion(vector<int> &nums, vector<bool> &states, vector<int> &sol, int take=0) {
    if (take == nums.size()) {
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i=0; i < nums.size(); i++ ) {
        if (states[i] == true) {
            continue;
        }
        sol[take] = nums[i];
        states[i] = true;
        permutacion(nums, states, sol, take+1);
        states[i] = false;
    }
}


int main () {
    vector<int> nums = {1,2,3, 4};
    vector<bool> states(nums.size(), false);
    vector<int> sol(nums.size(), 0);

    permutacion(nums, states, sol);

    return 0;
}
