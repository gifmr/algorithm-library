#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

// KUPC 2019 F - カズマ王国の陥落
// https://atcoder.jp/contests/kupc2019/tasks/kupc2019_f
// 解説: https://pione.hatenablog.com/entry/2019/10/17/193931

ll N, A[3005], M, L[3005], R[3005], B[3005];
ll dp[3005];
vector<pll> Monster[3005];
 
signed main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    for(int i = 1; i <= M; i++) {
        cin >> L[i] >> R[i] >> B[i];
        Monster[L[i]].push_back({R[i], B[i]});
    }
    for(int pos = 1; pos <= N; pos++) {
        ll num = 0;
        for(int nowpos = pos; nowpos >= 0; nowpos--) {
            // nowposまでの街に与えられるダメージの総和 + nowpos+1~posの街に与えられるダメージの総和 ← これの最大値をdp[pos]に格納する
            chmax(dp[pos], dp[nowpos] + max(0LL, num - A[pos]));
            for(int j = 0; j < Monster[nowpos].size(); j++) {
                // (nowposがL[i]であるMonsterであるもののうち、) pos <= R[i]を満たすMonsterであるか
                if(Monster[nowpos][j].first >= pos) {
                    // num ... nowposがL[i]であるMonsterの総数. つまり、nowpos ~ posを攻撃できるMonsterの攻撃の総和
                    num += Monster[nowpos][j].second;
                }
            }
        }
        cerr << dp[pos] << endl;
    }
    cout << dp[N] << endl;
    return 0;
}