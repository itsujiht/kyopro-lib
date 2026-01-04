template <typename T>
class segmenttree{
    public:
    vector<T> mx;
    vector<T> mi;
    const T INF = numeric_limits<T>::max();
    const T NINF = numeric_limits<T>::lowest();
    int sz;

    void init(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        mx.resize(sz * 2, NINF);
        mi.resize(sz * 2, INF);
    }

    void update(int pos, T value){
        pos += sz;
        mx[pos] = value;
        mi[pos] = value;
        while(pos > 1){
            pos >>= 1;
            mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
            mi[pos] = min(mi[pos * 2], mi[pos * 2 + 1]);
        }
    }

    T mx_query(int left, int right){
        return mx_query(left, right, 0, sz, 1);
    }

    T mi_query(int left, int right){
        return mi_query(left, right, 0, sz, 1);
    }

    private:
    T mx_query(int left, int right, int open, int close, int now){
        if(right <= open || close <= left) return NINF;
        if(left <= open && close <= right) return mx[now];
        int middle = (open + close) / 2;
        T lval = mx_query(left, right, open, middle, now * 2);
        T rval = mx_query(left, right, middle, close, now * 2 + 1);
        return max(lval, rval);
    }

    T mi_query(int left, int right, int open, int close, int now){
        if(right <= open || close <= left) return INF;
        if(left <= open && close <= right) return mi[now];
        int middle = (open + close) / 2;
        T lval = mi_query(left, right, open, middle, now * 2);
        T rval = mi_query(left, right, middle, close, now * 2 + 1);
        return min(lval, rval);
    }
};