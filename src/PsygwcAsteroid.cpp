#include "header.h"
#include "templates.h"
#include "PsygwcAsteroid.h"
#include "JPGImage.h"

ImageData im3, im24;


PsygwcAsteroid::PsygwcAsteroid(PsygwcEngine* pEngine, int iMapY)
	: DisplayableObject(pEngine)
{
	im24.LoadImage("asteroid1.png");
	im3.ShrinkFrom(&im24, 3);

	m_iCurrentScreenX = m_iPreviousScreenX = 800;
	m_iCurrentScreenY = m_iPreviousScreenY = rand() %500;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = im3.GetWidth();
	m_iDrawHeight = im3.GetHeight();

	SetVisible(true);
}


PsygwcAsteroid::~PsygwcAsteroid()
{
}


void PsygwcAsteroid::Draw()
{
	im3.RenderImageWithMask(m_pEngine->GetForeground(),
		0, 0,
		m_iCurrentScreenX, m_iCurrentScreenY,
		im3.GetWidth(), im3.GetHeight());
	

	StoreLastScreenPositionForUndraw();
}


void PsygwcAsteroid::DoUpdate(int iCurrentTime)
{
	
	m_iCurrentScreenX -= 2;

	if (m_iCurrentScreenX < -88) {
		m_iCurrentScreenX = GetEngine()->GetWindowWidth() - m_iDrawWidth;
		m_iCurrentScreenY = rand() %(580 -m_iDrawHeight);
	}
		
	RedrawObjects();
}

PsygwcAsteroid1::PsygwcAsteroid1(PsygwcEngine* pEngine, int iMapY)
	:PsygwcAsteroid(pEngine, iMapY)
{}
void PsygwcAsteroid1::DoUpdate(int iCurrentTime)
{

	m_iCurrentScreenX -= 3;

	if (m_iCurrentScreenX < -88) {
		m_iCurrentScreenX = GetEngine()->GetWindowWidth() - m_iDrawWidth;
		m_iCurrentScreenY = rand() % (580 - m_iDrawHeight);
	}

	RedrawObjects();
}
PsygwcAsteroid2::PsygwcAsteroid2(PsygwcEngine* pEngine, int iMapY)
	:PsygwcAsteroid(pEngine, iMapY)
{}
void PsygwcAsteroid2::DoUpdate(int iCurrentTime)
{

	m_iCurrentScreenX -= 4;

	if (m_iCurrentScreenX < -88) {
		m_iCurrentScreenX = GetEngine()->GetWindowWidth() - m_iDrawWidth;
		m_iCurrentScreenY = rand() % (580 - m_iDrawHeight);
	}

	RedrawObjects();
}
