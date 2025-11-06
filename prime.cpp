#include <vector>
#define ll long long
using namespace std;

// list of prime less than n : Sieve of Eratosthenes
vector<ll> primeList (ll n){
    vector<bool> isP(n+1, true);
    isP[0] = false, isP[1] = false;
    vector<ll> res;
    if (n < 2) return res;
    for(ll i = 2; i * i <= n; i++){
        if(isP[i]){
            for(ll j = i; j <= n; j += i){
                isP[j] = false;
            }
        }
    }
    for(ll i = 0; i <= n; i++){
        if(isP[i]) res.push_back(i);
    }
    return res;
}

// list of prime and its number in the number n
vector<pair<ll, ll>> primeNumList (ll n){
    vector<pair<ll, ll>> res;
    ll N = n;
    for(ll i = 2; i * i <= n; i++){
        ll divnum = 0;
        while(N % i == 0){
            N /= i;
            divnum++;
        }
        if(divnum > 0) res.push_back({i, divnum});
    }
    if(N > 1) res.push_back({N, 1});
    return res;
}

vector<ll> divisorList (ll n){
    vector<ll> res = {1};
    for(ll i = 2; i * i <= n; i++){
        if(n%i == 0) res.push_back(i);
    }
    vector<ll> res2;
    for(auto it = res.rbegin(); it != res.rend(); ++it){
        if((*it)*(*it) != n) res2.push_back(n/(*it));
    }
    for(ll d: res2) res.push_back(d);
    return res;
}