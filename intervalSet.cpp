template <typename T>
struct IntervalSet {
    set<pair<T, T>> st;

    void insert_interval(T L, T R) {
        if (L >= R) return;

        auto it = st.lower_bound({L, R});
        if (it != st.begin()) {
            auto it2 = prev(it);
            if (it2->second >= L) it = it2;
        }

        while (it != st.end() && it->first <= R) {
            L = min(L, it->first);
            R = max(R, it->second);
            it = st.erase(it);
        }
        st.insert({L, R});
    }

    void erase_interval(T L, T R) {
        if (L >= R) return;

        auto it = st.lower_bound({L, R});
        if (it != st.begin()) {
            auto it2 = prev(it);
            if (it2->second > L) it = it2;
        }

        while (it != st.end() && it->first < R) {
            ll a = it->first;
            ll b = it->second;
            it = st.erase(it);
            if (a < L) st.insert({a, L});
            if (R < b) {
                st.insert({R, b});
                break;
            }
        }
    }

    bool contains(T x) {
        auto it = st.upper_bound({x, inf});
        if (it == st.begin()) return false;
        it--;
        return it->first <= x && x < it->second;
    }
};
