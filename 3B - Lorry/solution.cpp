#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long v;
    cin >> n >> v;

    vector<pair<long long,int>> k, c;

    for(int i=1;i<=n;i++){
        int t,p;
        cin>>t>>p;
        if(t==1) k.push_back({p,i});
        else c.push_back({p,i});
    }

    sort(k.rbegin(),k.rend());
    sort(c.rbegin(),c.rend());

    int ks=k.size(), cs=c.size();

    vector<long long> pk(ks+1), pc(cs+1);

    for(int i=1;i<=ks;i++) pk[i]=pk[i-1]+k[i-1].first;
    for(int i=1;i<=cs;i++) pc[i]=pc[i-1]+c[i-1].first;

    long long best=0;
    int bestK=0,bestC=0;

    for(int i=0;i<=cs;i++){
        long long used=2LL*i;
        if(used>v) break;

        long long rem=v-used;
        int take=min((long long)ks,rem);

        long long val=pc[i]+pk[take];

        if(val>best){
            best=val;
            bestC=i;
            bestK=take;
        }
    }

    cout<<best<<"\n";

    for(int i=0;i<bestC;i++) cout<<c[i].second<<" ";
    for(int i=0;i<bestK;i++) cout<<k[i].second<<" ";
}
