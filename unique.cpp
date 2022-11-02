#include<iostream>
#include<unordered_set>
#include<set>
#include<string>
using namespace std;

class Unique{

	unordered_set<string> result ;
	string str;

	public:	
	Unique(string _str){ str = _str ; }

	bool allCharactersSame()
	{
		set <char> s1;

		for ( int i=0 ; i < str.length() ; i++)
			s1.insert(str[i]);
	
		if ( s1.size() == 1 )
			return true;
		else
			return false;;
	}

	int distinctSubstring()
	{
		if(str.length()==0) return 0;
		if(str.length()==1) return 1;

		if(allCharactersSame()) return str.length();

		for (int i = 0; i <= str.length(); i++)
		{	
			for (int j = 1; j <= str.length()-i; j++)
			{

				result.insert(str.substr(i, j));
			}	
		}
		return result.size();
	}
	unordered_set<string>& getset(){
		return result;
	}
};

int main(int argc, char** argv)
{
	if(argc !=2 ) return 1;
	string str(argv[1]);
	Unique uu(str);
	cout << uu.distinctSubstring();
	unordered_set<string> _set = uu.getset();
	cout << endl;
	for(auto str:_set) cout << str << " ";
	cout << endl;
	return 0;

}


