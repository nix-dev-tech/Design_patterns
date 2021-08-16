#include<iostream>
#include<sstream>

using namespace std;

int main() {
	auto text = "hello";
	string output;
	output += "<p>";
	output += text;
	output += "</p>";
	cout << output << endl;

	string words[] = { "hello", "world" };
	ostringstream oss;
	oss << "<ul>"<<endl;
	for (auto w : words)
		oss << "   <li>" << w << "</li>"<<endl;
	oss << "</ul>";
	cout << oss.str() << endl;
	return 0;
}
