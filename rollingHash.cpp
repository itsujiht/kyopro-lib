#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll B1 = 1000000007;
constexpr ll B2 = 10000000007;

// find T in S
bool rolling_hash(string S, string T){
    if(S.size() < T.size()) return false;

    ull powB1 = 1, powB2 = 1;
    for(ll i = 0; i < T.size(); i++){
        powB1 *= B1;
        powB2 *= B2;
    }

    ull shash1 = 0, thash1 = 0, shash2 = 0, thash2 = 0; // mod as overflow
    for(ll i = 0; i < T.size(); i++){
        shash1 *= B1, shash2 *= B2;
        thash1 *= B1, thash2 *= B2;
        shash1 += S[i], shash2 += S[i];
        thash1 += T[i], thash2 += T[i];
    }

    if(shash1 == thash1 && shash2 == thash2) return true;
    for(ll i = 0; i < S.size() - T.size(); i++){
        shash1 = shash1*B1 - S[i]*powB1 + S[T.size() + i];
        shash2 = shash2*B2 - S[i]*powB2 + S[T.size() + i];
        if(shash1 == thash1 && shash2 == thash2) return true;
    }

    return false;
}