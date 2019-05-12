#pragma once
#include <iostream>

template <class L, class R>
class Pair
{
public:
	Pair(const L&, const R&);
	Pair(const Pair<L, R>&);

	Pair<L, R>& operator=(const Pair<L, R>&);

	const L& get_left() const;
	const R& get_right() const;
	void set_left(const L&);
	void set_right(const R&);

private:
	L left;
	R right;

	void copy(const Pair<L, R>&);
};

template <class L, class R>
std::istream& operator>>(std::istream&, Pair<L, R>&);

template <class L, class R>
std::ostream& operator<<(std::ostream&, const Pair<L, R>&);

template <class L, class R>
Pair<L, R>::Pair(const L& left, const R& right) : left(left), rigth(right) {}

template <class L, class R>
Pair<L, R>::Pair(const Pair<L, R>& other) 
{
	copy(other);
}

template <class L, class R>
Pair<L, R>& Pair<L, R>::operator=(const Pair<L, R>& other) 
{
	copy(other);
}

template <class L, class R>
const L& Pair<L, R>::get_left() const
{
	return left;
}

template <class L, class R>
const R& Pair<L, R>::get_right() const
{
	return right;
}

template <class L, class R>
void Pair<L, R>::set_left(const L& left)
{
	this->left = left;
}

template <class L, class R>
void Pair<L, R>::set_right(const R& right)
{
	this->right = right;
}

template <class L, class R>
void Pair<L, R>::copy(const Pair<L, R>& other)
{
	set_left(other.left);
	set_right(other.right);
}

template <class L, class R>
std::istream& operator>>(std::istream& input_stream, Pair<L, R>& pair)
{
	L left;
	R right;
	input_stream >> left >> right;
	pair.set_left(left);
	pair.set_right(right);
	return input_stream;
}

template <class L, class R>
std::ostream& operator<<(std::ostream& output_stream, const Pair<L, R>& pair)
{
	output_stream << pair.get_left() << " " << pair.get_right();
	return output_stream;
}
