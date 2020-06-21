#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool ans2(ll a, ll b, ll c, ll p, ll q, ll r)
{
	if(a == p || b == q || c == r)
		return true;

	if((a - p == b - q) || (b - q == c - r) || (a - p == c- r))
		return true;

	if(a != 0 && b != 0 && p % a == 0 && q % b == 0 && p/a == q/b)return true;
	if(a != 0 && c != 0 && p % a == 0 && r % c == 0 && p/a == r/c)return true;
	if(b != 0 && c != 0 && q % b == 0 && r % c == 0 && q/b == r/c)return true;
	
	if((a - p + b - q == c - r) || (a - p + c - r == b - q) || (b - q + c - r == a - p))
		return true;

	if(a != 0 && b != 0 && c != 0)
	{
		if(p % a == 0 && q % b == 0 && r % c == 0)
		{
			ll ra = p/a;
			ll rb = q/b;
			ll rc = r/c;
			if(ra == rb * rc || rb == ra * rc || rc == ra * rb)
				return true;
		}
	}

	//ax + y = p, bx + y = q, cx + z = r 
	if((p - q) * (b - c) == (q - r) * (a - b) && (q - r) * (a - c) == (p - r) * (b - c) && (p - q) * (a - c) == (p - r) * (a - b))
	{
		ll num = (q - r);
		ll den = (b - c);
		ll x;
		if(den != 0 && num % den == 0)
		{
			x = num/den;
			ll y1 = p - a * x;
			ll y2 = q - b * x;
			ll y3 = r - c * x;
// 			cout<<x<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
			if(y1 == y2 && y2 == y3 && a * x + y1 == p && b * x + y2 == q && c * x + y3 == r)
				return true;
		}
	}
	
	//ax + y = p, bx + y = q, c + y = r
	if((a * q - p * b == (r -c) * (a- b) && (p - r + c) * (a - b) == a * (p - q) && ((p - r + c) * b == (q - r + c) * a)))
	{
		ll num = p - q;
		ll den = a - b;

		ll x;
		if(den != 0 && num % den == 0)
		{
			x = num/den;

			ll y1 = p - a * x;
			ll y2 = q - b * x;
			ll y3 = r - c;
// 			cout<<x<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
			if(y1 == y2 && y2 == y3 && a * x + y1 == p && b * x + y2 == q && c + y3 == r)
				return true;
		}
	}
	//ax + y = p, b + y = q, cx + y = r
	if(((p - r) * a == (p - q + b) * (a - c) && (r - q + b) * a == (p - q + b) * c) && (a * r - p * c) == (q - b) * (a - c))
	{
		ll num = p - r;
		ll den = a - c;

		ll x;
		if(den != 0 && num % den == 0)
		{
			x = num/den;

			ll y1 = p - a * x;
			ll y2 = q - b;
			ll y3 = r - c * x;
// 			cout << x << " " <<  y1 <<" "<< y2 << " "<<y3<<endl;
			if(y1 == y2 && y2 == y3 && a * x + y1 == p && b + y2 == q && c * x + y3 == r)
				return true;
		}
	}
	//a + y = p, bx + y = q, cx + y = r
	if((p - a) * (b - c) == (b * r - q * c) && (q + a - p) * (b - c) == (q - r) * b && (r - p + a) * b == (q - p + a) * c)
	{
		ll num = q - r;
		ll den = b - c;

		ll x;
		if(den != 0 && num % den == 0)
		{
			x = num/den;

			ll y1 = p - a;
			ll y2 = q - b * x;
			ll y3 = r - c * x;
// 			cout << x << " " <<  y1 <<" "<< y2 << " "<<y3<<endl;

			if(y1 == y2 && y2 == y3 && a + y1 == p && b * x + y2 == q && c * x + y3 == r)
				return true;
		}
	}

	if(a != 0 && b != 0 && c != 0 && (r % c == 0 || q % b == 0 || p % a == 0))
	{
		//ax + y = p, bx + y = q, cx = r
// 		cout<<"case 10a: "<<endl;
		if(r * (a - b) == (p - q) * c)
		{
			if(c != 0 && r % c == 0)
			{
				ll x1 = r/c;
				ll num = p - q;
				ll den = a - b;
				if(den != 0 && num % den == 0 && x1 == num/den)
				{
					ll y1 = p - a * x1;
					ll y2 = q - b * x1;
					ll y3 = r - c * x1;
				// 	cout<<x1<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
					if(y1 == y2 && y3 == 0 && a * x1 + y1 == p && b * x1 + y2 == q && c * x1 + y3 == r)
						return true;
				}
			}
		}
		//ax = p, bx + y = q, cx + y = r
		if(a * (q - r) == p * (b - c))
		{
			if(a != 0 && p % a == 0)
			{
				ll x1 = p/a;
				ll num = q - r;
				ll den = b - c;
				if(den != 0 && num % den == 0 && x1 == num/den)
				{
					ll y1 = p - a * x1;
					ll y2 = q - b * x1;
					ll y3 = r - c * x1;
				// 	cout<<x1<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
					if(y3 == y2 && y1 == 0 && a * x1 + y1 == p && b * x1 + y2 == q && c * x1 + y3 == r)
						return true;
				}
			}
		}
		//ax + y = p, bx = q, cx + y = r
		if(q * (a - c) == b * (p - r))
		{
			if(b != 0 && q % b == 0)
			{
				ll x1 = q/b;
				ll num = p - r;
				ll den = a - c;
				if(den != 0 && num % den == 0 && x1 == num/den)
				{
					ll y1 = p - a * x1;
					ll y2 = q - b * x1;
					ll y3 = r - c * x1;
					if(y1 == y3 && y2 == 0 && a * x1 + y1 == p && b * x1 + y2 == q && c * x1 + y3 == r)
						return true;
				}
			}
		}
	}
	//ax + y = p, bx = q, c + y = r
	if((q * a == b * (p - r + c) && (p * b - a * q) == b * (r - c)))
	{
		if(b != 0 && q % b == 0)
		{
			ll x1 = q/b;
			ll num = p - r + c;
			ll den = a;
			if(den != 0 && num % den == 0 && num/den == x1)
			{
				ll y1 = p - a * x1;
				ll y2 = q - b * x1;
				ll y3 = r - c;
				// cout<<x1<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
				if(y3 == y1 && y2 == 0 && a * x1 + y1 == p && b * x1 + y2 == q && c + y3 == r)
					return true;
			}
		}
	}
	//ax = p, b + y = q, cx + y = r
	if((p * c == a * (r - q + b) && a * (q - b) == a * r - c * p))
	{
		if(a != 0 && p % a == 0)
		{
			ll x1 = p/a;
			ll num = r - q + b;
			ll den = c;
			if(den != 0 && num % den == 0 && num/den == x1)
			{
				ll y1 = p - a * x1;
				ll y2 = q - b;
				ll y3 = r - c * x1;
				if(y2 == y3 && y1 == 0 && a * x1  == p && b + y2 == q && c * x1 + y3 == r)
					return true;
			}
		}
	}
	//ax = p, bx + y = q, c + y = r
	if((p * b == a * (q - r + c) && (a * q - b * p) == a * (r - c)))
	{
		if(a != 0 && p % a == 0)
		{
			ll x1 = p/a;
			ll num = q - r + c;
			ll den = b;
			if(den != 0 && num % den == 0 && num/den == x1)
			{
				ll y1 = p - a * x1;
				ll y2 = q - b * x1;
				ll y3 = r - c;
				// cout<<x1<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
				if(y3 == y2 && a * x1 + y1 == p && b * x1 + y2 == q && c + y3 == r)
					return true;
			}
		}
	}
	//a + y = p, bx = q, cx + y = r
	if((q * c == b * (r - p + a) && b * (p - a) == b * r - c * q))
	{
		if(b != 0 && q % b == 0)
		{
			ll x1 = q/b;
			ll num = r - p + a;
			ll den = c;
			if(den != 0 && num % den == 0 && num/den == x1)
			{
				ll y1 = p - a;
				ll y2 = q - b * x1;
				ll y3 = r - c * x1;

				if(y1 == y3 && y2 == 0 && a  + y1 == p && b * x1 + y2 == q && c * x1 + y3 == r)
					return true;
			}
		}
	}
	//ax + y = p, b + y = q , cx = r
	if( (r * a == (p - q + b) * c && (q - b) * c == (c * p - a * r)))
	{
		if(c != 0 && r % c == 0)
		{
			ll x1 = r/c;
			ll num = p - q + b;
			ll den = a;
			if(den != 0 && num % den == 0 && num/den == x1)
			{
				ll y1 = p - a * x1;
				ll y2 = q - b;
				ll y3 = r - c * x1;

				if(y1 == y2 && y3 == 0 && a * x1 + y1 == p && b + y2 == q && c * x1 + y3 == r)
					return true;
			}
		}
	}
	//a + y = p, bx + y = q, cx = r
	if((c * (q - p + a) == b * r && c != 0 && c * (p - a) == q * c - b * r))
	{
		if(c != 0 && r % c == 0)
		{
			ll x1 = r/c;
			ll num = q - p + a;
			ll den = b;
			if(den != 0 && num % den == 0 && num/den == x1)
			{
				ll y1 = p - a;
				ll y2 = q - b * x1;
				ll y3 = r - c * x1;
				// cout<<x1<<" "<<y1<<" "<<y2<<" "<<y3<<endl;

				if(y1 == y2 && y3 == 0 && a + y1 == p && b * x1 + y2 == q && c * x1 == r)
					return true;
			}
		}		
	}
	// (a + x)y =p, (b + x)y = q, (c + x)y = r
	if((p - q) * (b - c) == (q - r) * (a - b) && (p - r) * (b - c) == (q - r) * (a - c))
	{
		ll num = a * q - b * p;
		ll den = p - q;
		if(den != 0 && num % den == 0)
		{
			ll x1 = num/den;
			num = b * r - q * c;
			den = q - r;
			if(den != 0 && num % den == 0)
			{
				ll x2 = num/den;
				num = a * r - q * c;
				den = p - r;
				if(den != 0 && num % den == 0)
				{
					ll x3 = num/den;
					if(x1 == x2 && x2 == x3)
					{
						num = p - q;
						den = a - b;
						if(den != 0 && num % den == 0)
						{
							ll y1 = num/den;
							num = q - r;
							den = b - c;
							if(den != 0 && num % den == 0)
							{
								ll y2 = num/den;
								num = p - r;
								den = a - c;
								if(den != 0 && num % den == 0)
								{
									ll y3 = num/den;
								// 	cout<<x1<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
									if(y1 == y2 && y2 == y3 && (a + x1) * y1 == p && (b + x2) * y2 == q && (c + x3) * y3 == r)
										return true;
								}
							}
						}
					}
				}
			}
		}
	}
	// (a + x)y = p, (b + x)y = q, cy = r
	if((r * (a - b) == c * (p - q) && r * (a - b) == c * (p - q)))
	{
		if(c != 0 && r % c == 0)
		{
			ll y1 = r/c;
			ll num = p - q;
			ll den = a - b;
			if(den != 0 && num % den == 0 && num/den == y1)
			{
				if(y1 != 0 && p % y1 == 0)
				{
					ll x1 = p/y1 - a;
					if(q % y1 == 0)
					{
						ll x2 = q/y1 - b;
						ll x3 = r - c * y1;
						if(x1 == x2 && x3 == 0 &&(a + x1) * y1 == p && (b + x1) * y1 == q && c * y1 == r)
							return true;
					}
				}
			}
		}
	}
	// (a + x)y = p, by = q, (c + x)y = r
	if((q * (a - c) == b * (p - r) && q * (a - c) == b * (p - r)))
	{
		if(b != 0 && q % b == 0)
		{
			ll y1 = q/b;
			ll num = p - r;
			ll den = a - c;
			if(den != 0 && num % den == 0 && num/den == y1)
			{
				if(y1 != 0 && p % y1 == 0)
				{
					ll x1 = p/y1 - a;
					if(r % y1 == 0)
					{
						ll x3 = r/y1 - c;
						ll x2 = q - b * y1;
						if(x1 == x3 && x2 == 0 && (a + x1) * y1 == p && b * y1 == q && (c + x1) * y1 == r)
							return true;
					}
				}
			}
		}
	}
	// ay = p, (b + x)y = q, (c + x)y = r
	if((a * (q - r) == p * (b - c) && p * (b - c) == a * (q - r)))
	{
		if(a != 0 && p % a == 0)
		{
			ll y1 = p/a;
			ll num = q - r;
			ll den = b - c;
			if(den != 0 && num % den == 0 && num/den == y1)
			{
				if(y1 != 0 && q % y1 == 0)
				{
					ll x1 = q/y1 - b;
					if(r % y1 == 0)
					{
						ll x2 = r/y1 - c;
						ll x3 = p - a * y1;
						if(x1 == x2 && x3 == 0 && (a + x3) * y1 == p && (b + x1) * y1 == q && (c + x1) * y1 == r)
							return true;
					}
				}
			}
		}
	}
	//(a + x)y = p, (b + x)y = q, (c + x) = r
	if((r - c) * (p - q) == - b * p + a * q && (p - q) * (b + r - c) == q * (a - b))
	{
		ll x1 = r - c;
		ll num = - b * p + a * q;
		ll den = p - q;
		if(den != 0 && num % den == 0 && num/den == x1)
		{
			if(a + x1 != 0 && p % (a + x1) == 0)
			{
				ll y1 = p/(a + x1);

				if(b + x1 != 0 && q % (b  + x1) == 0)
				{
					ll y2 = q/(b + x1);
					if(y1 == y2 && (a + x1) * y1 == p && (b + x1) * y1 == q && c + x1 == r)
						return true;
				}
			}
		}
	}
	//(a + x)y = p, (b + x) = q, (c + x)y = r
	if((p - r) * (q - b) == (a * r - p * c) && p * (a - c) == (p - r) * (a +  q - b))
	{
		ll x1 = q - b;
		ll num = a * r - p * c;
		ll den = p - r;
		if(den != 0 && num % den == 0 && num/den == x1)
		{
			if(a + x1 != 0 && p % (a + x1) == 0)
			{
				ll y1 = p/(a + x1);

				if(c + x1 != 0 && r % (c  + x1) == 0)
				{
					ll y2 = r/(c + x1);
					if(y1 == y2 && (a + x1) * y1 == p && (b + x1) == q && (c + x1) * y1 == r)
						return true;
				}
			}
		}
	}
	//(a + x) = p, (b + x)y = q, (c + x)y = r
	if((p - a) * (q - r) == (b * r - q * c) && (q - r) * (b + p - a) == q * (b - c))
	{
		ll x1 = p - a;
		ll num = b * r - q * c;
		ll den = q - r;
		if(den != 0 && num % den == 0 && num/den == x1)
		{
			if(b + x1 != 0 && q % (b + x1) == 0)
			{
				ll y1 = q/(b + x1);

				if(c + x1 != 0 && r % (c  + x1) == 0)
				{
					ll y2 = r/(c + x1);
					if(y1 == y2 && (a + x1) == p && (b + x1) * y1 == q && (c + x1) * y1 == r)
						return true;
				}
			}
		}
	}
	// (a + x)y = p, b + x = q, cy = r
	if((r * (q - b) == p * c - a * r && r * (a + q - b) == c * p))
	{
		ll x1 = q - b;
		ll y1;
		if(c != 0 && r % c == 0)
		{
			y1 = r/c;
			ll num = p;
			ll den = a + q - b;
			if(den != 0 && num % den == 0 && num/den == y1 && (a + x1) * y1 == p && (b + x1) == q && c * y1 == r)
				return true;
		}
	}
	//(a + x)y = p, by = q, c + x = r
	if((q * (r - c) == b * p - q * a && q * (a + r - c) == p * b))
	{
		ll x1 = r - c;
		if(b != 0 && q % b == 0)
		{
			ll y1 = q/b;
			ll num = p;
			ll den = a + r - c;
			if(den != 0 && num % den == 0 && num/den == y1 && (a + x1) * y1 == p && b * y1 == q && c + x1 == r)
				return true;
		}
	}
	//a + x = p, (b + x)y = q, cy = r
	if((r * (p - a) == q * c - b * r && r * (p + b - a) == q * c))
	{
		ll x1 = p - a;
		if(c != 0 && r % c == 0)
		{
			ll y1 = r/c;

			ll num = q;
			ll den = b + p - a;

			if(den != 0 && num % den == 0 && num/den == y1 && a + x1 == p && (b + x1) * y1 == q && c * y1 == r)
				return true;
		}
	}
	//ay = p, (b + x)y = q, c + x = r
	if((p * (r - c) == a * q - b * p && p * (b + r - c) == a * q))
	{
		ll x1 = r - c;
		if(a != 0 && p % a == 0)
		{
			ll y1 = p/a;

			ll num = q;
			ll den = b + r - c;

			if(den != 0 && num % den == 0 && num/den == y1 && a * y1 == p && (b + x1) * y1 == q && c + x1 == r)
				return true;
		}
	}
	//ay = p, b + x = q, (c + x)y = r
	if(((q - b) * p == a * r - c * p && p * (c + q - b) == a * r))
	{
		ll x1 = q - b;
		if(a != 0 && p % a == 0)
		{
			ll y1 = p/a;
			ll num = r;
			ll den = c + q - b;
			if(den != 0 && num % den == 0 && num/den == y1 && a * y1 == p && b + x1 == q && (c + x1) * y1 == r)
				return true;
		}
	}
// 	cout<<"Case 29: "<<endl;
	//a + x = p, by = q, (c + x)y = r
	if((q * (c + p - a) == b * r && q * (p - a) == r * b - q * c))
	{
		ll x1 = p - a;
		if(b != 0 && q % b == 0)
		{
			ll y1 = q/b;
			ll num = r;
			ll den = c + p - a;
			if(den != 0 && num % den == 0 && num/den == y1 && a + x1 == p && b * y1 == q && (c + x1) * y1 == r)
				return true;
		}
	}
	return false;
}

