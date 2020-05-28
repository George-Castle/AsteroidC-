#include "header.h"
#include "templates.h"
#include "DisplayableObject.h"
#include "PsygwcEngine.h"
class BaseEngine;
class PsygwcObject :
	public DisplayableObject
{
public:
	PsygwcObject(PsygwcEngine*pEngine, PsygwcTileManager* pTileManager);
	~PsygwcObject(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	void Leap(double dX, double dY);
private:
	/** Pointer to the main engine object */
	PsygwcEngine* m_pEngine;
};

