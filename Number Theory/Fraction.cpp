class Fraction {
private:
ll numerator, denominator;
ll binpow(ll a, ll b) {
	a %= modulo;
	b %= modulo - 1;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % modulo;
		a = a * a % modulo;
		b >>= 1;
	}
	return res;
}
public:
static ll modulo;
Fraction(ll n = 0, ll d = 1) { numerator = n; denominator = d; }

void reduce() {
	ll x = __gcd(numerator, denominator);
	numerator /= x;
	denominator /= x;

	if (modulo == -1) return;

	numerator %= modulo;
	denominator %= modulo;
}
Fraction operator + (Fraction const f) {
	Fraction ans;
	ans.numerator = numerator * f.denominator + denominator * f.numerator;
	ans.denominator = denominator * f.denominator;
	ans.reduce();
	return ans;
}

Fraction operator * (Fraction const f) {
	Fraction ans;
	ans.numerator = numerator * f.numerator;
	ans.denominator = denominator * f.denominator;
	ans.reduce();
	return ans;
}
Fraction operator / (Fraction const f) {
	Fraction ans;
	ans.numerator = numerator * f.denominator;
	ans.denominator = denominator * f.numerator;
	ans.reduce();
	return ans;
}

ll inverseNotation() {
	ll inverse = binpow(denominator, modulo - 2);
	return numerator * inverse % modulo;
}
operator float() const { return float(numerator) / float(denominator); }
operator double() const { return double(numerator) / double(denominator); }
};
// Make modulo -1 if you don't want it to apply modulo
ll Fraction::modulo = 1000000007;
