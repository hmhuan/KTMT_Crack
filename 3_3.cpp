#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char * argv[]) {
	string name;
	int serial;
	ofstream fOut;
	fOut.open("SerialKey.txt", ios_base::app);
	serial = 0x23E;
	do {
		cout << "Input Name: ";
		cin >> name;
	} while (name.length() <= 4);
	fOut << "===============================\nName: " << name << endl;
	if (name.length() > 6)
		name.resize(6);
	for (int i = 0; i < name.length(); i++)
		serial = serial * (name[i] / 5) + name[i];
	cout << "Serial: " << serial << endl;
	fOut << "Serial: " << serial << endl;
	fOut.close();
	return 0;
}