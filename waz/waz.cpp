// waz.cpp: Określa punkt wejścia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>

#ifdef _WIN32
#include <cstdlib>
#endif // _WIN32


int main()
{
	int kratki[20][20];

	std::cout << "Gra w weza. 1 - prawo, 2 - lewo, 3 - dol, 4 - gora\n";

	int last = 0;
	int x = 10, y = 10;

	do {
		if (kratki[x][y] != 1) {
			kratki[x][y] = 1;
			std::cout << "OK\n";
		}
		else {
			std::cout << "Nie ok!\n" << std::endl;
			return 1;
		}

		std::cin >> last;
		
		switch (last)
		{
		case 1:
			x += 1;
			break;
		case 2:
			x -= 1;
		case 3:
			y -= 1;
			break;
		case 4:
			y += 1;
			break;
		default:
			break;
		}

	} while (last <= 4 && last >= 1);

#ifdef _WIN32
	system("PAUSE");
#endif // _WIN32



	return 0;
}

