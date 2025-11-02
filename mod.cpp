long long modpow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;  // aをmで割った余りにしておく
    while (b > 0) {
        if (b & 1)              // bの最下位ビットが1なら
            res = (res * a) % m; // resにaを掛ける
        a = (a * a) % m;        // aを2乗して更新
        b >>= 1;                // bを右に1ビットシフト（= b /= 2）
    }
    return res;
}
