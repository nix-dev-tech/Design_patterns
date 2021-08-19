#include<iostream>
#include<sstream>
using namespace std;

class Shape {
public:
	virtual string str() = 0;
};

class Circle :public Shape {
	float radius;

public:
	Circle(){}

	Circle(float radius) : radius{radius}
	{

	}
	string str() override{
		ostringstream oss;
		oss << "Circle has radius" << radius << endl;
		return oss.str();
	}

	void resize(float factor) {
		radius *= factor;
	}
};

class ColoredShape : public Shape {
	Shape& shape;
	string color;

public:
	ColoredShape(Shape& shape, const string& color) : shape{shape},color{color}
	{

	}

	string str() override {
		ostringstream oss;
		oss << shape.str() << " it has color " << color;
		return oss.str();
	}

};

int main() {
	Circle circle{ 5 };
	
	ColoredShape colored_circle{ circle, "red" };
	cout<<colored_circle.str();

	return 0;
}
