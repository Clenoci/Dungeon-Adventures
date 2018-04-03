#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Enemy.hpp"

class Goblin : public Enemy{
	
	public:
		Goblin();
		Goblin(std::string name,int health,int damage);
		


	private:
		int GoblinHealth=15;

};

#endif