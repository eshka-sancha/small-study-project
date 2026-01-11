#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

//Составить описание класса прямоугольников со сторонами, параллельными осям координат. 
//Предусмотреть возможность перемещения прямоугольников на плос­кости и  изменение размеров прямоугольника.
//Написать программу, демонстрирующую все разработанные элементы класса.
//Создать дочерний класс, выполняющий построение наименьшего прямоугольника, 
//содер­жащего два заданных прямоугольника, и прямоугольника, являющегося общей частью (пересечением) 
//двух прямоугольников. 

class pryam {
private:
    float x; float len_x;
    float y; float len_y;

    void validate_lenght(float len_X, float len_Y) {
        if (len_X <= 0 || len_Y <= 0) {
            throw invalid_argument("error: rectangle lenght must be positive! received: " + 
                                 to_string(len_X) + " x " + to_string(len_Y));
        }
    }

public:
    float get_x() const {return x;}
    float get_y() const {return y;}
    float get_lenx() const {return len_x;}
    float get_leny() const {return len_y;}
    
    void set_x(float X) { x = X; }
    void set_y(float Y) { y = Y; }
    
    void set_lenx(float len_X) { 
        if (len_X <= 0) {
            throw invalid_argument("error: x-length must be positive! received: " + to_string(len_X));
        }
        len_x = len_X;
    }
    
    void set_leny(float len_Y) { 
        if (len_Y <= 0) {
            throw invalid_argument("error: y-length must be positive! received: " + to_string(len_Y));
        }
        len_y = len_Y;
    }

    pryam(float X, float Y, float len_X, float len_Y) { 
        validate_lenght(len_X, len_Y);
        x = X; y = Y;
        len_x = len_X; len_y = len_Y;
    }

    float calculate_area() const {
        return len_x * len_y;
    }

    void print() const {
        cout << "length through x = " << len_x << " length through y = " << len_y;
        cout << " (area = " << calculate_area() << ")" << endl; 
    }
    
    void print_xy() const {
        cout << "coord left-down (x,y) = " << "(" << x << "," << y << ")" << endl;
        cout << "coord right-down (x,y) = " << "(" << x+len_x << "," << y << ")" << endl;
        cout << "coord left-high (x,y) = " << "(" << x << "," << y+len_y << ")" << endl;
        cout << "coord right-high (x,y) = " << "(" << x+len_x << "," << y+len_y << ")" << endl;
        cout << "valid rectangle with area: " << calculate_area() << endl << endl;
    }
};

class chertila : public pryam {
public:
    
    chertila(float X, float Y, float len_X, float len_Y) : pryam(X, Y, len_X, len_Y) {}

    static void make_smaller(const pryam& A, const pryam& B) {
        float areaA = A.calculate_area();
        float areaB = B.calculate_area();
        
        cout << "rectangle A area: " << areaA << endl;
        cout << "rectangle B area: " << areaB << endl;
        
        if (areaA <= areaB) {
            cout << "smaller rectangle: ";
            A.print();
        }
        else {
            cout << "smaller rectangle: ";
            B.print();
        }
    }
    
    static pryam make_around(const pryam& A, const pryam& B) {
        float min_x = min(A.get_x(), B.get_x());
        float min_y = min(A.get_y(), B.get_y());
        float max_x = max(A.get_x() + A.get_lenx(), B.get_x() + B.get_lenx());
        float max_y = max(A.get_y() + A.get_leny(), B.get_y() + B.get_leny());
        
        float width = max_x - min_x;
        float height = max_y - min_y;
        
        return pryam(min_x, min_y, width, height);
    }

    static pryam make_together(const pryam& A, const pryam& B) {
        float left = max(A.get_x(), B.get_x());
        float bottom = max(A.get_y(), B.get_y());
        float right = min(A.get_x() + A.get_lenx(), B.get_x() + B.get_lenx());
        float top = min(A.get_y() + A.get_leny(), B.get_y() + B.get_leny());
        
        float width = right - left;
        float height = top - bottom;

        if (width <= 0 || height <= 0) {
            throw runtime_error("rectangles do not intersect! cannot create null_rect rectangle.");
        }
        
        return pryam(left, bottom, width, height);
    }
};

pryam create_safe_rectangle(float x, float y, float len_x, float len_y, const string& name) {
    try {
        pryam rect(x, y, len_x, len_y);
        cout << "successfully created " << name << endl;
        return rect;
    } catch (const invalid_argument& e) {
        cout << "failed to create " << name << ": " << e.what() << endl;
        throw;
    }
}

