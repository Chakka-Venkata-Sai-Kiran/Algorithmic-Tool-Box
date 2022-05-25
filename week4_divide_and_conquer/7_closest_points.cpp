#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr double distance(const pair<ll, ll>& a,const pair<ll, ll>& b)
{
	return sqrt((b.first - a.first) * (b.first - a.first) +(b.second - a.second) * (b.second - a.second));
}
bool less_than_on_x(pair<ll, ll>& a,pair<ll, ll>& b)
{
	if(a.first == b.first)
	    return a.second < b.second;
	return a.first < b.first;
}
bool less_than_on_y(pair<ll, ll>& a,pair<ll, ll>& b) {
	if(a.second == b.second)
	    return a.first < b.first ;
	return a.second < b.second;
}
void merge(vector<pair<ll, ll>>& points, ll low,ll high)
{
	if (low >= high) return;
	ll mid = low + (high - low) / 2;
	ll i = low, j = mid + 1;
	vector<pair<ll, ll>> vec;
	vec.reserve(high - low + 1);
	while (i <= mid and j <= high)
	{
		if (less_than_on_y(points[i], points[j])) {
			vec.emplace_back(points[i].first, points[i].second);
			i++;
		} else {
			vec.emplace_back(points[j].first, points[j].second);
			j++;
		}
	}
	while (i <= mid) {
		vec.emplace_back(points[i].first, points[i].second);
		i++;
	}
	while (j <= high) {
		vec.emplace_back(points[j].first, points[j].second);
		j++;
	}
	for (size_t k = 0; k < vec.size(); k++) { points[low + k] = vec.at(k); }
}
double minimal_distance(vector<pair<ll, ll>>& points,
						ll low, ll high) {
	if (low >= high) return numeric_limits<double>::max();
	if (high - low == 1) {
		if (not less_than_on_y(points[low], points[high])) {
			swap(points[low], points[high]);
		}
		return distance(points[low], points[high]);
	}

	ll mid = low + (high - low) / 2;
	auto mid_point = points.at(mid);  // This is important

	double d = min(minimal_distance(points, low, mid),
				   minimal_distance(points, mid + 1, high));

	vector<pair<ll, ll>> strip_points;

	merge(points, low, high);
	for (ll i = low; i <= high; i++) {
		if (abs(points[i].first - mid_point.first) <= d) {
			strip_points.emplace_back(points[i].first, points[i].second);
		}
	}

	for (ll i = 0; i < strip_points.size() - 1; i++) {
		for (ll j = i + 1; j < strip_points.size() and j - i < 8; j++) {
			d = min(d, distance(strip_points[i], strip_points[j]));
		}
	}
	return d;
}

int main()
{
	size_t n;
	cin >> n;
	vector<pair<ll, ll>> points(n);
	ll x, y;
	for (size_t i = 0; i < n; i++) {
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}
	sort(points.begin(), points.end(), &less_than_on_x);
	cout << fixed;
	cout << setprecision(9) << minimal_distance(points, 0, points.size() - 1)
		 << endl;
  return 0;
}
