class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) i++; // lightest shares the boat
            j--;                                      // heaviest always leaves
            ans++;
        }
        return ans;
    }
};