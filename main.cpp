#include <stdio.h>

class IShape
{
public:
	virtual float size() = 0;
	virtual void draw() = 0;
};

class Circle : public IShape
{
private:
	float r = 16.0f;

public:
	float size() { return r * r * 3.141592f; }
	void draw() { printf("CircleSize:%f\n", size()); }
};

class Rectangle :public IShape
{
private:
	float rX = 10.0f;
	float rY = 15.0f;

public:
	float size() { return rX * rY; }
	void draw() { printf("RectangleSize:%f\n", size()); }
};

int main()
{
	Circle circle;
	Rectangle rectangle;
	circle.draw();
	rectangle.draw();

	return 0;
}