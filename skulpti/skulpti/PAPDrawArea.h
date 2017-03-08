#pragma once
class PAPDrawArea
{
public:
	PAPDrawArea(int startX, int startY, int width, int height);
	virtual void render(bool mouseOver);
	virtual ~PAPDrawArea();
	void move(int startX, int startY, int width, int height);
protected:
	int _startX;
	int _startY;
	int _width;
	int _height;
};

