#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(a % b, a);
}

int gcdExtended(int a, int b, int* x, int* y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcdE = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcdE;
}

void encode() {
	std::string plaintext;
	std::cout << "texto plano:\n";
	std::getline(std::cin, plaintext);
	std::getline(std::cin, plaintext);
	std::cout << "Ingrese la clave K de la siguiente manera:\na b\nc d\nPor ejemplo:\n11 8\n3 7\n";
	std::vector<int> k(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> k[i];
	}
	int n = plaintext.size();
	plaintext.erase(std::remove_if(plaintext.begin(), plaintext.end(), isspace), plaintext.end());
	std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

	if (n % 2) {
		plaintext += 'X';
		n++;
	}

	for (int i = 0; i < n; i += 2) {
		int a1 = plaintext[i] - 'A';
		int a2 = plaintext[i + 1] - 'A';
		std::cout << char((a1 * k[0] + a2 * k[2]) % 26 + 'A');
		std::cout << char((a1 * k[1] + a2 * k[3]) % 26 + 'A');
	}

}

void decode() {
	std::string encodedtext;
	std::cout << "Texto encriptado:\n";
	std::getline(std::cin, encodedtext);
	std::getline(std::cin, encodedtext);
	std::cout << "Ingrese la clave K de la siguiente manera:\na b\nc d\nPor ejemplo:\n11 8\n3 7\n";
	std::vector<int> k(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> k[i];
	}
	int n = encodedtext.size();
	encodedtext.erase(std::remove_if(encodedtext.begin(), encodedtext.end(), isspace), encodedtext.end());
	std::transform(encodedtext.begin(), encodedtext.end(), encodedtext.begin(), ::toupper);

	if (n % 2) {
		encodedtext += 'X';
		n++;
	}

	int detA = k[0] * k[3] - k[1] * k[2];

	if (detA == 0) {
		std::cout << "No invertible porque el detA=0\n";
	}
	else if (gcd(detA, 26) != 1) {
		std::cout << "No invertible porque el gcd(detA,26)!=0\n";
	}
	else {
		std::vector<int> adj = { (k[3]%26+26)%26,(-k[1] % 26 + 26) % 26,(-k[2] % 26 + 26) % 26,(k[0] % 26 + 26) % 26 };
		int x, y;
		gcdExtended(detA, 26, &x, &y);
		int detInv = detInv = (x % 26 + 26) % 26;
		std::vector<int> kInv(4);
		for (int i = 0; i < 4; i++) kInv[i] = detInv * adj[i];
		for (int i = 0; i < n; i += 2) {
			int a1 = encodedtext[i] - 'A';
			int a2 = encodedtext[i + 1] - 'A';
			std::cout << char((a1 * kInv[0] + a2 * kInv[2]) % 26 + 'A');
			std::cout << char((a1 * kInv[1] + a2 * kInv[3]) % 26 + 'A');
		}
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
