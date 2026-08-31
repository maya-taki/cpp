//phonebook
//contact

//add
//search
//exit

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class contact {
	private: 
		string first_name;
		string last_name;
		string nickname;
		string secret;
	public:
		void setFirstName(string name) {first_name = name; }
		string getFirstName(void) const {return first_name; }

		void setLastName(string name) {last_name = name; }
		string getLastName(void) const {return last_name; }
		
		void setNickName(string name) {nickname = name; }
		string getNickName(void) const {return nickname; }
		
		void setsecret(string name) {secret = name; }
		string getsecret(void) const {return secret; }
};

// class phoneBook {
// 	public: ;
// };

void	welcomeTitle() {
	cout << "=================================" << endl;
	cout << "Welcome to the AWESOME phonebook!" << endl;
	cout << "=================================" << endl;
	cout << "Please type the desired outputs:" << endl;
	cout << "ADD:	save a new contact" << endl;
	cout << "SEARCH:	display a specific contact" << endl;
	cout << "EXIT:	quit the program" << endl;
	cout << "=================================" << endl;
}

int	parseInput(string input) {
	if (input == "ADD")
	{
		cout << "first name, last name, nickname & secret" << endl;
		return (0);
	}
	else if (input == "SEARCH")
	{
		cout << "search contact" << endl;
		return (0);
	}
	else if (input == "EXIT")
	{
		exit (1);
	}
	cout << "wrong input" << endl;
	exit (1);
}


int	main(int argc, char **argv) {
	if (argc == 1)
	{
		cout << "please type ADD, SEARCH or EXIT" << endl;
		return (1);
	}
	else if (argc == 2)
		parseInput(argv[1]);
	else
	{
		cout << "too many args" << endl;
		return (1);
	}
	welcomeTitle();
	return (0);
}