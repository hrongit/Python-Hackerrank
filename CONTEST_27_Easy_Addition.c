#Ques Link - https://www.hackerrank.com/contests/int213-contest27/challenges/easy-addition

#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
typedef struct _lnode
{
    int x;
    int w;
    struct _lnode *next;
}lnode;
typedef struct _data
{
    long long term10_fa;
    long long term20_fa;
    long long term21_fa;
    long long term30_fa;
    long long term31_fa;
    long long term32_fa;
    long long term10_ia;
    long long term20_ia;
    long long term21_ia;
    long long term30_ia;
    long long term31_ia;
    long long term32_ia;
    long long term10_fs;
    long long term20_fs;
    long long term21_fs;
    long long term30_fs;
    long long term31_fs;
    long long term32_fs;
    long long term10_is;
    long long term20_is;
    long long term21_is;
    long long term30_is;
    long long term31_is;
    long long term32_is;
}data;
int N, R, RI, DP[18][100000], level[100000];
long long s[100000], dis[100000], Rp[100005], IRp[100005];
lnode *table[100000] = {0};
data tree[100000] = {0};
void insert_edge(int x, int y, int w)
{
    lnode *t = malloc(sizeof(lnode));
    t -> x = y;
    t -> w = w;
    t -> next = table[x];
    table[x] = t;
    t = malloc(sizeof(lnode));
    t -> x = x;
    t -> w = w;
    t -> next = table[y];
    table[y] = t;
    return;
}
void preprocess()
{
    int i, j;
    level[0] = 0;
    DP[0][0] = 0;
    dfs0(0);
    for( i = 1 ; i < 18 ; i++ )
    {
        for( j = 0 ; j < N ; j++ )
        {
            DP[i][j] = DP[i-1][DP[i-1][j]];
        }
    }
    return;
}
int lca(int a, int b)
{
    int i;
    if( level[a] > level[b] )
    {
        i = a;
        a = b;
        b = i;
    }
    int d = level[b] - level[a];
    for( i = 0 ; i < 18 ; i++ )
    {
        if( d & ( 1 << i ) )
        {
            b = DP[i][b];
        }
    }
    if( a == b )
    {
        return a;
    }
    for( i = 17 ; i >= 0 ; i-- )
    {
        if( DP[i][a] != DP[i][b] )
        {
            a = DP[i][a], b = DP[i][b];
        }
    }
    return DP[0][a];
}
void dfs0(int u)
{
    lnode *x;
    for( x = table[u] ; x ; x = x -> next )
    {
        if( x -> x != DP[0][u] )
        {
            DP[0][x -> x] = u;
            level[x -> x] = level[u] + 1;
            dfs0(x -> x);
        }
    }
    return;
}
void dfs1(int u)
{
    lnode *x;
    for( x = table[u] ; x ; x = x -> next )
    {
        if( x -> x != DP[0][u] )
        {
            dfs1(x -> x);
            tree[u].term10_fa = ( tree[u].term10_fa + tree[x -> x].term10_fa * R ) % MOD;
            tree[u].term10_ia = ( tree[u].term10_ia + tree[x -> x].term10_ia * RI ) % MOD;
            tree[u].term10_fs = ( tree[u].term10_fs + tree[x -> x].term10_fs * R ) % MOD;
            tree[u].term10_is = ( tree[u].term10_is + tree[x -> x].term10_is * RI ) % MOD;
            tree[u].term20_fa = ( tree[u].term20_fa + tree[x -> x].term20_fa * R ) % MOD;
            tree[u].term21_fa = ( tree[u].term21_fa + ( tree[x -> x].term21_fa + tree[x -> x].term20_fa ) * R ) % MOD;
            tree[u].term20_ia = ( tree[u].term20_ia + tree[x -> x].term20_ia * RI ) % MOD;
            tree[u].term21_ia = ( tree[u].term21_ia + ( tree[x -> x].term21_ia - tree[x -> x].term20_ia + MOD ) * RI ) % MOD;
            tree[u].term20_fs = ( tree[u].term20_fs + tree[x -> x].term20_fs * R ) % MOD;
            tree[u].term21_fs = ( tree[u].term21_fs + ( tree[x -> x].term21_fs + tree[x -> x].term20_fs ) * R ) % MOD;
            tree[u].term20_is = ( tree[u].term20_is + tree[x -> x].term20_is * RI ) % MOD;
            tree[u].term21_is = ( tree[u].term21_is + ( tree[x -> x].term21_is - tree[x -> x].term20_is + MOD ) * RI ) % MOD;
            tree[u].term30_fa = ( tree[u].term30_fa + tree[x -> x].term30_fa * R ) % MOD;
            tree[u].term31_fa = ( tree[u].term31_fa + ( tree[x -> x].term31_fa + tree[x -> x].term30_fa ) * R ) % MOD;
            tree[u].term32_fa = ( tree[u].term32_fa + ( tree[x -> x].term32_fa + 2 * tree[x -> x].term31_fa + tree[x -> x].term30_fa ) * R ) % MOD;
            tree[u].term30_ia = ( tree[u].term30_ia + tree[x -> x].term30_ia * RI ) % MOD;
            tree[u].term31_ia = ( tree[u].term31_ia + ( tree[x -> x].term31_ia - tree[x -> x].term30_ia + MOD ) * RI ) % MOD;
            tree[u].term32_ia = ( tree[u].term32_ia + ( tree[x -> x].term32_ia - 2 * tree[x -> x].term31_ia + tree[x -> x].term30_ia + 2 * MOD ) * RI ) % MOD;
            tree[u].term30_fs = ( tree[u].term30_fs + tree[x -> x].term30_fs * R ) % MOD;
            tree[u].term31_fs = ( tree[u].term31_fs + ( tree[x -> x].term31_fs + tree[x -> x].term30_fs ) * R ) % MOD;
            tree[u].term32_fs = ( tree[u].term32_fs + ( tree[x -> x].term32_fs + 2 * tree[x -> x].term31_fs + tree[x -> x].term30_fs ) * R ) % MOD;
            tree[u].term30_is = ( tree[u].term30_is + tree[x -> x].term30_is * RI ) % MOD;
            tree[u].term31_is = ( tree[u].term31_is + ( tree[x -> x].term31_is - tree[x -> x].term30_is + MOD ) * RI ) % MOD;
            tree[u].term32_is = ( tree[u].term32_is + ( tree[x -> x].term32_is - 2 * tree[x -> x].term31_is + tree[x -> x].term30_is + 2 * MOD ) * RI ) % MOD;
        }
    }
    s[u] = ( tree[u].term10_fa + tree[u].term10_ia - tree[u].term10_fs - tree[u].term10_is + 2 * MOD ) % MOD;
    s[u] = ( s[u] + tree[u].term21_fa + tree[u].term21_ia - tree[u].term21_fs - tree[u].term21_is + 2 * MOD ) % MOD;
    s[u] = ( s[u] + tree[u].term32_fa + tree[u].term32_ia - tree[u].term32_fs - tree[u].term32_is + 2 * MOD ) % MOD;
    return;
}
void dfs2(int u)
{
    lnode *x;
    if( u != DP[0][u] )
    {
        dis[u] = ( s[u] + dis[DP[0][u]] ) % MOD;
    }
    else
    {
        dis[u] = s[u];
    }
    for( x = table[u] ; x ; x = x -> next )
    {
        if( x -> x != DP[0][u] )
        {
            dfs2(x -> x);
        }
    }
    return;
}
long long modInverse(long long a, long long mod)
{
    long long b0 = mod, t, q;
    long long x0 = 0, x1 = 1;
    while( a > 1 )
    {
        q = a / mod;
        t = mod;
        mod = a % mod;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if( x1 < 0 )
    {
        x1 += b0;
    }
    return x1;
}
int main()
{
    int U, Q, x, y, a1, a2, d1, d2, t1, t2, i;
    long long ans;
    scanf("%d%d", &N, &R);
    for( i = 0 ; i < N - 1 ; i++ )
    {
        scanf("%d%d", &x, &y);
        insert_edge(x-1, y-1, 1);
    }
    preprocess();
    RI = modInverse(R, MOD);
    Rp[0] = IRp[0] = 1;
    for( i = 1 ; i < 100005 ; i++ )
    {
        Rp[i] = Rp[i-1] * R % MOD;
        IRp[i] = IRp[i-1] * RI % MOD;
    }
    scanf("%d%d", &U, &Q);
    while(U--)
    {
        scanf("%d%d%d%d%d%d", &a1, &d1, &a2, &d2, &x, &y);
        i = lca(x-1, y-1);
        t1 = level[x-1] - level[i];
        t2 = level[y-1] - level[i];
        tree[x-1].term10_fa = ( tree[x-1].term10_fa + a1 * (long long)a2 ) % MOD;
        tree[x-1].term20_fa = ( tree[x-1].term20_fa + a1 * (long long)d2 + a2 * (long long)d1 ) % MOD;
        tree[x-1].term30_fa = ( tree[x-1].term30_fa + d1 * (long long)d2 ) % MOD;
        tree[i].term10_fs = ( tree[i].term10_fs + a1 * (long long)a2 % MOD * Rp[t1] ) % MOD;
        tree[i].term20_fs = ( tree[i].term20_fs + ( a1 * (long long)d2 + a2 * (long long)d1 ) % MOD * Rp[t1] ) % MOD;
        tree[i].term21_fs = ( tree[i].term21_fs + ( a1 * (long long)d2 + a2 * (long long)d1 ) % MOD * t1 % MOD * Rp[t1] ) % MOD;
        tree[i].term30_fs = ( tree[i].term30_fs + d1 * (long long)d2 % MOD * Rp[t1] ) % MOD;
        tree[i].term31_fs = ( tree[i].term31_fs + d1 * (long long)d2 % MOD * t1 % MOD * Rp[t1] ) % MOD;
        tree[i].term32_fs = ( tree[i].term32_fs + d1 * (long long)d2 % MOD * t1 % MOD * t1 % MOD * Rp[t1] ) % MOD;
        tree[y-1].term10_ia = ( tree[y-1].term10_ia + a1 * (long long)a2 % MOD * Rp[t1+t2] ) % MOD;
        tree[y-1].term20_ia = ( tree[y-1].term20_ia + ( a1 * (long long)d2 + a2 * (long long)d1 ) % MOD * Rp[t1+t2] ) % MOD;
        tree[y-1].term21_ia = ( tree[y-1].term21_ia + ( a1 * (long long)d2 + a2 * (long long)d1 ) % MOD * ( t1 + t2 ) % MOD * Rp[t1+t2] ) % MOD;
        tree[y-1].term30_ia = ( tree[y-1].term30_ia + d1 * (long long)d2 % MOD * Rp[t1+t2] ) % MOD;
        tree[y-1].term31_ia = ( tree[y-1].term31_ia + d1 * (long long)d2 % MOD * ( t1 + t2 ) % MOD * Rp[t1+t2] ) % MOD;
        tree[y-1].term32_ia = ( tree[y-1].term32_ia + d1 * (long long)d2 % MOD * ( t1 + t2 ) % MOD * ( t1 + t2 ) % MOD * Rp[t1+t2] ) % MOD;
        if(i)
        {
            tree[DP[0][i]].term10_is = ( tree[DP[0][i]].term10_is + a1 * (long long)a2 % MOD * Rp[t1+t2] % MOD * IRp[t2+1] ) % MOD;
            tree[DP[0][i]].term20_is = ( tree[DP[0][i]].term20_is + ( a1 * (long long)d2 + a2 * (long long)d1 ) % MOD * Rp[t1+t2] % MOD * IRp[t2+1] ) % MOD;
            tree[DP[0][i]].term21_is = ( tree[DP[0][i]].term21_is + ( a1 * (long long)d2 + a2 * (long long)d1 ) % MOD * ( t1 - 1 + MOD ) % MOD * Rp[t1+t2] % MOD * IRp[t2+1] ) % MOD;
            tree[DP[0][i]].term30_is = ( tree[DP[0][i]].term30_is + d1 * (long long)d2 % MOD * Rp[t1+t2] % MOD * IRp[t2+1] ) % MOD;
            tree[DP[0][i]].term31_is = ( tree[DP[0][i]].term31_is + d1 * (long long)d2 % MOD * ( t1 - 1 + MOD ) % MOD * Rp[t1+t2] % MOD * IRp[t2+1] ) % MOD;
            tree[DP[0][i]].term32_is = ( tree[DP[0][i]].term32_is + d1 * (long long)d2 % MOD * ( t1 - 1 + MOD ) % MOD * ( t1 - 1 + MOD ) % MOD * Rp[t1+t2] % MOD * IRp[t2+1] ) % MOD;
        }
    }
    dfs1(0);
    dfs2(0);
    while(Q--)
    {
        scanf("%d%d", &x, &y);
        a1 = lca(x-1, y-1);
        ans = ( dis[x-1] + dis[y-1] - dis[a1] + MOD ) % MOD;
        if(a1)
        {
            ans = ( ans - dis[DP[0][a1]] + MOD ) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}