#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


std::vector<std::vector<char>> grid(std::string& key) {
	int nkey = key.size();
	std::vector<bool> letters(25);

	std::vector<std::vector<char>> grid(5, std::vector<char>(5));

	int ipos = 0;
	int numj = 9;

	for (int i = 0; i < nkey; i++)
	{
		bool gratherTanJ = false;
		if (key[i] >= 'J')
			gratherTanJ = true;
		int posInArr = key[i] - 'A' - gratherTanJ;
		if (!letters[posInArr]) {
			letters[posInArr] = true;
			grid[ipos / 5][ipos % 5] = key[i];
			ipos++;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		if (!letters[i]) {
			grid[ipos / 5][ipos % 5] = char(i + (i >= numj) + 'A');
			ipos++;
		}
	}

	return grid;
}

std::vector<std::pair<int, int>> gridPos(std::vector<std::vector<char>>& gridkey) {
	std::vector<std::pair<int, int>> pos(26);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pos[gridkey[i][j] - 'A'] = std::pair<char, char>(i, j);
		}
	}
	return pos;
}

void encode() {
	std::string key, plaintext;
	std::cout << "texto plano:\n";
	std::getline(std::cin, plaintext);
	std::getline(std::cin, plaintext);
	std::cout << "clave:\n";
	std::getline(std::cin, key);

	std::cout << "\ntexto cifrado:\n";

	plaintext.erase(std::remove_if(plaintext.begin(), plaintext.end(), isspace), plaintext.end());
	key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
	std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);


	auto gridKey = grid(key);
	auto keyPosInGrid = gridPos(gridKey);

	int nplain = plaintext.size();

	std::list<std::pair<char, char>> plainInPairs;


	for (int i = 0; i < nplain; i++)
	{
		char first = plaintext[i];
		if (first == 'J')
			first = 'I';
		char second = 'X';
		if (i + 1 < nplain && plaintext[i] != plaintext[i + 1]) {
			second = plaintext[i + 1];
			i++;
		}
		plainInPairs.push_back(std::pair<char, char>(first, second));
	}

	//encode
	while (!plainInPairs.empty())
	{
		char first = plainInPairs.front().first;
		char second = plainInPairs.front().second;

		std::pair<int, int> firstCord = keyPosInGrid[first - 'A'];
		std::pair<int, int> secondCord = keyPosInGrid[second - 'A'];

		if (firstCord.second == secondCord.second) {//same colum
			firstCord.first = (firstCord.first + 1) % 5;
			secondCord.first = (secondCord.first + 1) % 5;
		}
		else if (firstCord.first == secondCord.first) {//same row
			firstCord.second = (firstCord.second + 1) % 5;
			secondCord.second = (secondCord.second + 1) % 5;
		}
		else {//else
			std::swap(firstCord.second, secondCord.second);
		}
		std::cout << gridKey[firstCord.first][firstCord.second];
		std::cout << gridKey[secondCord.first][secondCord.second];
		std::cout << ' ';
		plainInPairs.pop_front();
	}

}

void decode() {
	std::string key, encodedText;
	std::cout << "texto a descifrar:\n";
	std::getline(std::cin, encodedText);
	std::getline(std::cin, encodedText);
	std::cout << "clave:\n";
	std::getline(std::cin, key);

	std::cout << "\ntexto descifrado:\n";

	encodedText.erase(std::remove_if(encodedText.begin(), encodedText.end(), isspace), encodedText.end());
	key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
	std::transform(encodedText.begin(), encodedText.end(), encodedText.begin(), ::toupper);
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);


	auto gridKey = grid(key);
	auto keyPosInGrid = gridPos(gridKey);

	int nEncoded = encodedText.size();

	for (int i = 0; i < nEncoded; i += 2)
	{
		char first = encodedText[i];
		char second = encodedText[i + 1];

		std::pair<int, int> firstCord = keyPosInGrid[first - 'A'];
		std::pair<int, int> secondCord = keyPosInGrid[second - 'A'];


		if (firstCord.second == secondCord.second) {//same colum
			firstCord.first = (firstCord.first - 1 + 5) % 5;
			secondCord.first = (secondCord.first - 1 + 5) % 5;
		}
		else if (firstCord.first == secondCord.first) {//same row
			firstCord.second = (firstCord.second - 1 + 5) % 5;
			secondCord.second = (secondCord.second - 1 + 5) % 5;
		}
		else {//else
			std::swap(firstCord.second, secondCord.second);
		}
		char firstOut = gridKey[firstCord.first][firstCord.second];
		char secondOut = gridKey[secondCord.first][secondCord.second];
		if (firstOut == 'I')
			std::cout << "[IJ]";
		else
			std::cout << firstOut;
		if (secondOut == 'I')
			std::cout << "[IJ]";
		else
			std::cout << secondOut;
		std::cout << ' ';
	}

}

int main()
{
	//freopen("inPair2.txt", "r", stdin);
	int option;
	std::cout << "Que desea realizar? \n cifrar(0) \n decifrar(1) \n";
	std::cin >> option;

	if (option)
		decode();
	else
		encode();
	return 0;
}
