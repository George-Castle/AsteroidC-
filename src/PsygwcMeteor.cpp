#include "header.h"
#include "templates.h"
#include "PsygwcMeteor.h"
#include "JPGImage.h"
ImageData im4, im25;


PsygwcMeteor::PsygwcMeteor(BaseEngine* pEngine, int iMapY)
	: DisplayableObject(pEngine)
{
	im25.LoadImage("meteor.png");
	im4.ShrinkFrom(&im25, 6);


	m_iCurrentScreenX = m_iPreviousScreenX = 800;
	m_iCurrentScreenY = m_iPreviousScreenY = iMapY;
	
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = im4.GetWidth();
	m_iDrawHeight = im4.GetHeight();

	SetVisible(true);
}


PsygwcMeteor::~PsygwcMeteor()
{
}

void PsygwcMeteor::Draw()
{
	im4.RenderImageWithMask(m_pEngine->GetForeground(),
		0, 0,
		m_iCurrentScreenX, m_iCurrentScreenY,
		im4.GetWidth(), im4.GetHeight());

	StoreLastScreenPositionForUndraw();
}

void PsygwcMeteor::SetPosition(double dX, double dY)
{
	m_dX = dX;
	m_dY = dY;
}

void PsygwcMeteor::SetSpeed(double dSX, double dSY)
{
	m_dSX = dSX;
	m_dSY = dSY;
}
void PsygwcMeteor::DoUpdate(int iCurrentTime)
{
	if (GetEngine()->IsKeyPressed(SDLK_UP))
		m_dSY -= 0.01;
	if (GetEngine()->IsKeyPressed(SDLK_DOWN))
		m_dSY += 0.01;
	
	m_dSX -= 0.1;
	
	m_dX += m_dSX/50;
	m_dY += m_dSY;

	if ((m_dX + m_iStartDrawPosX) < 0)
	{
		m_dX = GetEngine()->GetWindowWidth() - 1 - m_iStartDrawPosX - m_iDrawWidth;
	
	}

	if ((m_dX + m_iStartDrawPosX + m_iDrawWidth) >(GetEngine()->GetWindowWidth() - 1))
	{
		m_dX = -m_iStartDrawPosX;
		
	}

	if ((m_dY + m_iStartDrawPosY) < 0)
	{
		m_dY = -m_iStartDrawPosY;
		if (m_dSY < 0)
			m_dSY = -m_dSY;
	}

	if ((m_dY + m_iStartDrawPosY + m_iDrawHeight) >(GetEngine()->GetWindowHeight() - 21))
	{
		m_dY = GetEngine()->GetWindowHeight() - 21 - m_iStartDrawPosY - m_iDrawHeight;
		if (m_dSY > 0)
			m_dSY = -m_dSY;
	}

	
	m_iCurrentScreenX = (int)(m_dX + 0.5);
	m_iCurrentScreenY = (int)(m_dY + 0.5);

	
	RedrawObjects();
}
