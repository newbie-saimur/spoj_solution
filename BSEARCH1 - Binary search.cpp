#include <bits/stdc++.h>
using namespace std;
#define int    long long
int _;

void solve()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (auto &i : a) cin >> i;
    while (k--) {
        int x; cin >> x;
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] == x) {
                ans = mid;
                r = mid - 1;
            }
            else if (a[mid] < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin>>test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
