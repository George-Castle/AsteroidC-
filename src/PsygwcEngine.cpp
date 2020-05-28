#include "header.h"
#include "templates.h"
#include "PsygwcEngine.h"
#include "PsygwcObject.h"
#include "PsygwcAsteroid.h"
#include "TileManager.h"
#include "PsygwcMeteor.h"
#include "BaseEngine.h"
#include "PsygwcTileManager.h"
#include "JPGImage.h"#include <iostream>
#include <fstream>
using namespace std;
PsygwcEngine::PsygwcEngine(void) 
	:m_pRocket(NULL)
	,m_pMeteor(NULL)
	, m_state(stateInit)
{
}

PsygwcEngine::~PsygwcEngine(void)
{
}


void PsygwcEngine::SetupBackgroundBuffer()
{
	switch (m_state)
	{
	case stateInit:
		FillBackground(0x000000);
		{
			for (int iX = 0; iX < GetWindowWidth(); iX++)
				for (int iY = 0; iY < this->GetWindowHeight(); iY++)
					switch (rand() % 400)
					{
					case 0: SetBackgroundPixel(iX, iY, 0xFFFFFF); break;
					}
			DrawBackgroundOval(-200, -200, 110, 800, 0x23297A);
			DrawBackgroundOval(600, 40, 700, 140, 0x808080);
			DrawBackgroundOval(655, 70, 665, 80, 0x696969);
			DrawBackgroundOval(650, 90, 690, 130, 0x696969);
			DrawBackgroundOval(653, 93, 687, 127, 0x808080);
			DrawBackgroundOval(655, 95, 685, 125, 0x696969);
			DrawBackgroundOval(620, 100, 640, 120, 0x696969);
			DrawBackgroundOval(670, 50, 685, 65, 0x696969);
			DrawBackgroundOval(610, 60, 640, 90, 0x696969);
			DrawBackgroundPolygon(-10, 100, 100, 150,
				-5, 600, 50, 500,
				-500, 200, 80, 20,
				42, 300, 0x228B22);
			ImageData im, im2, im3;
			im2.LoadImage("Title.png");
			im.LoadImage("SpaceShuttle1.png");
			im3.ShrinkFrom(&im, 10);
			im2.RenderImageWithMask(this->GetBackground(),
				0, 0, 
				100, 160,
				im2.GetWidth(), im2.GetHeight());
			im3.RenderImageWithMask(this->GetBackground(),
				0, 0,
				110, 270,
				im3.GetWidth(), im3.GetHeight());
		}
		return;
	case stateMain:
		FillBackground(0x000000);
		for (int iX = 0; iX < GetWindowWidth(); iX++)
			for (int iY = 0; iY < this->GetWindowHeight(); iY++)
				switch (rand() % 400)
				{
				case 0: SetBackgroundPixel(iX, iY, 0xFFFFFF); break;
				}
		m_oTiles.SetSize(60, 1);
		for (int x = 0; x < 60; x++)
			for (int y = 0; y < 1; y++)
				m_oTiles.SetValue(x, y, rand() % 31);
		m_oTiles.SetBaseTilesPositionOnScreen(40, 580);
		m_oTiles.DrawAllTiles(this, this->GetBackground(), 0, 0, 59, 0);
		break;
	case stateMain2:
		FillBackground(0x000000);
		{
			ImageData Background1;
			Background1.LoadImage("Space2.png");
			Background1.RenderImageWithMask(this->GetBackground(),
				0, 0,
				0, 0,
				Background1.GetWidth(), Background1.GetHeight());
			m_oTiles.SetSize(60, 1);
			for (int x = 0; x < 60; x++)
				for (int y = 0; y < 1; y++)
				{
					
					if(x<Tiles)
						m_oTiles.SetValue(x, y, 40);
					else
						m_oTiles.SetValue(x, y, rand() % 31);
				}
			m_oTiles.SetBaseTilesPositionOnScreen(40, 580);
			m_oTiles.DrawAllTiles(this, this->GetBackground(), 0, 0, 59, 0);
		}
		break;
	case stateMain3:
		FillBackground(0x000000);
		{
			ImageData Cosmos;
			Cosmos.LoadImage("Cosmos3.png");
			Cosmos.RenderImageWithMask(this->GetBackground(),
				0, 0,
				0, 0,
				Cosmos.GetWidth(), Cosmos.GetHeight());
			m_oTiles.SetSize(60, 1);
			for (int x = 0; x < 60; x++)
				for (int y = 0; y < 1; y++)
					if (x<Tiles)
						m_oTiles.SetValue(x, y, 40);
					else
						m_oTiles.SetValue(x, y, rand() % 31);
			m_oTiles.SetBaseTilesPositionOnScreen(40, 580);
			m_oTiles.DrawAllTiles(this, this->GetBackground(), 0, 0, 59, 0);
		}
		break;
	case stateSave:
		FillBackground(0x000000);
		{
			for (int iX = 0; iX < GetWindowWidth(); iX++)
				for (int iY = 0; iY < this->GetWindowHeight(); iY++)
					switch (rand() % 400)
					{
					case 0: SetBackgroundPixel(iX, iY, 0xFFFFFF); break;
					}
			DrawBackgroundOval(-200, -200, 110, 800, 0x23297A);
			DrawBackgroundOval(600, 40, 700, 140, 0x808080);
			DrawBackgroundOval(655, 70, 665, 80, 0x696969);
			DrawBackgroundOval(650, 90, 690, 130, 0x696969);
			DrawBackgroundOval(653, 93, 687, 127, 0x808080);
			DrawBackgroundOval(655, 95, 685, 125, 0x696969);
			DrawBackgroundOval(620, 100, 640, 120, 0x696969);
			DrawBackgroundOval(670, 50, 685, 65, 0x696969);
			DrawBackgroundOval(610, 60, 640, 90, 0x696969);
			DrawBackgroundPolygon(-10, 100, 100, 150,
				-5, 600, 50, 500,
				-500, 200, 80, 20,
				42, 300, 0x228B22);
			ImageData im, im3;
			im.LoadImage("SpaceShuttle1.png");
			im3.ShrinkFrom(&im, 10);
			im3.RenderImageWithMask(this->GetBackground(),
				0, 0,
				110, 270,
				im3.GetWidth(), im3.GetHeight());
		}
		return;
	}
}


