#include <bits/stdc++.h>

struct suffix
{
	int index;
	int rank[2];
};

//Element passed as first is cosidered to go before the second
bool cmp(suffix a, suffix b) {
	if (a.rank[0] == b.rank[0]) {
		return (a.rank[1] < b.rank[1]) ? 1 : 0;
	}
	else {
		return (a.rank[0] < b.rank[0]) ? 1 : 0;
	}
}

std::vector<int> buildSuffixArray(std::string& s) {
	int n = s.size();
	std::vector<suffix> suffixes(n);

	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = s[i] - 'a';
		suffixes[i].rank[1] = (i + 1 < n) ? (s[i+1] - 'a') : -1;
	}

	std::sort(suffixes.begin(), suffixes.end(), cmp);

	std::vector<int> indexSuffixies(n);

	//hasta 2*n porque requiere que se realiza hasta que sea del tamaño del arreglo como mucho
	//debido a que se toma k/2
	for (int k = 4; k < 2 * n; k = 2 * k)
	{
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		indexSuffixies[suffixes[0].index] = 0;

		for (int i = 1; i < n; i++)
		{
			if (suffixes[i].rank[0] == prev_rank
				&& suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			indexSuffixies[suffixes[i].index] = i;
		}

		for (int i = 0; i < n; i++)
		{
			int nextIndex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextIndex < n) ? suffixes[indexSuffixies[nextIndex]].rank[0] : -1;
		}

		sort(suffixes.begin(), suffixes.end(), cmp);
	}
	std::vector<int> suffixArr(n);
	for (int i = 0; i < n; i++)
	{
		suffixArr[i] = suffixes[i].index;
	}
	return suffixArr;
}

//ordenados lexicograficamente
//prioridad la letra mas grande, despues el string mas largo
int main()
{
	std::string s="bananna";
	std::vector<int> suffixArray = buildSuffixArray(s);
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			std::cout<<s[suffixArray[i]+j];
		}
		std::cout<<std::endl;
	}
}
