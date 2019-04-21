#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Card.cpp"

const unsigned int DECK_SIZE = 40;

class Deck
{
public:

	Deck() {}

	Deck(const char* file_name)
	{
		std::ifstream file(file_name, std::ios::binary);
		if (!file)
		{
			std::cerr << "Error opening file!" << std::endl;
			return;
		}
		for (int i = 0; i < DECK_SIZE; i++)
		{
			Card card;
			int is_card_a_monster;
			int name_length = 0;
			char* name = new char[MAX_LENGHT_CARD_NAME];
			int attack;
			int def;

			file.read((char*)&is_card_a_monster, sizeof(int));
			file.read((char*)&name_length, sizeof(int));
			file.read((char*)&name, sizeof(char) * name_length);
			card.set_name(name);
			// tova ne raboti no smqtam da go predam zashtoto go debugvam na vim veche 2 dena 
			if (is_card_a_monster)
			{
				file.read((char*)&attack, sizeof(int));
				file.read((char*)&def, sizeof(int));
				card.set_type(Card_Type::MONSTER);
				card.set_attack(attack);
				card.set_def(def);
			} 
			else
			{
				card.set_type(Card_Type::MAGIC);
			}
			deck[i] = card;
		}
		file.close();
	}

	void change_card(const int card_number, const char* card_name, 
					 const int attack, const int def)
	{
		Card card(card_name, attack, def);
		deck[card_number - 1] = card;
	}

	void change_card(const int card_number, const char* card_name)
	{
		Card card(card_name);
		deck[card_number - 1] = card;
	}

	int get_magic_card_count() const
	{
		unsigned int magic_card_count = 0;
		for (int i = 0; i < DECK_SIZE; i++)
			if (deck[i].get_type() == Card_Type::MAGIC)
				magic_card_count++;
		return magic_card_count;
	}

	int get_monster_card_count() const
	{
		unsigned int monster_card_count = 0;
		for (int i = 0; i < DECK_SIZE; i++)
			if (deck[i].get_type() == Card_Type::MONSTER)
				monster_card_count++;
		return monster_card_count;
	}

	void save_to_file(const char* file_name) const
	{
		std::ofstream file(file_name);
		if (!file)
		{
			std::cerr << "Error opening file!" << std::endl;
			return;
		}
		for (int i = 0; i < DECK_SIZE; i++)
		{
			int is_card_a_monster = (deck[i].get_type() == Card_Type::MONSTER) ? 1 : 0;
			char* name = deck[i].get_name();
			int name_length = strlen(name);
			int attack = deck[i].get_attack();
			int def = deck[i].get_def();
			file.write((char*)&is_card_a_monster, sizeof(int));
			file.write((char*)&name_length, sizeof(int));
			file.write((char*)name, sizeof(char) * name_length); 
			if (is_card_a_monster)
			{
				file.write((char*)&attack, sizeof(int));
				file.write((char*)&def, sizeof(int));
			}
			delete[] name;
		}
		file.close();
	}

	const Card operator[](const int index) const 
	{
		return deck[index];
	}

	unsigned int card_max_name_len() const
	{
		unsigned int max_name_len = 0;
		unsigned int curr_name_len = strlen(deck[0].get_name());
		for (int i = 1; i < DECK_SIZE; curr_name_len = strlen(deck[i++].get_name()))
			if (curr_name_len > max_name_len)
					max_name_len = curr_name_len;
		return max_name_len;
	}

	Deck& operator=(const Deck& other)
	{
		for (int i = 0; i < DECK_SIZE; i++)
			deck[i] = other[i];
		return *this;
	}

private:
	Card deck[DECK_SIZE];

	bool is_card_number_valid(const int card_number) const
	{
		return card_number >= 0 && card_number < DECK_SIZE;
	}
};

std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	unsigned int max_name_len = deck.card_max_name_len();
	os << std::setfill(' ') << std::setw(max_name_len) << "NAME" << " | "
		<< "ATTACK" << " | " << "DEFENSE" << " | " << "   TYPE" << std::endl;
	for (int i = 0; i < DECK_SIZE; i++)
		std::cout << std::setfill(' ') << std::setw(max_name_len) << deck[i].get_name() 
				<< " |   " << std::setw(4) << std::setfill('0') << deck[i].get_attack() 
				<< " |    " << std::setw(4) << std::setfill('0') << deck[i].get_def() 
				<< " | " << std::setw(7) << std::setfill(' ') << deck[i].get_type() << std::endl;
	return os;
}
