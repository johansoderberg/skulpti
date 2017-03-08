#include "stdafx.h"
#include "PAPDrawArea.h"


PAPDrawArea::PAPDrawArea(int startX, int startY, int width, int height)
{
	move(startX, startY, width, height);
}

PAPDrawArea::~PAPDrawArea()
{

}

void PAPDrawArea::move(int startX, int startY, int width, int height) {
	_startX = startX;
	_startY = startY;
	_width = width;
	_height = height;
}

void PAPDrawArea::render(bool mouseOver) {


}

