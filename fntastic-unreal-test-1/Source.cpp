#include <iostream>
#include <string> 
#include <algorithm>
#include <cctype>

using namespace std;

string convert(string str)
{
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); } );
	string result = str;
	for (char& ch : str) {
		int num_occurrences = count(str.begin(), str.end(), ch);
		if (num_occurrences > 1) {
			replace(result.begin(), result.end(), ch, ')');
		}
		else {
			replace(result.begin(), result.end(), ch, '(');
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	string user_input;
	cout << "Enter string:\n";
	getline(cin, user_input);
	cout << "Result:\n" << convert(user_input);
	cout << endl;

	return 0;
}
