#define MOD (ll)(1e9 + 7)
typedef long long ll;
const int N = 1000001;
ll factinverse[N + 1], inverse[N + 1], fact[N + 1];
ll binomial(ll N, ll R) {
    return (R > N) ? 0 : fact[N] * factinverse[R] % MOD * factinverse[N - R] % MOD;
}
void precompute() {
    inverse[0] = inverse[1] = 1;
    for (int i = 2; i <= N; i++)
        inverse[i] = inverse[MOD % i] * (MOD - MOD / i) % MOD;

    factinverse[0] = factinverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factinverse[i] = inverse[i] * factinverse[i - 1] % MOD;

    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;
}
 

