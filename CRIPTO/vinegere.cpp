#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

void encode() {
	std::string key, plaintext;
	int t;
	std::cout << "texto plano:\n";
	std::getline(std::cin, plaintext);
	std::getline(std::cin, plaintext);
	std::cout << "clave:\n";
	std::cin >> key;
	std::cout << "t:\n";
	std::cin >> t;
	plaintext.erase(std::remove_if(plaintext.begin(), plaintext.end(), isspace), plaintext.end());
	std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);

	int nPlain = plaintext.size();
	int nKey = key.size();

	for (int i = 0; i < nPlain; i++)
	{
		int a = (plaintext[i] - 'A' + key[i % nKey] - 'A') % 26 + 'A';
		std::cout << char(a);
		if ((i + 1) % t == 0)
			std::cout << " ";
	}
}

void decode() {
	std::string key, encodedText;
	int t;
	std::cout << "texto a decodificar:\n";
	std::getline(std::cin, encodedText);
	std::getline(std::cin, encodedText);
	std::cout << "clave:\n";
	std::cin >> key;
	std::cout << "t:\n";
	std::cin >> t;

	encodedText.erase(std::remove_if(encodedText.begin(), encodedText.end(), isspace), encodedText.end());
	std::transform(encodedText.begin(), encodedText.end(), encodedText.begin(), ::toupper);
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);

	int nEncoded = encodedText.size();
	int nKey = key.size();

	for (int i = 0; i < nEncoded; i++)
	{
		int val = std::abs(encodedText[i] - key[i % nKey] + 26) % 26;
		std::cout << char(val + 'A');
		if ((i + 1) % t == 0)
			std::cout << ' ';
	}

}

int main()
{
	int option;
	std::cout << "Que desea realizar? \n cifrar(0) \n decifrar(1) \n";
	std::cin >> option;

	if (option)
		decode();
	else
		encode();
	return 0;
}
