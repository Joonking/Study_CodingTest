//09. 3003번 문제 (킹, 퀸, 룩, 비숍, 나이트, 폰)

#include <iostream>

int main()
{
	int Chess[6] = { 1, 1, 2, 2, 2, 8 };
	int InChess[6];

	for (int i = 0; i < 6; i++)
	{
		std::cin >> InChess[i];
	}

	for (int i = 0; i < 6; i++)
	{
		std::cout << Chess[i] - InChess[i] << " ";
	}
}