#pragma once   

class Figure: public CObject 
{
	DECLARE_SERIAL (Figure)    
public:
	void Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ()) //
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << color;
			ar << set;
		}
		else // Loading
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> color;
			ar >> set;
		}
	}
	Figure();
	Figure(int xx1,int yy1, int xx2, int yy2)
	{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;
		color=RGB(255,0,0); 
	}
	int getX1() const;
	int getX2() const;
	int getY1() const;
	int getY2() const;
	void setX1(int);
	void setX2(int);
	void setY1(int);
	void setY2(int);
	void setColor(COLORREF);
	void setXY(int,int,int,int);
	int getSet() const;
	void setSet(int);
	COLORREF getColor() const;
	virtual void Draw(CDC *dc)
	{

	}
	virtual ~Figure(void);

private:
	int x1,y1,x2,y2,set;
	COLORREF color;
};

class RectangleM:public Figure
{
	DECLARE_SERIAL (RectangleM)   
public:
	RectangleM();
	RectangleM(int xx1,int yy1, int xx2, int yy2)
		:Figure(xx1,yy1,xx2,yy2)
	{

	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(this->getColor());
		oldBrush=dc->SelectObject( &myBrush );
		dc->Rectangle(getX1(),getY1(),getX2(),getY2());
		dc->SelectObject( oldBrush ); 
	}
};
class EllipseM:public Figure
{
	DECLARE_SERIAL (EllipseM)    
public:
	EllipseM();
	EllipseM(int xx1,int yy1, int xx2, int yy2)
		:Figure(xx1,yy1,xx2,yy2)
	{
	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(this->getColor());
		oldBrush=dc->SelectObject( &myBrush );
		dc->Ellipse(getX1(),getY1(),getX2(),getY2());
		dc->SelectObject( oldBrush ); 
	}
};


class CircleM:public EllipseM
{
	DECLARE_SERIAL (CircleM)

public:
	CircleM();
	CircleM(int xx1,int yy1,int xx2, int yy2):EllipseM(xx1,yy1,xx2,yy2)
	{

	}
	void Draw(CDC *dc)
	{
		int midY = (getY1() + getY2())/2;
		int midX = (getX1() + getX2())/2;
		CPoint p1(midX , midY); // get the center as a point
		int distY = abs(getY1() - midY);
		int distX = abs(getX1() - midX);
		int minDist = min(distX , distY);

		CBrush myBrush,*oldBrush;

		myBrush.CreateSolidBrush(this->getColor());
		oldBrush=dc->SelectObject( &myBrush );
		dc->Ellipse(p1.x-minDist , p1.y-minDist , p1.x+minDist+1 , p1.y+minDist+1);
		dc->SelectObject( oldBrush ); 
	}
};