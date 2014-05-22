#include "Point.h"
#include <string>

/**
	Constructeur par défaut d'un Point.
*/
Point::Point()
{
	this->x = 0;
	this->y = 0;
	this->used = false;
} 

/**
	Constructeur d'un Point. Un nouveau point est classé comme non-utilisé.
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
	@param[in] _pointToCopy l'adresse d'un Point à copier.
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
	Redifinition de l'operateur <<. Ajoute à un objet ostram les positions du point.
	@param[in] _out L'objet ostream pour la sortie.
	@param[in] _point Le point à utiliser pour faire la sortie.
	@return _out _out suivit de (valeurX, valeurY)
*/
std::ostream& operator<<(std::ostream& _out, Point& _point)
{
	_out << "(" << _point.getX() << ", " << _point.getY() << ")";
	return _out;
}

/**
	Redéfinition de l'operateur <. Un point est plus petit si la valeur X et plus petite, suivit de la valeur Y.
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
	Redéfinition de l'opérateur ==. Deux points sont égaux si les valeurs de X et de Y de chacuns sont à moins de 0.2 de différence.
	@param[in] _comparedPoint Le point avec lequel on se compare.
	@return True s'ils sont égaux à +- 0.2. Sinon false.
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
	Redéfinition de l'operateur () avec deux points.
	@param[in] _pointA Référence d'un point
	@param[in] _pointB Référence d'un point
	@return boolean Le résultat de la comparaison "<" entre le _pointA et le _pointB.
*/
bool Point::operator()(const Point* _pointA, const Point* _pointB)
{
	return *_pointA < *_pointB;
}

/**
	Redéfinition de l'opérateur = pour la copie d'un point.
	@param[in] _pointToCopy l'adresse d'un Point à copier.
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
	Redéfinition de l'operateur !=. Retourne l'inverse de l'opérateur ==.
	@param[in] _comparedPoint Le point avec lequel on se compare.
	@return False si this est égal, sinon, retourne true.
*/
bool Point::operator!=(const Point& _comparedPoint) const
{
	return !(operator==(_comparedPoint));
}

/**
	Getter de used.
	@return La valeur défini de used.
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
