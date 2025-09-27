#include <iostream>
#include <cmath>

using namespace::std;
int main() {
	float x, n;
	cin >> x >> n;
	float y = pow(x, 1 / n);
	cout << y;
	return 0;
}