int PsygwcEngine::InitialiseObjects(void)
{
	DrawableObjectsChanged();
	// Destroy any existing objects
	DestroyOldObjects();


	m_pRocket = new PsygwcObject(this, &m_oTiles);
	m_pMeteor = new PsygwcMeteor(this, 200);
	m_pMeteor->SetPosition(GetWindowWidth(), 100);
	m_pMeteor->SetSpeed(1, 1);
	switch (m_state)
	{
	
	case stateMain:
		CreateObjectArray(4);
		StoreObjectInArray(0, m_pRocket);
		StoreObjectInArray(1, new PsygwcAsteroid(this, 1));
		StoreObjectInArray(2, new PsygwcAsteroid1(this, 2));
		StoreObjectInArray(3, NULL);
		break;
	case stateMain2:
		CreateObjectArray(5);
		StoreObjectInArray(0, m_pRocket);
		StoreObjectInArray(1, m_pMeteor);
		StoreObjectInArray(2, new PsygwcAsteroid(this, 1));
		StoreObjectInArray(3, new PsygwcAsteroid1(this, 2));
		StoreObjectInArray(4, NULL);
		break;
	case stateMain3:
		CreateObjectArray(6);
		StoreObjectInArray(0, m_pRocket);
		StoreObjectInArray(1, m_pMeteor);
		StoreObjectInArray(2, new PsygwcAsteroid(this, 1));
		StoreObjectInArray(3, new PsygwcAsteroid1(this, 2));
		StoreObjectInArray(4, new PsygwcAsteroid2(this, 3));
		StoreObjectInArray(5, NULL);
		break;
	}
	return 0;
}

void PsygwcEngine::MouseDown(int iButton, int iX, int iY)
{
	if (Tiles < 60) {
		m_pRocket->Leap(iX, iY);
		m_oTiles.UpdateTile(this, Tiles, 0, 40);
		Tiles += 1;
	}
}

