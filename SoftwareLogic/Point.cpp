#include "Point.h"
#include <string>

/**
	Constructeur par d�faut d'un Point.
*/
Point::Point()
{
	this->x = 0;
	this->y = 0;
	this->used = false;
} 

/**
	Constructeur d'un Point. Un nouveau point est class� comme non-utilis�.
	@param[in] x La position en X du point.
	@param[in] y La position en Y du point.
*/
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
	this->used = false;
}

/**
	Destructeur du point.
*/
Point::~Point()
{
	
}

/**
	Constructeur de copie d'un point.
	@param[in] _pointToCopy l'adresse d'un Point � copier.
*/
Point::Point(const Point* _pointToCopy)
{
	this->x = _pointToCopy->getX();
	this->y = _pointToCopy->getY();
	this->used = _pointToCopy->isUsed();
}

/**
	Fonction qui retourne la position en X du Point.
	@return La position en X du Point
*/
float Point::getX() const
{
	return this->x;
}

/**
	Fonction qui retourne la position en Y du Point.
	@return La position en Y du Point.
*/
float Point::getY() const
{
	return this->y;
}

/**
	Redifinition de l'operateur <<. Ajoute � un objet ostram les positions du point.
	@param[in] _out L'objet ostream pour la sortie.
	@param[in] _point Le point � utiliser pour faire la sortie.
	@return _out _out suivit de (valeurX, valeurY)
*/
std::ostream& operator<<(std::ostream& _out, Point& _point)
{
	_out << "(" << _point.getX() << ", " << _point.getY() << ")";
	return _out;
}

/**
	Red�finition de l'operateur <. Un point est plus petit si la valeur X et plus petite, suivit de la valeur Y.
	@param[in] _comparedPoint Le point avec lequel on se compare.
	@return True si this est plus petit. Sinon False.
*/
bool Point::operator<(const Point& _comparedPoint) const
{
	if (this->x > _comparedPoint.x)
	{
		return false;
	}
	if (this->x == _comparedPoint.x)
	{
		if (this->y > _comparedPoint.y)
		{
			return false;
		}
	}
	if (*this == _comparedPoint)
	{
		return false;
	}
	return true;
}

/**
	Red�finition de l'op�rateur ==. Deux points sont �gaux si les valeurs de X et de Y de chacuns sont � moins de 0.2 de diff�rence.
	@param[in] _comparedPoint Le point avec lequel on se compare.
	@return True s'ils sont �gaux � +- 0.2. Sinon false.
	@see isFloatApprocimativelyEqual
*/
bool Point::operator==(const Point& _comparedPoint) const
{
	
	if (PointsComparator::isFloatApproximativelyEqual(this->getX(), _comparedPoint.getX(),0.2))
	{
		if (PointsComparator::isFloatApproximativelyEqual(this->getY(), _comparedPoint.getY(),0.2))
		{
			return true;
		}
	}
	return false;
	
}

/**
	Red�finition de l'operateur () avec deux points.
	@param[in] _pointA R�f�rence d'un point
	@param[in] _pointB R�f�rence d'un point
	@return boolean Le r�sultat de la comparaison "<" entre le _pointA et le _pointB.
*/
bool Point::operator()(const Point* _pointA, const Point* _pointB)
{
	return *_pointA < *_pointB;
}

/**
	Red�finition de l'op�rateur = pour la copie d'un point.
	@param[in] _pointToCopy l'adresse d'un Point � copier.
	@return L'adresse de this.
*/
Point& Point::operator=(Point* const& _pointToCopy)
{
	if (this != _pointToCopy)
	{
		this->x = _pointToCopy->getX();
		this->y = _pointToCopy->getY();
		this->used = _pointToCopy->isUsed();
	}	
	return *this;

}

/**
	Red�finition de l'operateur !=. Retourne l'inverse de l'op�rateur ==.
	@param[in] _comparedPoint Le point avec lequel on se compare.
	@return False si this est �gal, sinon, retourne true.
*/
bool Point::operator!=(const Point& _comparedPoint) const
{
	return !(operator==(_comparedPoint));
}

/**
	Getter de used.
	@return La valeur d�fini de used.
*/
bool Point::isUsed(void) const
{
	return this->used;
}

/**
	Setter de used.
	@param[in] _usedState La valeur boolean voulut pour used.
*/
void Point::setUsed(bool _usedState)
{
	this->used = _usedState;
}
