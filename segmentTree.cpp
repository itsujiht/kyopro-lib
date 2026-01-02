template <typename T>
class segmenttree{
    public:
    vector<T> date1;
    vector<T> date2;
    const T INF = numeric_limits<T>::max();
    int sz;

    void init(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        date1.resize(sz * 2, 0);
        date2.resize(sz * 2, INF);
    }

    void update(int pos, T value){
        pos += sz;
        date1[pos] = max(date1[pos], value);
        date2[pos] = min(date2[pos], value);
        while(pos > 1){
            pos >>= 1;
            date1[pos] = max(date1[pos * 2], date1[pos * 2 + 1]);
            date2[pos] = min(date2[pos * 2], date2[pos * 2 + 1]);
        }
    }

    T query1(int left, int right, int open, int close, int now){
        if(right <= open || close <= left) return 0;
        if(left <= open && close <= right) return date1[now];
        int middle = (open + close) / 2;
        T lval = query1(left, right, open, middle, now * 2);
        T rval = query1(left, right, middle, close, now * 2 + 1);
        return max(lval, rval);
    }

    T query2(int left, int right, int open, int close, int now){
        if(right <= open || close <= left) return INF;
        if(left <= open && close <= right) return date2[now];
        int middle = (open + close) / 2;
        T lval = query2(left, right, open, middle, now * 2);
        T rval = query2(left, right, middle, close, now * 2 + 1);
        return min(lval, rval);
    }
};