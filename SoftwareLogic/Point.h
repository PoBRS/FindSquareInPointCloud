#pragma once
#include "PointsComparator.h"
#include <iostream>

/**
	Le point est la base du programme. Il permet de créer des lignes qui formeront un carré.
	Chaque point a une position X et Y.
*/
class Point
{
public:
	Point::Point(void);
	Point(float _x, float _y);
	~Point(void);
	Point(const Point* _pointToCopy);

	float getX(void) const;
	float getY(void) const;

	bool ComparePoints(Point* _A, Point* _B) const;
	bool isUsed(void) const;
	void setUsed(bool _usedState);
	void setX(float x);
	void setY(float y);

	Point& operator=(Point* const& _pointToCopy);
	bool operator<(const Point& _comparedPoint) const;
	bool operator==(const Point& _comparedPoint) const;
	bool operator!=(const Point& _comparedPoint) const;
	bool operator()(const Point* _pointA, const Point* _pointB);
	friend std::ostream& operator<<(std::ostream& _out, Point& _point);
private:
	float x;
	float y;
	bool used;
};