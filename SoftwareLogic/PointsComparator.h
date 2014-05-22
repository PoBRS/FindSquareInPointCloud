#pragma once
//namespace SFML
class Point;
/**
	Classe de tri supplémentaire aux opérateurs de comparaison de Point. Ceux-ci servent aux Squares
	n'ayant pas étés retrouvés à la suite d'un premier balayage.
*/
class PointsComparator
{
public:
	PointsComparator(void);
	~PointsComparator(void);
	bool operator() (const Point& _point1, const Point& _point2) const;
	static bool isFloatApproximativelyEqual(const float _value1, const float _value2, const float _allowedDifference);
private:
	bool isApproximativelySmaller(const Point& _point1, const Point& _point2) const;

};