#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string name;
	string birthday;
	Person(string _name, string _birthday)
	{
		name = _name;
		birthday = _birthday;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	Person youngest("#", "1814/09/05"), oldest("#", "2014/09/07");
	int cnt = 0;
	for( int i = 0; i < n; i++ )
	{
		string name, birthday;
		cin >> name >> birthday;
		if( birthday >= "1814/09/06" && birthday <= "2014/09/06" )
		{
			Person person(name, birthday);
			if( youngest.birthday < person.birthday )
			{
				youngest = person;
			}

			if( oldest.birthday > person.birthday )
			{
				oldest = person;
			}

			cnt++;
		}
	}

	cout << cnt ;
	if( cnt > 0 )
	{
		cout << ' ' << oldest.name << ' ' << youngest.name << '\n';
	}
	return 0;
}
