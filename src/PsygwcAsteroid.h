#include "header.h"
#include "templates.h"
#include "DisplayableObject.h"
#include "PsygwcEngine.h"


class PsygwcAsteroid :
	public DisplayableObject
{
public:
	PsygwcAsteroid(PsygwcEngine* pEngine, int iMapY);
	~PsygwcAsteroid();
	void Draw();
	void DoUpdate(int iCurrentTime);
};

class PsygwcAsteroid1 :
	public PsygwcAsteroid
{
public:
	PsygwcAsteroid1(PsygwcEngine* pEngine, int iMapY);
	void DoUpdate(int iCurrentTime);
};
class PsygwcAsteroid2 :
	public PsygwcAsteroid
{
public:
	PsygwcAsteroid2(PsygwcEngine* pEngine, int iMapY);
	void DoUpdate(int iCurrentTime);
};