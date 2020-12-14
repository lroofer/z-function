#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

/*
	Îäíà èç çàäà÷ - íàéòè âñå âõîæäåíèÿ p â s
	t = p + '$' + s
	Ïîñòðîèì åå z - ôóíêöèþ
	Òåïåðü ìîæåì ñêàçàòü, ÷òî åñëè z[i] = |p|, òî 
	ïîäñòðîêà äëèíû |p|, êîòîðàÿ íà÷èíàåòñÿ â i ðàâíà p
	p âõîäèò â s ñ ïîçèöèè i - |p| - 1
*/

/*
	Ñàìó z-ôóíêöèþ áóäåì ñ÷èòàòü ñëåâà íàïðàâî äëÿ âñåõ i
	îò 1 äî n
	Âîçüìåì ïîçèöèþ i, áóäåì õðàíèòü áëîê
	l...r, ãäå l...r - ïðåôèêñ ñòðîêè, è r - max
	l, r: s[l...r-1] = s[0..r-l-1]
	l < i, r - max
	Ïóñòü ïðåäûäóùèå z ïîñ÷èòàíû --> íàéäåì l è r
	z[1...i-1] - ïîñ÷èòàíî
	Íàéäåì l è r:
	r = l + z[l] // r = ëåâàÿ ãðàíèöà + ìàêñèìàëüíûé ïðåôèêñ, íà÷èíàþùèéñÿ ñ l
	r = max(l + z[l]), ãäå l ïðîáåãàåòñÿ îò 1 äî i - 1
	z[i] = z[i-l], åñëè i + z[i-l] < r
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
