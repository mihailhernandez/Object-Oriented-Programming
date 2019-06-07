class Consumable
{
public:
	virtual void readLabel() const = 0;
	virtual void consume(const int) = 0;
	virtual int quantity() const;
protected:
	bool is_open;
};

class Eatable : public Consumable
{
public:
	void consume(const int);
	int quatity() const;
protected:
	Eatable(const int, const int);
private:
	int grams_per_piece;
	int pieces;
};

class Drinkable : public Consumable
{
public:
	void consume(const int);
	void readLabel() const;
public:
	Drinkable(const double);
protected:
	double liters;
};

class Chocolate : public Eatable
{
public:
	Chocolate(const int, const int, const double);
protected:
	double percentage_cacao;
};

class Croissant : public Eatable
{

};