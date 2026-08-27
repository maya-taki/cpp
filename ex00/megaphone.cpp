#include <iostream>
#include <string>

using namespace std;

int	main(int ac, char *av[])
{
	int	i = 1;

	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (i < ac) 
	{
		string s = av[i];
		for (int j = 0; j < (int)s.size(); j++)
		{
			cout << (char)toupper(s[j]);
		}
		i++;
	}
	cout << endl;
	return (0);
}
