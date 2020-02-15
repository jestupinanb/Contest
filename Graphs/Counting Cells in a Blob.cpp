#include <iostream>
#include <bits/stdc++.h>

int main()
{
	
	std::string pos1;
	std::string pos2;
	while (std::getline(std::cin,pos1,' ') && !pos1.empty() && std::getline(std::cin, pos2, '\n'))
	{
		bool chess[8][8];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				chess[i][j] = 0;
			}
		}

		int source[2];
		int target[2];

		source[0] = pos1[0] - 97;
		source[1] = pos1[1] - 49;

		target[0] = pos2[0] - 97;
		target[1] = pos2[1] - 49;

		std::list<std::vector<int>> list;

		list.push_back({ source[0], source[1] });

		chess[source[0]][source[1]] = true;

		bool found = false;

		int n = 0;

		while (!list.empty() && !found)
		{
			std::list<std::vector<int>> tempList;
			while (!list.empty() && !found) {
				int row = list.front()[0];
				int col = list.front()[1];
				list.pop_front();

				if (row == target[0] && col == target[1]) {
					std::cout << "To get from " << pos1 << " to " << pos2 << " takes " << n << " knight moves."<<std::endl;
					found = true;
					break;
				}

				for (int i = -2; i <= 2; i += 4)
				{
					for (int j = -1; j <= 1; j += 2)
					{
						int newRow = row + i;
						int newCol = col + j;
						if (newRow >= 0 && newCol >= 0 && newRow < 8 && newCol < 8) {
							if (!chess[newRow][newCol]) {
								chess[newRow][newCol] = true;
								tempList.push_back({ newRow,newCol });
							}
						}
					}
				}

				for (int i = -2; i <= 2; i += 4)
				{
					for (int j = -1; j <= 1; j += 2)
					{
						int newCol = col + i;
						int newRow = row + j;
						if (newRow >= 0 && newCol >= 0 && newRow < 8 && newCol < 8) {
							if (!chess[newRow][newCol]) {
								chess[newRow][newCol] = true;
								tempList.push_back({ newRow,newCol });
							}
						}
					}
				}

			}
			n++;
			list = tempList;
		}
	}
	
}
