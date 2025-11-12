#include <math.h>
#define ll long long

ll floorSqrt (ll x){
    ll y = sqrt(x);
    while (y * y > x) y--;
    while ((y+1) * (y+1) <= x) y++;
    return y;
}

ll floorLog (ll a, ll x){ // a >= 2, x >= 1
    ll y = logl(x) / logl(a);
    ll cur = 1;
    for (int i = 0; i < y; i++) cur *= a;
    while (cur > x) { cur /= a; y--; }
    while (cur * a <= x) { cur *= a; y++; }
    return y;
}