bool ans1(ll a, ll b, ll c, ll p, ll q, ll r)
{
  if(a - p == b - q && b - q == c - r)
    return true;
  if(a != 0 && b != 0 && c != 0 && p % a == 0 && q % b == 0 && r % c == 0 && p/a == q/b && q/b == r/c)
    return true;
  if((a == p && b == q && c != r) || (a != p && b == q && c == r) || (a == p && b != q && c == r))
    return true;
  if(a == p || b == q || c == r)
  {
    if(a == p)
    {
      if(b - q == c - r)return true;
      if(b != 0 && c != 0 && q % b == 0 && r % c == 0 && q/b == r/c)return true;
    }
    if(b == q)
    {
      if(a - p == c - r)return true;
      if(a != 0 && c != 0 && r % c == 0 && p % a == 0 && r/c == p/a)return true;
    }
    if(c == r)
    {
      if(a - p == b - q)return true;
      if(a != 0 && b != 0 && p % a == 0 && q % b == 0 && p/a == q/b)return true;
    }
  }
  return false;
}

int main()
{
	int t;
	ll a, b, c, p, q, r;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c >> p >> q >> r;

		if(a == p && b == q && c == r)
		{
			cout<<"0"<<endl;
			continue;
		}

		if(ans1(a, b, c, p , q, r))
		{
			cout<<"1"<<endl;
			continue;
		}

		if(ans2(a, b, c, p, q, r))
		{
			cout<<"2"<<endl;
			continue;
		}
		cout<<"3"<<endl;
	}
	return 0;
}
