#include <iostream>
#include <stdexcept>
#include "Player.h"

int main()
{
	Player *p = new Player("Shoham");
	std::cout << p->toString() << std::endl;
	delete p;
}