#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

struct segtree {
    vector<ll> tree;
    int size;

    void initialize(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, 0);

    }

    void set(int i, int v, int x, int lx, int rx) 
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int mid= = (lx + rx) / 2;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];

    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    ll sum (int l, int r, int x, int lx, int rx)
    {
        if( l >= rx || lx >= r)
        {
            return -1;
        
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        int mid = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, mid);
        ll s2 = sum(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll sum (int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    segtree st;
    st.initialize(n);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x; 
        st.set(i, x);

    }
    for(int t = 0; t < m; t++)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }
    return 0;
}