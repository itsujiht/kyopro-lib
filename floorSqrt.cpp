#include <math.h>
#define ll long long

ll f (ll x) {  // sqrtの丸め誤差を修正
    ll y = sqrt(x);
    while (y * y > x) y--;
    while ((y+1) * (y+1) <= x) y++;
    return y;
}