void PsygwcEngine::DrawStringsUnderneath()
{
	char buf[128];
	switch (m_state)
	{
	case stateInit:
		CopyBackgroundPixels(0/*X*/, 0/*Y*/, GetWindowWidth(), 40/*Height*/);
		DrawForegroundString(250, 400, "Press Space To Play", 0xffffff, NULL);
		DrawForegroundString(170, 450, "Press Tab To View High Scores", 0xffffff, NULL);
		DrawForegroundString(150, 500, "Enter Ship Number between 0-9: ", 0xffffff, NULL);
		break;
	case stateSave:
		ifstream infile("Scores.txt");
		int one;
		int score[3];
		int i = 0;
		while(infile >> one)
		{ 
			score[i] = one;
			i++;
		}
		CopyBackgroundPixels(0/*X*/, 0/*Y*/, GetWindowWidth(), 40/*Height*/);
		DrawForegroundString(355, 100, "Scores", 0xffffff, NULL);
		DrawForegroundString(10, 10, "Tab to go back", 0xffffff, NULL);
		sprintf(buf, "1: %d", score[0]);
		DrawForegroundString(345, 400, buf, 0xffffff, NULL);
		sprintf(buf, "2: %d", score[1]);
		DrawForegroundString(345, 450, buf, 0xffffff, NULL);
		sprintf(buf, "3: %d", score[2]);
		DrawForegroundString(345, 500, buf, 0xffffff, NULL);
		break;

	}
}
void PsygwcEngine::DrawStringsOnTop()
{
	char buf[128];
	switch (m_state)
	{
	case statePaused:
		CopyBackgroundPixels(0/*X*/, 0/*Y*/, GetWindowWidth(), 40/*Height*/);
		DrawForegroundString(10, 10, "Paused. Press SPACE to continue", 0xffffff, NULL);
		break;
	case stateEnd:
		CopyBackgroundPixels(0/*X*/, 0/*Y*/, GetWindowWidth(), 40/*Height*/);
		DrawForegroundString(320, 250, "Game Over!", 0xffffff, NULL);
		DrawForegroundString(10, 10, "Tab to go to Menu", 0xffffff, NULL);
		sprintf(buf, "Score: %d", m_iScore);
		DrawForegroundString(310, 400, buf, 0xffffff, NULL);
		break;
	case stateMain:
		DrawForegroundString(10, 10, "Phase 1", 0xffffff, NULL);
		sprintf(buf, "Score: %d", GetTime() - m_iCTime);
		DrawForegroundString(550, 10, buf, 0xffffff, NULL);
		break;
	case stateMain2:
		DrawForegroundString(10, 10, "Phase 2: No Pausing!", 0xffffff, NULL);
		sprintf(buf, "Score: %d", GetTime() - m_iCTime);
		DrawForegroundString(550, 10, buf, 0xffffff, NULL);
		break;
	case stateMain3:
		DrawForegroundString(10, 10, "Phase 3: No Pausing!", 0xffffff, NULL);
		sprintf(buf, "Score: %d", GetTime() - m_iCTime);
		DrawForegroundString(550, 10, buf, 0xffffff, NULL);
		break;
	}
}
void PsygwcEngine::UnDrawStrings() 
{
	CopyBackgroundPixels(545/*X*/, 5/*Y*/, 300, 40/*Height*/);
}
void PsygwcEngine::GameAction()
{
	
	if (!IsTimeToAct()) 
		return;
	SetTimeToAct(15);

	switch (m_state)
	{
	case stateInit:
	case stateSave:
	case statePaused:
		break;
	case stateMain:
		// Only tell objects to move when not paused etc
		UpdateAllObjects(GetModifiedTime());
		if (m_iEnd == 3)
		{
			m_iScore = GetTime() - m_iCTime;
			m_state = stateEnd;
		}
			
		if ((GetTime() - m_iCTime) > 10000)
		{
			m_state = stateMain2;
			InitialiseObjects();
			SetupBackgroundBuffer();
			
			// Redraw the whole screen now
			Redraw(true);
			break;
		}
		break;
	case stateMain2:
		UpdateAllObjects(GetModifiedTime());
		if (m_iEnd == 3)
		{
			m_iScore = GetTime() - m_iCTime;
			m_state = stateEnd;
		}
		if ((GetTime() - m_iCTime) > 120000)
		{
			m_state = stateMain3;
			InitialiseObjects();
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}
		break;
	case stateMain3:
		if (m_iEnd == 3)
		{
			m_iScore = GetTime() - m_iCTime;
			m_state = stateEnd;
		}
		UpdateAllObjects(GetModifiedTime());
		break;
	case stateEnd:
		UndrawObjects();
		ofstream myfile;
		ifstream infile("Scores.txt");
		int score[3];
		int a = 0;
		int i = 0;
		int j = 0;
		while (infile >> a)
		{
			score[i] = a;
			i++;
		}
		while (score[j] > m_iScore)
		{
			j+=1;
			if (j == 3)
				break;
		}
		if (j < 3)
		{
			if (j == 0)
			{
				if (score[j] != m_iScore) 
				{
					score[j + 2] = score[j + 1];
					score[j + 1] = score[j];
				}
				score[j] = m_iScore;
			}
			if (j == 1)
			{
				if(score[j] != m_iScore)
					score[j + 1] = score[j];
				score[j] = m_iScore;
			}
			if (j == 2)
			{
				score[j] = m_iScore;

			}

		}
		myfile.open("Scores.txt");
		for (int y = 0; y < 3; y++) 
		{
			myfile << score[y] << '\n';
			
		}
		myfile.close();
		break;

	}
}
void PsygwcEngine::KeyDown(int iKeyCode)
{
	// NEW SWITCH on current state
	switch (iKeyCode)
	{
	case SDLK_0:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "0", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "0";
			break;
		}
		break;
	case SDLK_1:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "1", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "1";
			break;
		}
		break;
	case SDLK_2:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "2", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "2";
			break;
		}
		break;
	case SDLK_3:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "3", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "3";
			break;
		}
		break;
	case SDLK_4:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "4", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "4";
			break;
		}
		break;
	case SDLK_5:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "5", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "5";
			break;
		}
		break;
	case SDLK_6:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "6", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "6";
			break;
		}
		break;
	case SDLK_7:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "7", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "7";
			break;
		}
		break;
	case SDLK_8:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "8", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "8";
			break;
		}
		break;
	case SDLK_9:
		switch (m_state)
		{
		case stateInit:
			DrawBackgroundString(620, 500, "9", 0xffffff, NULL);
			Redraw(true);
			m_iSNum = "9";
			break;
		}
		break;
	case SDLK_BACKSPACE:
		switch (m_state)
		{
		case stateInit:
			SetupBackgroundBuffer();
			Redraw(true);
		}
		break;
	case SDLK_ESCAPE: // End program when escape is pressed
		SetExitWithCode(0);
		break;
	case SDLK_SPACE: // SPACE Pauses
		switch (m_state)
		{
		case stateInit:
			// Go to state main
			m_state = stateMain;
			m_iCTime = GetTime();
			InitialiseObjects();
			// Force redraw of background
			SetupBackgroundBuffer();
			// Redraw the whole screen now
			Redraw(true);
			break;
		case stateMain:
			m_state = statePaused;
			m_iPauseStarted = GetTime();
			Redraw(true);
			break;
		case statePaused:
			m_state = stateMain;
			IncreaseTimeOffset(m_iPauseStarted - GetTime());
			m_iCTime += (GetTime() - m_iPauseStarted);
			Redraw(true);
			break;
		} 
		break; 
	case SDLK_TAB:
		switch (m_state)
		{
		case stateInit:
			m_state = stateSave;
			SetupBackgroundBuffer();
			InitialiseObjects();
			Redraw(true);
			break;
		
		case stateSave:
			m_state = stateInit;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		case stateEnd:
			m_state = stateInit;
			SetupBackgroundBuffer();
			m_iEnd = 0;
			Tiles = 0;
			Redraw(true);
			break;
		}
	}
	

	
}

void PsygwcEngine::UndrawObjects()
{
	if (m_state != stateInit) 
		BaseEngine::UndrawObjects();
}

void PsygwcEngine::DrawObjects()
{
	if (m_state != stateInit)
		BaseEngine::DrawObjects();
}

