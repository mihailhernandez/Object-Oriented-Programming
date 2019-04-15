#include <iostream>
#include <fstream>

class Complex
{
public:
	Complex() : re(0), im(0) {}

	Complex(const double re, const double im) : re(re), im(im) {}

	void print() const
	{
		std::cout << re << (im > 0 ? "+" : "") << im << "i" << std::endl;
	}

	Complex& operator+=(const Complex& other)
	{
		re += other.get_re();
		im += other.get_im();
		return *this;
	}

	Complex& operator-=(const Complex& other)
	{
		re -= other.get_re();
		im -= other.get_im();
		return *this;
	}

	Complex& operator*=(const Complex& other)
	{
		double oldRe = re;
		re = re * other.get_re() - im * other.get_im();
		im = oldRe * other.get_im() + im * other.get_re();
		return *this;
	}

	Complex& operator/=(const Complex& other)
	{
		Complex numerator = other.get_conjugated();
		*this *= numerator;

		Complex denominator(other);
		denominator *= numerator;
		re /= denominator.get_re();
		im /= denominator.get_im();

		return *this;
	}

	Complex get_conjugated() const
	{
		Complex con = *this;
		con.set_im(con.get_im() * -1);
		return con;

	}

	double get_re() const
	{
		return re;
	}

	double get_im() const
	{	
		return im;
	}

	void set_re(const double re) 
	{
		this->re = re;	
	}

	void set_im(const double im)
	{
		this->im = im;	
	}
private:
	double re;
	double im;
};

Complex operator+(const Complex& left, const Complex& right)
{
	Complex result = left;
	return result += right;
}

Complex operator-(const Complex& left, const Complex& right)
{
	Complex result = left;
	return result -= right;
}

Complex operator*(const Complex& left, const Complex& right)
{
	Complex result = left;
	return result *= right;
}

std::ostream& operator<<(std::ostream& stream, const Complex& c)
{
	stream << c.get_re() << (c.get_im() > 0 ? "+" : "") << c.get_im() << "i" << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Complex& c)
{
	double re, im;
	stream >> re >> im;
	c.set_re(re);
	c.set_im(im);
	return stream;
}

int main()
{
	Complex c(1, 2);
	Complex c2(4, 4);

	c.print();
	c2.print();
	std::cout << "---------------------------------------" << std::endl;
	c.print();
	std::cout << " + " << std::endl;
	c2.print();
	c += c2;
	std::cout << " = " << std::endl;
	c.print();

	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	c.print();
	std::cout << " - " << std::endl;
	c2.print();
	c -= c2;
	std::cout << " = " << std::endl;
	c.print();
	
	std::cout << "---------------------------------------" << std::endl;
	Complex c3 = c + c2;
	c.print();
	std::cout << " + " << std::endl;
	c2.print();
	std::cout << " = " << std::endl;
	c3.print();

	std::cout << "---------------------------------------" << std::endl;
	Complex c4 = c;
	c.print();
	std::cout << " * " << std::endl;
	c2.print();
	std::cout << " = " << std::endl;
	c4 *= c2;
	c4.print();

	std::cout << "---------------------------------------" << std::endl;
	Complex c5 = c * c2;
	c.print();
	std::cout << " * " << std::endl;
	c2.print();
	std::cout << " = " << std::endl;
	c5.print();

	std::cout << "---------------------------------------" << std::endl;
	c5 = c * c2;
	std::cout << c;
	std::cout << " * " << std::endl;
	std::cout << c2;
	std::cout << " = " << std::endl;
	std::cout << c5;
	
	std::cout << "---------------------------------------" << std::endl;
	std::cout << c5;
	std::cout << " / " << std::endl;
	std::cout << c2;
	std::cout << " = " << std::endl;
	c5 /= c2;
	std::cout << c5;

	std::ofstream file("complex.txt");
	if (!file)
	{
		std::cerr << "Error opening file!" << std::endl;
		return -1;
	}
	file << c << c2;

	Complex c6;
	std::cin >> c6;
	std::cout << c6;
	
	return 0;
}
