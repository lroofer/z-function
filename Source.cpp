#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

/*
	Одна из задач - найти все вхождения p в s
	t = p + '$' + s
	Построим ее z - функцию
	Теперь можем сказать, что если z[i] = |p|, то 
	подстрока длины |p|, которая начинается в i равна p
	p входит в s с позиции i - |p| - 1
*/

/*
	Саму z-функцию будем считать слева направо для всех i
	от 1 до n
	Возьмем позицию i, будем хранить блок
	l...r, где l...r - префикс строки, и r - max
	l, r: s[l...r-1] = s[0..r-l-1]
	l < i, r - max
	Пусть предыдущие z посчитаны --> найдем l и r
	z[1...i-1] - посчитано
	Найдем l и r:
	r = l + z[l] // r = левая граница + максимальный префикс, начинающийся с l
	r = max(l + z[l]), где l пробегается от 1 до i - 1
	z[i] = z[i-l], если i + z[i-l] < r
	if >: z[i] = r - i
	else: z[i] = r - i, while s[i+z[i]] = s[z[i]]: z[i]++
*/

vector<ll> z(string s) {
	ll n = s.size();
	ll l = 0, r = 0;
	vector<ll> z(n);
	for (int i = 1; i < n; ++i) {
		if (r >= i) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}
ostream& operator << (ostream& out, vector<ll>& p) {
	for (int i = 0; i < p.size(); ++i) out << p[i] << " ";
	out << "\n";
	return out;
}
int main() {
	string s;
	cin >> s;
	vector<ll> a = z(s);
	cout << a;
	return 0;
}