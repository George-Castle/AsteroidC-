#pragma once
#include "BaseEngine.h"
#include "TileManager.h"
#include "PsygwcTileManager.h"

class PsygwcObject;
class PsygwcMeteor;
class PsygwcEngine :
	public BaseEngine
{
protected:
	PsygwcObject* m_pRocket;
	//TileManager obTileManager;
	PsygwcMeteor* m_pMeteor;

public:
	PsygwcEngine();
	~PsygwcEngine();
	
	void SetupBackgroundBuffer();
	int InitialiseObjects();
	void MouseDown(int iButton, int iX, int iY);
	void DrawStringsUnderneath();
	void DrawStringsOnTop();
	void UnDrawStrings();
	virtual void GameAction();
	virtual void KeyDown(int iKeyCode);
	virtual void UndrawObjects();
	virtual void DrawObjects();

	PsygwcTileManager& GetTileManager() { return m_oTiles; }
private:
	PsygwcTileManager m_oTiles;
public:
	enum State { stateInit, stateMain, statePaused, stateMain2, stateMain3, stateEnd, stateSave };
	int m_iPauseStarted;
	int m_iEnd;
	int m_iCTime;
	int Tiles = 0;
	int m_iCScore;
	int m_iScore;
	char* m_iSNum = "11";
private:
	State m_state;
};

