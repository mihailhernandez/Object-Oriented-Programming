#include "Clubs.h"

int main()
{
	Clubs clubs;
	clubs.add_folk_club("33", 10, 40, "Galena");  // False (the Vodka is too cheap)
	clubs.add_folk_club("33", 40, 40, "Galena");  // Much better
	clubs.add_house_club("Yalta", 50, 50, 2);     // 50 for whiskey, 50 for vodka and 2 DJs this night.
	User ivan("Ivan", 18, 180, 2, 2, "House");    // Name: Ivan, Age: 18, Cash: 180, Vodkas: 2, Whiskeys: 2, Music: House
	clubs.add_to_club(ivan, "Yalta");             // not enough cash for 2 vodkas and 2 whiskeys
	clubs.add_to_club(ivan, "33");                // True
	clubs.remove_from_club("Poli", "33");         // False. No Poli in 33 tonight. 
	clubs.remove_from_club("Ivan", "33");         // True
	return 0;
}