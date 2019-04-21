#include <iostream>
#include "Date.cpp"
#include "Deck.cpp"
#include "Duelist.cpp"

int main()
{
	std::cout << "------------------------------------------------------------------" << std::endl;

	Date d1(23, 2, 2012);
	std::cout << "Date 1 -> " << d1 << "." << std::endl;
	Date d2;
	std::cout << "Date 2 -> " << d2 << "." << std::endl;
	std::cout << d1 << " + 365 days -> ";
	d1.add_days(365);
	std::cout << d1 << std::endl;
	std::cout << d1 << " - 365 days -> ";
	d1.remove_days(365);
	std::cout << d1 << std::endl; 
	std::cout << "Is " << d1 << " a leap year? -> " 
			<< std::boolalpha << d1.is_leap_year() << std::endl;
	std::cout << "Is " << d1 << " later than " << d2 << "? -> " 
			<< d1.is_later_than(d2) << std::endl;
	Date d3 = d2;
	std::cout << "Date 3 = date 2." << std::endl;
	std::cout << "Date 2 -> " << d2 << std::endl
			<< "Date 3 -> " << d3 << std::endl;

	Date result = get_difference(d1, d2);
	std::cout << "Difference between " << d1 
			<< " and " << d2 << " = " << result << std::endl;

	std::cout << d1 << " has " << d1.days_until_Christmas() << " days until Christmas." << std::endl;
	std::cout << d2 << " has " << d2.days_until_Christmas() << " days until Christmas." << std::endl;
	std::cout << d3 << " has " << d3.days_until_Christmas() << " days until Christmas." << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;
	
	Deck deck;
	deck.change_card(1, "Dark Magician", 2500, 2100);
	deck.change_card(2, "Silver Fang", 1200, 800);
	deck.change_card(3, "Blue-eyes white dragon", 3000, 2500);
	deck.change_card(4, "Sword of Dark Destruction");
	deck.change_card(10, "Blue-eyes white dragon", 3000, 2500);
	deck.change_card(11, "Card Destruction");
	deck.change_card(15, "Change of Heart");
	deck.change_card(23, "Card Destruction");
	deck.change_card(25, "Monster reborn");
	deck.change_card(27, "Blue-eyes white dragon", 3000, 2500);
	deck.change_card(30, "Blue-eyes white dragon", 3000, 2500);
	deck.change_card(40, "Change of Heart");

	std::cout << deck;
	std::cout << "Monster cards: " << deck.get_monster_card_count() << std::endl;
	std::cout << "Magic cards: " << deck.get_magic_card_count() << std::endl;
	deck.save_to_file("my_deck");
	//Deck deck2("my_deck"); 
	//std::cout << deck2;

	std::cout << "------------------------------------------------------------------" << std::endl;

	Duelist player1("Seto Kaiba");
	player1.change_card_in_deck(2, "Blue-eyes white dragon", 3000, 2500);
	Duelist player2("Yugi Muto");
	player2.change_card_in_deck(2, "Dark magician", 2500, 2100);

	std::cout << player1 << player2;
	return 0;
}
