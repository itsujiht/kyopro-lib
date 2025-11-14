#include <functional>
using namespace std;
using ll = long long;

// Floyd's cycle detection　ABC179Eなど
struct Cycle {
    ll mu; // ループに入るまでの長さ mu (start から lp_start まで)
    ll lmd; // ループ長 lambda
};

Cycle cycleDetection(ll start, function<ll(ll)> f) {
    ll slow = f(start);
    ll fast = f(f(start));

    while (slow != fast) {
        slow = f(slow);
        fast = f(f(fast));
    }

    // find mu
    ll mu = 0;
    slow = start;
    while (slow != fast) {
        slow = f(slow);
        fast = f(fast);
        mu++;
    }

    // find lambda
    ll lmd = 1;
    fast = f(slow);
    while (slow != fast) {
        fast = f(fast);
        lmd++;
    }

    return {mu, lmd};
}

