#include <iostream>
#include <cstring>

const int MAXBEERML = 500;
const int MINBEERML = 330;
const int MAXBRANDNAME = 20;

class Beer
{
	private:

	char brand[MAXBRANDNAME];
	int ml;

	public:

	Beer(const char* brand, int ml)
	{
		set_ml(ml);
		set_brand(brand);
	}

	void print()
	{
		std::cout << brand << ", " << ml << std::endl; 
	}

	void print_address()
	{
		std::cout << this << std::endl;
	}

	const char* get_brand()
	{
		return brand;
	}

	int get_ml()
	{
		return ml;
	}

	void set_ml(int ml)
	{
		if(ml < MINBEERML)
			ml = MINBEERML;
		if (ml > MAXBEERML)
			ml = MAXBEERML;
		this->ml = ml;
	}

	void set_brand(const char* brand)
	{
		if (strlen(brand) < 1 || strlen(brand) > MAXBRANDNAME)
			std::strcpy(this->brand, "Default");
		else
			std::strcpy(this->brand, brand);
	}
};

int main()
{
	Beer* t = new Beer("dfghjkjhgfghjklkjhgfghjkkjhgf", 2000);

	t->print_address();
	t->print();

	delete t;

	return 0;
}
