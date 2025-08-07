#include <iostream>
#include <stdexcept>
#include "Player.h"

int main()
{
	Player *p = new Player("Shoham","123");
	std::cout << p->toString() << std::endl;
	delete p;
}