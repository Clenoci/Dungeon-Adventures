#ifndef STRENGTHPOTION_HPP
#define STRENGTHPOTION_HPP
#include "Item.hpp"
#include "CombatUnit.hpp"

class StrengthPotion : public Item {
public:
	StrengthPotion();
	void Effect(CombatUnit* target);
private:
};

#endif
