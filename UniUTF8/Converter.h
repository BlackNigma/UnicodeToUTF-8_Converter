#pragma once
#include <string>

using namespace std;

class Converter
{
public:

	string convertToHex(int classInput) {

		char hexValue[100];

		_itoa_s(classInput, hexValue, 16);

		return string(hexValue);

	};

	int getBytes(long int classInput) {

		if (classInput < 128) return 1;
		if (classInput < 2048) return 2;
		if (classInput < 65536) return 3;
		if (classInput < 1114112) return 4;
	};

	string convertToHexUTF8(int classInput) {

		int bytes = getBytes(classInput);
		if (bytes == 1) {
			return convertToHex(classInput);
		}

		char binaryValue[100];
		_itoa_s(classInput, binaryValue, 2);
		string binary(binaryValue);

		while (binary.length() <= 11 + (5 * (bytes - 2)))
		{
			binary.insert(binary.begin(), '0');
		}

		for (int i = 0; i < bytes; i++)
		{
			binary.insert(binary.begin(), '1');
		}

		for (int i = 1; i <= bytes--; i++)
		{
			binary.insert(binary.begin() + (i * 8), '0');
			binary.insert(binary.begin() + (i * 8), '1');
		}

		classInput = stoi(binary, nullptr, 2);
		return convertToHex(classInput);
	};

	string convertFromCodePage437(unsigned char character);
};
