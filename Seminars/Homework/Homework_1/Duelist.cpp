#include <iostream>

class Duelist
{
public:

	Duelist(const char * name)
	{	
		set_name(name);
	}

	~Duelist()
	{
		delete[] name;
	}

	int get_magic_card_count() const
	{
		return deck.get_magic_card_count();
	}

	int get_monster_card_count() const
	{
		return deck.get_monster_card_count();
	}

	char * get_name() const
	{
		char* name = new char[strlen(this->name)];
		strcpy(name, this->name);
		return name;
	}

	void set_name(const char * name) 
	{
		delete[] this->name;
		this->name = new char[strlen(name)];
		strcpy(this->name, name);
	}

	void set_deck(const Deck& other)
	{
		deck = other;
	}

	Deck get_deck() const
	{
		Deck cpy = deck;
		return cpy;
	}

	void change_card_in_deck(const int card_number, const char * name)
	{
		deck.change_card(card_number, name);
	}

	void change_card_in_deck(const int card_number, const char * name, 
					const int attack, const int def) 
	{
		deck.change_card(card_number, name, attack, def);
	}
private:
	char* name = new char[0];
	Deck deck;
};

std::ostream& operator<<(std::ostream& os, const Duelist& duelist)
{
	os << "NAME : " << duelist.get_name() << std::endl;
	os << "DECK : " << duelist.get_deck();
	return os;
}
