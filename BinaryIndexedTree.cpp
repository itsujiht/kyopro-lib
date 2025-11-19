typedef long long ll;
template<typename T>
struct BIT {
    ll n;
    vector<T> bit;
    BIT(ll n_) : n(n_ + 1), bit(n_ + 1, 0){} // 1-indexed

    // add x to i index
    void add(ll i, T x){
        for(ll idx = i; idx < n; idx += (idx & -idx)){
            bit[idx] += x;
        }
    }

    // sum from 1 to i
    T sum(ll i){
        T s(0);
        for(ll idx = i; idx > 0; idx -= (idx & -idx)){
            s += bit[idx];
        }
        return s;
    }
};