class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        st.reserve(asteroids.size());
        for (auto& ast : asteroids) {
            bool alive = true;
            while (alive && !st.empty() && st.back() > 0 && ast < 0) {
                if (st.back() < (ast * -1)) {
                    st.pop_back();
                } else if (st.back() == (ast * -1)) {
                    st.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) st.push_back(ast);
        }
        return st;
    }
};