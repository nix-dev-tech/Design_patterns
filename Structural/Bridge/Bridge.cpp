#include<iostream>
using namespace std;
// shape: circle, square, triangle
//renderer: vector, raster
//3 x 2 instances cartesian product
// instead create hierarchical top level interfaces which will act as a bridge and communicate with each other
struct Renderer {
	virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer {
	void render_circle(float x, float y, float radius) override{
		std::cout << "Vector rendering of circle of radius "<<radius << endl;
	}
};

struct RasterRenderer : Renderer {
	void render_circle(float x, float y, float radius) override {
		std::cout << "Raster rendering of circle of radius "<<radius << endl;
	}
};

struct Shape {
protected:
	Renderer& renderer;
	Shape(Renderer& renderer) : renderer(renderer)
	{

	}

public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;
};

struct Circle :Shape {
	float radius, x, y;
	Circle(Renderer& renderer, float x, float y, float radius) : Shape(renderer), x{ x }, y{ y }, radius{ radius }
	{
		
	}
	void draw() override{
		renderer.render_circle(x, y, radius);
	}

	void resize(float factor) override {
		radius *= factor;
	}
};

struct square : Shape {

};

int main() {
	RasterRenderer rr;
	Circle raster_circle{ rr, 5,5,5 };
	raster_circle.draw();
	raster_circle.resize(2);
	raster_circle.draw();
	return 0;
}
