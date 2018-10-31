#include <iostream>
#include <fstream>
#include "Converter.h"

int main() {
	int userInput;

	Converter converter;

	//Part One
	cout << "Enter value (integer) that will be converted to UTF-8:\n";
	cin >> userInput;

	cout << "Your integer's Unicode Code Point is:\n\n";
	cout << "U+" << converter.convertToHex(userInput) << endl << endl;
	cout << "Your integer's Hexadecimal UTF-8 Code Point is:\n\n";
	cout << converter.convertToHexUTF8(userInput) << endl << endl;

	//Part Two
	basic_ifstream<unsigned char> input("386intel.txt");
	ofstream output("rez.txt");
	unsigned char character;
	while (input) {
		input.get(character);
		if (character < 128) {
			output << character;
		}
		else {
			output << converter.convertFromCodePage437(character);
		}
	}
	input.close();
	output.close();

	system("pause");
	return 0;
}