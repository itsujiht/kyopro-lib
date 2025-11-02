#include <vector>
#include <functional>
#define ll long long
using namespace std;

//a進数→b進数
string f(string n, int a, int b){
    ll d10 = 0;
    for (char c : n) {
        d10 = d10 * a + (c - '0');
    }
    if(d10 == 0) return "0";
    string dbs = "";
    while(d10){
        ll di = d10%b;
        dbs += to_string(di);
        d10 /= b;
    }
    reverse(dbs.begin(), dbs.end());
    return dbs;
}

//10進を経由せずに変換
string baseatob(string s, int a, int b) {
    string res = "";

    // b進変換の途中結果を得る
    while (s != "0") {
        string next = "";
        int carry = 0;
        for (char c : s) {
            int cur = carry * a + (c - '0');
            int q = cur / b;      // 商
            carry = cur % b;      // 余り
            if (!next.empty() || q > 0) next += (char)('0' + q);
        }
        res += (char)('0' + carry);  // 余りを9進の末尾桁に
        if (next.empty()) next = "0"; // 商が0になったら終了条件
        s = next;
    }

    reverse(res.begin(), res.end());
    return res;
}