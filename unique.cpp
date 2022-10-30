#include<iostream>
#include<unordered_set>
using namespace std;

class Unique{

	unordered_set<string> result ;
	string str;

	public:	
	Unique(string _str){ str = _str ; }
	int distinctSubstring()
	{

		cout << endl;
		for (int i = 0; i <= str.length(); i++)
		{	
			for (int j = 1; j <= str.length()-i; j++)
			{

				result.insert(str.substr(i, j));
				cout << str.substr(i,j) << " " ;
			}	
			cout << endl;
		}
		return result.size();
	}
	unordered_set<string>& getset(){
		return result;
	}
};

int main()
{
	Unique uu("aabcd");
	cout << uu.distinctSubstring();
	unordered_set<string> _set = uu.getset();
	cout << endl;
	for(auto str:_set) cout << str << " ";
	cout << endl;
	return 0;

}


