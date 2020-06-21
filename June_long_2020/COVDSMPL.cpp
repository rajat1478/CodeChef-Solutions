  

#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

int flag = 0;

void solve() {
	int n, p;
	cin >> n >> p;
	
	vector<vii> a(n, vii (n, 0));
	
	int x;

	//
	//cin >> x;
	
	int people;
	int counter;
	
	int f = 0;
	
	rr(i, n) {
		cout << 1 <<" " << i + 1 << " "  << 1 <<  " " << i + 1 << " "<< n << endl;
		cin >> x;
		
		people = x;
		counter = 0;
		
		if(people == n) {
			rr(j, n) a[i][j] = 1;
			continue;		
		}
		if(people == 0) {
			continue;
		}
		
		rr(j, n) {
			cout << 1 << " " << i + 1 << " " << j+1 << " " << i + 1 << " " << j+1 << endl;
			cin >> x;
			a[i][j] = x;
			
			if(x == 1) counter++;
			if(counter == people) {
				//f = 1;
				break;
			}
			if(n - j - 1 == people - counter) {
				for(int k = j + 1; k < n; k++) {
					a[i][k] = 1;
				}
				break;
			}
		}
	}
	
	cout << 2 << endl;
	
	rr(i, n) {
		rr(j, n) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	cin >> x;
	
	if(x == -1) {
		flag = 1;
	}
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
		if(flag == 1) break;
	}
    return 0;
}
