#include <iostream>
#include <fstream>
#include <math.h>

struct Point {
    
    private:
    
    double x;
    double y;

    public:

	Point(const double x, const double y) : x(x), y(y) {}

	~Point() {}

    void set_x(const double x)
    {
        this->x = x;
    }

    void set_y(const double y)
    {
        this->y = y;
    }

    double get_x() const
    {
        return this->x;
    }

    double get_y() const
    {
        return this->y;
    }

    double dist_from_center() const 
    {
        return hypot(x, y);
    }

    double dist_to_point(const Point& other)
    {
        return hypot(abs(this->x - other.get_x()), 
                    abs(this->y - other.get_y()));
    }

    void print() const
    {
        std::cout << "Point " << this << " x = "
            << x << " y = " << y << std::endl;
    }
};

int closest_point_to_origin_index(Point** points, const unsigned int arr_size)
{
	int closest_point_index = 0;
	double closest_point_dist = points[0]->dist_from_center();
	for (size_t i = 1; i < arr_size; i++)
	{
		double current_dist = points[i]->dist_from_center();
		if (current_dist < closest_point_dist)
		{
			closest_point_index = i;
			closest_point_dist = current_dist;
		}
	}
	return closest_point_index;
}

Point** create_points(const unsigned int size)
{
	Point** points = new Point*[size];
	for (size_t i = 0; i < size; i++)
	{
		double x;
		double y;
		std::cin >> x;
		std::cin >> y;
		points[i] = new Point(x, y);
	}
	return points;
}

Point** read_points(const char* file_name)
{
	std::ifstream file(file_name);

	if (!file.is_open())
	{
		std::cerr << "File not opened!" << std::endl;
		return NULL;
	}

	unsigned int arr_size;
	file >> arr_size;

	if (arr_size < 1)
	{
		std::cerr << "Enter a size bigger than 1!" << std::endl;
		return NULL;
	}
	
	Point** points = new Point*[arr_size];

	for (size_t i = 0; i < arr_size; i++)
	{
		double x;
		double y;
		if (!file.good())
		{
			std::cerr << "File not good!" << std::endl;
			delete[] points;
			return NULL;
		}
		file >> x >> y;
		points[i] = new Point(x, y);
	}
	return points;
}

int main()
{
	unsigned int arr_size;
	std::cin >> arr_size;

	if (arr_size < 1)
	{
		std::cerr << "Enter a size bigger than 1!" << std::endl;
		return -1;
	}

	Point** points = create_points(arr_size);
	int index = closest_point_to_origin_index(points, arr_size);
	std::cout << index << std::endl;
	delete[] points;

	const char* file_name = "points.txt";
	points = read_points(file_name); 
	index = closest_point_to_origin_index(points, arr_size);
	std::cout << index << std::endl;
	delete[] points;

    return 0;
}
