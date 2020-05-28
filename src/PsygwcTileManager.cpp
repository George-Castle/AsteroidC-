#include "header.h"
#include "templates.h"
#include "PsygwcTileManager.h"



PsygwcTileManager::PsygwcTileManager(void) : TileManager(10, 12)
{

}


PsygwcTileManager::~PsygwcTileManager(void)
{
}

void PsygwcTileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	int i;
	i = GetValue(iMapX, iMapY);
	
	if (i < 32)
	{
			pEngine->DrawRectangle(
				iStartPositionScreenX,
				iStartPositionScreenY,
				iStartPositionScreenX + GetTileWidth() - 1,
				iStartPositionScreenY + GetTileHeight() - 1,
				0xffffff,
				pSurface);
	}
	if (i > 32) {
		pEngine->DrawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + GetTileWidth() - 1,
			iStartPositionScreenY + GetTileHeight() - 1,
			0xff4500,
			pSurface);
	}
}


