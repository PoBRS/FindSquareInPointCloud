#include <vector>
#include "../SoftwareLogic/Square.h"
#include "SFML/Graphics.hpp"
//namespace SFML
using namespace sf;

class SquareDisplay
{
public:
	 bool displayAllRectanglePartially(std::vector<Square*>* _rectangleVector, RenderWindow &mainWin) ;
	 bool displayRectangleOneByOne(std::vector<Square*>* _rectangleVector, int* _nbRectangleCompletedDisplay,RenderWindow &mainWin);
private:
	void InstantDisplay(RenderWindow &_mainWin, Line &line);
	bool DisplayCompleted(Line &line);
	bool SquareProgressiveDisplay(RenderWindow& _mainWin, Square &square);
	void LineInstantDisplay(RenderWindow &_mainWin, Line &line);
	void SquareInstantDisplay(RenderWindow& _mainWin, Square &square);
	void LineProgressiveDisplay(RenderWindow &_mainWin, Line &line);
	void SquareProgressiveDisplayTop(RenderWindow& _mainWin, Square &Square);
	void SquareProgressiveDisplayBottom(RenderWindow& _mainWin, Square &Square);
	bool Display(RenderWindow& _mainWin, Square &square);

	int fps;
};