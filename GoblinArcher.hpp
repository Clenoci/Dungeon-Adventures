#ifndef GOBLINARCHER_HPP
#define GOBLINARCHER_HPP

#include "Enemy.hpp"

class GoblinArcher : public Enemy{
	
	public:
		GoblinArcher();
		GoblinArcher(std::string name, int health,int damage);
	private:

};

#endif