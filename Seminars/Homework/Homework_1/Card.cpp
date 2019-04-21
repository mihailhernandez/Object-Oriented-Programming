#include <iostream>
#include <cstring>
#include <cstdlib>

const unsigned int MAX_LENGHT_CARD_NAME = 25;
const unsigned int MIN_ATTACK_POINTS = 0;
const unsigned int MAX_ATTACK_POINTS = 5000;
const unsigned int MIN_DEF_POINTS = 0;
const unsigned int MAX_DEF_POINTS = 5000;

enum Card_Type
{
	MAGIC,
	MONSTER
};

class Card
{
public:

	Card()
	{
		set_name("Token");
		set_attack(0);
		set_def(0);
		set_type(Card_Type::MONSTER);
	}

	Card(const Card& other)
	{
		set_name(other.get_name());
		set_type(other.get_type());
		set_attack(other.get_attack());
		set_def(other.get_def());
	}

	Card(const char* name)
	{
		set_name(name);
		set_type(Card_Type::MAGIC);
		set_attack(MIN_ATTACK_POINTS);
		set_def(MIN_DEF_POINTS);
	}

	Card(const char* name, const int attack, const int def)
	{
		set_name(name);
		set_type(Card_Type::MONSTER);
		set_attack(attack);
		set_def(def);
	}

	char* get_name() const
	{
		char* name_copy = new char[strlen(name)];
		strcpy(name_copy, name);
		return name_copy;
	}

	Card_Type get_type() const
	{
		return type;
	}

	int get_attack() const
	{
		return attack;
	}

	int get_def() const
	{
		return def;
	}

	void set_name(const char* name)
	{
		strcpy(this->name, name);
	}

	void set_type(const Card_Type type)
	{
		this->type = type;
	}

	void set_attack(const int attack)
	{
		if (attack <= MIN_ATTACK_POINTS)
			this->attack = MIN_ATTACK_POINTS;
		else if (attack >= MAX_ATTACK_POINTS)
			this->attack = MAX_ATTACK_POINTS;
		else
			this->attack = attack;
	}

	void set_def(const int def)
	{
		if (def <= MIN_DEF_POINTS)
			this->def = MIN_DEF_POINTS;
		else if (def >= MAX_ATTACK_POINTS)
			this->def = MAX_ATTACK_POINTS;
		else
			this->def = def;
	}

private:
	char name[MAX_LENGHT_CARD_NAME];
	Card_Type type;
	int attack;
	int def;
};

std::ostream& operator<<(std::ostream& stream, const Card_Type type)
{
	switch (type)
	{
		case MONSTER: stream << "MONSTER"; break;
		case MAGIC: stream << "MAGIC"; break;
	}
	return stream;
}