int main() {
    cout << "=== test 1: normal rectangles ===" << endl;
    try {
        pryam a = create_safe_rectangle(2, 2, 4, 5, "rectangle A");
        pryam b = create_safe_rectangle(3, 3, 2, 1, "rectangle B");
        
        a.print_xy();
        b.print_xy();
        chertila::make_smaller(a, b);

        cout << "\n=== around rectangle ===" << endl;
        pryam bounding = chertila::make_around(a, b);
        bounding.print_xy();
        
        cout << "\n=== intersection ===" << endl;
        pryam intersection = chertila::make_together(a, b);
        intersection.print_xy();
        
    } catch (const exception& e) {
        cout << "test 1 failed: " << e.what() << endl;
    }

    cout << "\n=== test 2: attempt to create null_rect rectangles ===" << endl;
    try {
        pryam c = create_safe_rectangle(1, 1, 0, 5, "rectangle C (zero width)");
        c.print_xy();
    } catch (const exception& e) {
        cout << "failed to create rectangle with zero width" << endl;
    }

    try {
        pryam d = create_safe_rectangle(2, 2, 3, 0, "rectangle D (zero height)");
        d.print_xy();
    } catch (const exception& e) {
        cout << "failed to create rectangle with zero height" << endl;
    }

    try {
        pryam e = create_safe_rectangle(0, 0, 0, 0, "rectangle E (all zero)");
        e.print_xy();
    } catch (const exception& e) {
        cout << "failed to create all zero rectangle" << endl;
    }

    cout << "\n=== test 3: attempt to create rectangle with negative lenght ===" << endl;
    try {
        pryam f = create_safe_rectangle(1, 1, -4, 5, "rectangle F (negative width)");
        f.print_xy();
    } catch (const exception& e) {
        cout << "failed to create rectangle with negative lenght" << endl;
    }

    cout << "\n=== test 4: using setters with invalid values ===" << endl;
    try {
        pryam test(1, 1, 2, 2);
        test.print_xy();
        
        cout << "attempting to set negative length..." << endl;
        test.set_lenx(-5);
        test.print_xy();
        
    } catch (const exception& e) {
        cout << "setter error: " << e.what() << endl;
    }

    cout << "\n=== test 5: non-intersecting rectangles ===" << endl;
    try {
        pryam g(1, 1, 2, 2);
        pryam h(5, 5, 3, 3);
        
        g.print_xy();
        h.print_xy();
        
        cout << "attempting to find intersection..." << endl;
        pryam intersection2 = chertila::make_together(g, h);
        intersection2.print_xy();
        
    } catch (const exception& e) {
        cout << "failed to find intersection: " << e.what() << endl;
    }

    cout << "\n=== test 6: partial intersection with movement demonstration ===" << endl;
    try {

        pryam i = create_safe_rectangle(1, 1, 4, 3, "rectangle I");
        pryam j = create_safe_rectangle(3, 2, 4, 4, "rectangle J");
        
        cout << "=== initial state ===" << endl;
        i.print_xy();
        j.print_xy();
        
        cout << "comparing sizes:" << endl;
        chertila::make_smaller(i, j);
        
        cout << "\n=== aroud rectangle ===" << endl;
        pryam bounding6 = chertila::make_around(i, j);
        bounding6.print_xy();
        
        cout << "\n=== intersection ===" << endl;
        pryam intersection6 = chertila::make_together(i, j);
        intersection6.print_xy();

        cout << "\n=== moving rectangle J ===" << endl;
        cout << "current position of rectangle J:" << endl;
        cout << "x = " << j.get_x() << ", y = " << j.get_y() << endl;
        cout << "width = " << j.get_lenx() << ", height = " << j.get_leny() << endl;
        cout << "moving rectangle J to position (8, 2)..." << endl;
        j.set_x(8); 
        j.set_y(2); 
        
        cout << "new position of rectangle J:" << endl;
        i.print_xy();
        j.print_xy();
        
        cout << "attempting to find intersection after movement..." << endl;
        try {
            pryam intersection_after_move = chertila::make_together(i, j);
            intersection_after_move.print_xy();
        } catch (const runtime_error& e) {
            cout << "success: " << e.what() << endl;
            cout << "rectangles no longer intersect after movement!" << endl;
        }
        
        cout << "\n=== new around rectangle after movement ===" << endl;
        pryam bounding_after_move = chertila::make_around(i, j);
        bounding_after_move.print_xy();

        cout << "\n=== moving rectangle J to the left side ===" << endl;
        j.set_x(-2);
        
        cout << "new position of rectangle J:" << endl;
        j.print_xy();
        
        cout << "attempting to find intersection..." << endl;
        try {
            pryam intersection_left = chertila::make_together(i, j);
            intersection_left.print_xy();
        } catch (const runtime_error& e) {
            cout << "success: " << e.what() << endl;
            cout << "rectangles also don't intersect when J is on the left!" << endl;
        }
        
    } catch (const exception& e) {
        cout << "test 6 failed: " << e.what() << endl;
    }

    return 0;
}