class Matrix {
private:

public:
vvi matrix;
static ll modulo;
Matrix(int n, int identity = 0) { 
	matrix = vvi(n, vi(n,0)); 

	if (identity) {
		for (int i = 0; i < n; i++) {
			matrix[i][i] = 1;
		}
	}

}
Matrix(vvi m) { matrix = m; }

int size() {
	return matrix.size();	
}
Matrix operator * (Matrix const m) {
	int sz = size();
	Matrix product(sz);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				if (modulo == -1) {
					product.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
				else {
					product.matrix[i][j] += matrix[i][k] * m.matrix[k][j] % modulo;
					product.matrix[i][j] %= modulo;
				}
			}
		}
	}
	return product;
}

Matrix operator + (Matrix const m) {
	int sz = size();
	Matrix sum(sz);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			sum.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
			if (modulo != -1) sum.matrix[i][j] %= modulo;
		}
	}
	return sum;
}

Matrix operator - (Matrix const m) {
	int sz = size();
	Matrix sum(sz);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			sum.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			if (modulo != -1) sum.matrix[i][j] %= modulo;
		}
	}
	return sum;
}

Matrix binpow(Matrix a, ll b) {
	b %= modulo - 1;	
	Matrix res(a.size(), 1); 
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
};
// Make modulo -1 if you don't want it to apply modulo
ll Matrix::modulo = 1000000007;	
