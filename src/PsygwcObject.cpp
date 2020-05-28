#include "header.h"
#include "templates.h"
#include "PsygwcObject.h"
#include "JPGImage.h"

ImageData im, im2;
ImageData flash, f, flash2, f2;
int flashing = 0;


PsygwcObject::PsygwcObject(PsygwcEngine* pEngine, PsygwcTileManager* pTileManager)
	: DisplayableObject(pEngine)
	, m_pEngine(pEngine)
{
	f.LoadImage("flash.png");
	flash.ShrinkFrom(&f, 2);
	f2.LoadImage("flash2.png");
	flash2.ShrinkFrom(&f2, 2);
	im2.LoadImage("SpaceShuttle1.png");
	im.ShrinkFrom(&im2, 10);

	m_iCurrentScreenX = m_iPreviousScreenX = 110;
	m_iCurrentScreenY = m_iPreviousScreenY = 270;
	
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = im.GetWidth() + flash.GetWidth();
	m_iDrawHeight = im.GetHeight();

	SetVisible(true);
}


PsygwcObject::~PsygwcObject(void)
{
}


void PsygwcObject::Draw()
{
	int iCentreX = m_iCurrentScreenX + 20 + m_iDrawWidth / 2;
	int iCentreY = m_iCurrentScreenY + m_iDrawHeight / 2;
	im.RenderImageWithMask(m_pEngine->GetForeground(),
		0, 0,
		m_iCurrentScreenX + flash.GetWidth() - 5, m_iCurrentScreenY,
		im.GetWidth(), im.GetHeight());
	GetEngine()->DrawForegroundString(iCentreX +33 , iCentreY- 13 , m_pEngine->m_iSNum, 0x000000);
	if(flashing == 0)
	{
		flash.RenderImageWithMask(m_pEngine->GetForeground(),
			0, 0,
			m_iCurrentScreenX, m_iCurrentScreenY+15,
			flash.GetWidth(), flash.GetHeight());
	}
	if(flashing == 1)
	{
		flash2.RenderImageWithMask(m_pEngine->GetForeground(),
			0, 0,
			m_iCurrentScreenX, m_iCurrentScreenY+15,
			flash2.GetWidth(), flash2.GetHeight());
	}
	StoreLastScreenPositionForUndraw();
}


void PsygwcObject::DoUpdate(int iCurrentTime)
{
	int i = 0;
	int j = 0;

	DisplayableObject* pObject;
	for (int iObjectId = 0;
		(pObject = m_pEngine->GetDisplayableObject(iObjectId)
			) != NULL;
		iObjectId++)
	{
		if (pObject == this) 
			continue;

		int iXDiff = abs((pObject->GetXCentre()) - (m_iCurrentScreenX + (flash.GetWidth() + (im.GetWidth() / 2))));
		int iYDiff = abs((pObject->GetYCentre()) - (m_iCurrentScreenY + (m_iDrawHeight / 2)));
	

		if ((iXDiff < ((im.GetWidth() /2))) && (iYDiff <((m_iDrawHeight/2))))
		{
				m_pEngine->m_iEnd = 3;
				return;
		}
	}

	if (GetEngine()->IsKeyPressed(SDLK_UP))
		m_iCurrentScreenY -= 2.2;
	if (GetEngine()->IsKeyPressed(SDLK_DOWN))
		m_iCurrentScreenY += 2.2;
	
	m_iCurrentScreenX -= 2;


	if (m_iCurrentScreenX < 100)
		m_iCurrentScreenX = 100;
	if (m_iCurrentScreenX >= GetEngine()->GetWindowWidth() - m_iDrawWidth)
		m_iCurrentScreenX = GetEngine()->GetWindowWidth() - m_iDrawWidth;
	if (m_iCurrentScreenY < 0)
		m_iCurrentScreenY = 0;
	if (m_iCurrentScreenY >= GetEngine()->GetWindowHeight() - m_iDrawHeight - 20)
		m_iCurrentScreenY = GetEngine()->GetWindowHeight() - m_iDrawHeight - 20;

	if (flashing == 0)
		flashing = 1;
	else
		flashing = 0;

	RedrawObjects();
}
void PsygwcObject::Leap(double dX, double dY)
{
	m_iCurrentScreenX += 100;

}