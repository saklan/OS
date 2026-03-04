/*
 *   BISMILLAHIR RAHMANIR RAHIM
 *   ==========================
 *
 *   Submitted By: SAKLAN
 *   North East University Bangladesh



 */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define int long long
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define cinv(v) for(auto &i:v) cin >> i;
#define vi vector<int>
#define vii vector<ll>
#define modd 1000000007
#define coutv(v) for(auto e:v) cout << e << ' ';
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define yes cout<<"Yes\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define no cout<<"No\n"
#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
#define comp [](const pair<int,int> &a, const pair<int,int> &b){ return a.second > b.second; }
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define saklan ios::sync_with_stdio(0); cin.tie(0);
#define dbg(v) do { \
    for (auto val : v) cout << val << " "; \
    cout << endl << "___________________________ " << endl; \
} while(0)

#define otp(v) do { \
    for (auto val : v) cout << val << " "; \
    cout << endl; \
} while(0)

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }



//template<class T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_nodde_update>;

bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return (a.first - a.second) > (b.first - b.second);
}

bool cmpp(const pair<int,int>& a, const pair<int,int>& b){
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;

    int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

//const int mx = 10000000 + 5;
//bool isPrime[mx];

//void sieve() {
//    isPrime[2] = 1;
//    for (int i = 3; i < mx; i += 2)
//        isPrime[i] = 1;
//
//    int sq = sqrt(mx);
//    for (int i = 3; i <= sq; i += 2) {
//        if (isPrime[i]) {
//            for (int j = i * i; j < mx; j += 2 * i)
//                isPrime[j] = 0;
//        }
//    }
//}




//unordered_map<int,int> dp;
//
//int rec(int n, int k) {
//    if (n == k) return 0;
//    if (n < k) return -1;
//    if (dp.count(n)) return dp[n];
//
//    int a = rec((n + 1) / 2, k);
//    int b = rec(n / 2, k);
//
//    int res = min(a, b);
//    if (res != -1) res++;
//
//    return dp[n] = res;
//}



int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}


//const int mx = 1e6+10;
//int composit[mx];
//
//void seive(){
//    composit[1] = 1;
//    for(int i=2;i<=mx;i++)
//    {
//        if(composit[i]) continue;
//        for(int j=i+i;j<=mx;j+=i){
//            composit[j] = 1;
//        }
//    }
//}
//bool isPrime(int n) {
//    for (int i = 3; i * i <= n; i += 2) {
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//}





struct sjf{
    string name;
    int arrive;
    int brust;
    int compile;
    int tat;
    int wt;
    int rt;
    int index;
    bool flag = false;
};

void solve() {
    int n;cout <<"Give me the total Number of Process: ";cin>>n;
    vector<sjf>p(n);
    for(int i = 0; i < n; i++){
        cout << "Give process Name and its Arrival Time as well as Burst time: ";
        cin >> p[i].name >> p[i].arrive >> p[i].brust;
        p[i].index = i;
    }
    int x = 0;
    int counter = 0;
    int avg_tat = 0, avg_wt = 0, avg_rt = 0;
    while(x < n){
        int idx = -1;
        int mn = 5e9;
        for(int i = 0; i <n ; i++){
            if(!p[i].flag and p[i].arrive <= counter){
                if(mn > p[i].brust){
                    mn = p[i].brust;
                    idx = i;
                }
                else if(p[i].brust == mn){
                    if(p[i].arrive < p[idx].arrive) idx = i;
                }

            }
        }
        if(idx == -1){
            counter++;
            continue;
        }else{
            p[idx].rt = (counter-p[idx].arrive);
            counter += p[idx].brust;
            p[idx].compile = counter;
            p[idx].tat = (p[idx].compile-p[idx].arrive);
            p[idx].wt = (p[idx].tat-p[idx].brust);
            p[idx].flag = true;
            avg_rt +=p[idx].rt;
            avg_tat += p[idx].tat;
            avg_wt += p[idx].wt;
            x++;
        }

//        sort(p.begin(),p.end(),[](const sjf &a , const sjf &b){
//            return a.compile < b.compile;
//        });
    }

    cout << endl << endl << "PName\tAv\tBT\tCT\tTAT\tWT\tRT" <<  endl << "___________________________________________________"<<endl;
    for(auto val : p){
        cout << val.name << "\t " << val.arrive << "\t " << val.brust << "\t " << val.compile << "\t " << val.tat << "\t " << val.wt << "\t " << val.rt  << endl;
    }
}



int32_t main() {
   // saklan
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

