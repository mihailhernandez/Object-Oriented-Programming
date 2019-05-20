#include "Farm.hpp"

int main()
{
	Farm farm(2);
	farm.add_cat("Cat");
	farm.add_dog("Dog");
	farm.add_dog("Dog");
	farm.add_cow("Cow");
	farm.add_cat("Cat");
	farm.roar_all();
	return 0;
}