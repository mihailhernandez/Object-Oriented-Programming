#include <iostream>
#include <math.h>
#define SCALE 20

struct Point {
    
    private:
    
    double x;
    double y;

    public:

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

    double dist_from_center()
    {
        return hypot(this->x, this->y);
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

struct Rectangle {
    
    private:

    Point p1;
    Point p2;

    public:

    Rectangle() {}

    Rectangle(const Point& p1, const Point& p2)
    {
        this->p1 = p1;
        this->p2 = p2;
    }

    void set_p1(const Point& p1)
    {
        this->p1 = p1;
    }

    void set_p2(const Point& p2)
    {
        this->p2 = p2;
    }

    Point get_p1() const
    {
        return this->p1;
    }

    Point get_p2() const
    {
        return this->p2;
    }

    void print() const 
    {
        std::cout << "Rectangle " << this << std::endl;
        this->p1.print();
        this->p2.print();
    }

    double diag()
    {
        return p1.dist_to_point(p2);
    }

    const Point& most_left() const
    {
        return this->p1.get_x() < this->p2.get_x()
                  ? this->p1
                  : this->p2;
    }

    const Point& most_right() const
    {
        return this->p1.get_x() > this->p2.get_x()
                  ? this->p1
                  : this->p2;
    }

    const Point& most_up() const
    {
        return this->p1.get_y() > this->p2.get_y()
                  ? this->p1
                  : this->p2;
    }

    const Point& most_down() const
    {
        return this->p1.get_y() < this->p2.get_y()
                  ? this->p1
                  : this->p2;
    }

    bool is_on_edge(int x, int y) const 
    {
        return (x >= this->most_left().get_x() && x <= this->most_right().get_x())
            && (y <= this->most_up().get_y() && y >= this->most_down().get_y());
    }

    bool contains(const Point& p) const 
    {
        const Point& left = this->most_left();
        const Point& right = this->most_right();
        const Point& down = this->most_down();
        const Point& up = this->most_up();

        return p.get_x() >= left.get_x() && p.get_x() <= right.get_x()
               && p.get_y() >= down.get_y() && p.get_y() <= up.get_y();
    }

    bool intersects_with(const Rectangle& rec) const 
    {
        const Point& left = rec.most_left();
        const Point& right = rec.most_right();
        const Point& down = rec.most_down();
        const Point& up = rec.most_up();

        return this->contains(left) || this->contains(right)
                || this->contains(up) || this->contains(down);
    }

    void draw_rec() const
    {
        for (int row = SCALE / 2; row > -SCALE / 2; row--)
        {
            for (int col = -SCALE / 2; col < SCALE / 2; col++)
            {
                if (this->is_on_edge(row, col))
                {
                    std::cout << "*";
                }
                else if (row == 0 && col == 0)
                {
                    std::cout << "o";
                }
                else if (row == 0)
                {
                    std::cout << "-";
                }
                else if (col == 0)
                {   
                    std::cout << "|"; 
                }
                else
                {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
      
    }
};

void write_point(Point& p)
{
    double x, y;
    std::cin >> x >> y;
    p.set_x(x);
    p.set_y(y);
}

int main()
{
    Point p1, p2;
    Point p3, p4;

    write_point(p1);
    write_point(p2);

    Rectangle rec(p1, p2);

    rec.print();

    std::cout << "Diag = " << rec.diag() << std::endl;
   
    p3.set_x(1.5);
    p3.set_y(1.6);
    p4.set_x(2);
    p4.set_y(3);

    std::cout << std::boolalpha << rec.contains(p3) << std::endl;
    std::cout << std::boolalpha << rec.contains(p4) << std::endl;

    Rectangle rec_2(p3, p4);

    std::cout << std::boolalpha << rec.intersects_with(rec_2) << std::endl;

    Point p5, p6;

    p5.set_x(3);
    p5.set_y(5);
    p6.set_x(10);
    p6.set_y(11);

    Rectangle rec_3(p5, p6);

    std::cout << std::boolalpha << rec.intersects_with(rec_3) << std::endl;

    rec.draw_rec();

    return 0;
}
