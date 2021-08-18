#include<iostream>
#include<math.h>

using namespace std;

class RoundPeg {
public:
	RoundPeg()
	{

	}

	RoundPeg(float radius) : radius(radius)
	{

	}

	virtual float getRadius() {
		return radius;
	}
	float radius;
};

class RoundHole {
public:

	RoundHole(float radius) : radius(radius)
	{

	}

	float getRadius() {
		return radius;
	}

	bool fits(RoundPeg* peg) {
		return this->radius >= peg->getRadius();
	}
	float radius;
};


class SquarePeg {
	float width;

public:
	SquarePeg(float width) : width(width)
	{

	}

	float getWidth() {
		return width;
	}
};

class SquarePegAdapter : public RoundPeg {
	SquarePeg peg;
public:
	SquarePegAdapter(SquarePeg peg) : peg(peg)
	{

	}

	float getRadius() override{
		//cout << endl<<(peg.getWidth() * sqrt(2)) / 2;
		return (peg.getWidth() * sqrt(2)) / 2;
	}
};

int main() {
	RoundHole* hole = new RoundHole(5);
	RoundPeg* rpeg = new RoundPeg(10);
	cout<<hole->fits(rpeg);

	SquarePeg* small_sqpeg = new SquarePeg(5);
	SquarePeg* large_sqpeg = new SquarePeg(10);
	//hole->fits(small_sqpeg); does not support square peg object. Hence we need adapter that support and compatible with both the types

	SquarePegAdapter* small_sqpeg_adapter = new SquarePegAdapter(5);
	SquarePegAdapter* large_sqpeg_adapter = new SquarePegAdapter(10);
	cout<<hole->fits(small_sqpeg_adapter);
	cout<<hole->fits(large_sqpeg_adapter);
	
	return 0;
}
