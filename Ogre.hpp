#ifndef OGRE_HPP
#define OGRE_HPP

#include "Enemy.hpp"

class Ogre : public Enemy{
	
	public:
		Ogre();
		Ogre(std::string name, int health, int damage);

	private:
		

};

#endif