template <typename T>
class segmenttree{
    public:
    vector<T> date;
    int sz;

    void init(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        date.resize(sz * 2, 0);
    }

    void update(int pos, T value){
        pos += sz;
        if(date[pos] >= value) return;
        date[pos] = value;
        while(pos > 1){
            pos /= 2;
            date[pos] = max(date[pos * 2], date[pos * 2 + 1]);
        }
    }

    T query(int left, int right, int open, int close, int now){
        if(right <= open || close <= left) return 0;
        if(left <= open && close <= right) return date[now];
        int middle = (open + close) / 2;
        T lval = query(left, right, open, middle, now * 2);
        T rval = query(left, right, middle, close, now * 2 + 1);
        return max(lval, rval);
    }
};