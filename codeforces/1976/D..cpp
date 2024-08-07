#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segment_tree {
  public:
    segment_tree() : segment_tree(0) {}
    explicit segment_tree(int n) : segment_tree(std::vector<S>(n, e())) {}
    explicit segment_tree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        if (!(0 <= l && l <= r && r <= _n)) {
            cerr << l << " " << r << "\n";
        }
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct S {
    int min_pre, sum;
};

// basic operation
S op(S a, S b) {
    return {min(a.min_pre, a.sum + b.min_pre), a.sum + b.sum};
}

// op(anything, e()) = anything
S e() {
    return {0, 0};
}

// Functions:
// seg.set(int p, S x) => a[p] := x
// seg.get(int p) => a[p]
// seg.prod(int l, int r) => op(a[l], ..., a[r - 1])
// seg.all_prod() => op(a[0], ..., a[n - 1])
// seg.min_left<cnd>(int r) => minimum l such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true
// seg.max_right<cnd>(int r) => maximum r such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    vector<int> p(n + 1);
    vector<vector<int>> ps(n + 1);
    segment_tree<S, op, e> seg(n + 1);
    ps[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '(') {
            p[i] = p[i - 1] + 1;
            seg.set(i, {-1, -1});
        }
        else {
            p[i] = p[i - 1] - 1;
            seg.set(i, {1, 1});
        }
        ps[p[i]].push_back(i);
        // cerr << p[i] << " " << i << "\n";
    }
    for (int i = 1; i < n; ++i) {
        // if (i != 2) {
        //     continue;
        // }
        if (p[i - 1] + seg.prod(i, i + 2).min_pre < 0) {
            continue;
        }
        int l = 1, r = (n - i + 1) / 2, m;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (p[i - 1] + seg.prod(i, i + m * 2).min_pre < 0) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        // for (int j : ps[p[i - 1]]) {
        //     cerr << j << " ";
        // }
        // cerr << " !!!\n";
        int l1 = 0, r1 = ps[p[i - 1]].size() - 1, m1;
        int l2 = 0, r2 = ps[p[i - 1]].size() - 1, m2;
        while (l1 < r1) {
            m1 = l1 + (r1 - l1) / 2;
            if (ps[p[i - 1]][m1] < i - 1) {
                l1 = m1 + 1;
            }
            else {
                r1 = m1;
            }
        }
        // cout << l1 << "!\n";
        while (l2 < r2) {
            m2 = l2 + (r2 - l2) / 2 + 1;
            if (ps[p[i - 1]][m2] < i + l * 2) {
                l2 = m2;
            }
            else {
                r2 = m2 - 1;
            }
        }
        // cout << l2 << "!!\n";
        ans += l2 - l1;
        // cout << i << " adds " << l2 - l1 << "\n";
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}