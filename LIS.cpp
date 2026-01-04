#include <iostream>
#include <vector>
#include <functional>
#define ll long long
using namespace std;

vector<ll> p;
void LIS(void){
    vector<ll> lis;
    for (int i = 0; i < p.size(); i++){
        auto it = lower_bound(lis.begin(), lis.end(), p[i]);
        if(it == lis.end()) lis.push_back(p[i]);
        else *it = p[i];
    }
    cout << lis.size() << endl;
}
