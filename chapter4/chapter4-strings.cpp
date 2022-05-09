// strings.cpp -- storing strings in an array
#include <iostream>
#include <cstring>	// for the strlen() function
using namespace std;

const int array_size = 15;

int main(){
	char name1[array_size];			// empty array
	char name2[array_size] = "Wyrm";	// initialized array
	// NOTE: some implementations my require the static keyword 
	// to initialized array name2
	
	cout << "Hello! I'm " << name2;
	cout << "! What's your name?\n";	
	cin >> name1;
	
	cout << "Well, " << name1 << ", Your name has ";
	cout << strlen(name1) << " letters and is stored\n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	
	name2[3] = '\0';
	cout << "Here are the first 3 characters of my name: ";
	cout << name2;
	
	return 0;
} 
