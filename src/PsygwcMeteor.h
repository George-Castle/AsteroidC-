#pragma once
#include "DisplayableObject.h"
#include "MovementPosition.h"
class PsygwcMeteor :
	public DisplayableObject
{
public:
	PsygwcMeteor(BaseEngine* pEngine, int iMapY);
	~PsygwcMeteor(void);
	void Draw();
	
	void SetPosition(double dX, double dY);

	void SetSpeed(double dSX, double dSY);

	void DoUpdate(int iCurrentTime);

protected:
	double m_dX;
	double m_dY;
	double m_dSX;
	double m_dSY;
};

