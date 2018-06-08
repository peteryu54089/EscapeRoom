/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "mygame.h"
#include <string>
#include <time.h>

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame* g) : CGameState(g)
	{
	
	}

	CGameStateInit::~CGameStateInit()
	{
	
	}

	void CGameStateInit::OnInit()
	{

		//
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
		//
		// �}�l���J���
		//
		Background.LoadBitmap("Bitmaps\\map\\clickToStart.bmp");
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");
		CAudio::Instance()->Load(AUDIO_BGM, "sounds\\BGM.MP3");
		CAudio::Instance()->Load(AUDIO_0, "sounds\\sound_zero.wav");
		CAudio::Instance()->Load(AUDIO_1, "sounds\\sound_one.wav");
		CAudio::Instance()->Load(AUDIO_2, "sounds\\sound_two.wav");
		CAudio::Instance()->Load(AUDIO_3, "sounds\\sound_three.wav");
		CAudio::Instance()->Load(AUDIO_4, "sounds\\sound_four.wav");
		CAudio::Instance()->Load(AUDIO_5, "sounds\\sound_five.wav");
		CAudio::Instance()->Load(AUDIO_6, "sounds\\sound_six.wav");
		CAudio::Instance()->Load(AUDIO_7, "sounds\\sound_seven.wav");
		CAudio::Instance()->Load(AUDIO_8, "sounds\\sound_eight.wav");
		CAudio::Instance()->Load(AUDIO_9, "sounds\\sound_nine.wav");
		CAudio::Instance()->Load(AUDIO_ERROR, "sounds\\error.MP3");
		CAudio::Instance()->Load(AUDIO_BROTHER, "sounds\\brother.MP3");
		CAudio::Instance()->Load(AUDIO_GUN, "sounds\\gun.MP3");
		CAudio::Instance()->Load(AUDIO_GUN2, "sounds\\gun2.MP3");
		CAudio::Instance()->Load(AUDIO_DOOR, "sounds\\door.MP3");
		CAudio::Instance()->Load(AUDIO_CAR, "sounds\\car.MP3");

		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
		//
	}

	void CGameStateInit::OnBeginState()
	{
	
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		if (nChar == KEY_ESC)								        // Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
		CAudio::Instance()->Play(AUDIO_DING);
		CAudio::Instance()->Play(AUDIO_BGM, 1);
		//CAudio::Instance()->Play(AUDIO_BROTHER);
	}

	void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point)
	{
	
	}


	void CGameStateInit::OnShow()
	{
		//
		// �K�Wlogo
		//
		Background.ShowBitmap();
		//
		// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
		//
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	CGameStateOver::CGameStateOver(CGame* g) : CGameState(g)
	{
	
	}

	void CGameStateOver::OnMove()
	{
		counter--;

		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}

	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 5; // 5 seconds
	}

	void CGameStateOver::OnInit()
	{
		//
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
		//
		// �}�l���J���
		//
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// �̲׶i�׬�100%
		//
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "Game Over ! (%d)", counter / 30);
		pDC->TextOut(240, 210, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	CGameStateRun::CGameStateRun(CGame* g): CGameState(g)
	{
		digit = 0;
		mapNow = 1;
		objNow = 7;
		mapTemp = 15;
		mes = true;
		mapMove = false;
		npcMove = false;
		macMove = false;
		chooseMovie = false;
		password7 = 1604;
		password9 = 25689;
		passwordInput = 0;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < OBJ_SIZE; j++)
			{
				hideArr[j] = 0;
				mapArr[i][j] = new CAnimation(1);
			}
		}
		hideArr[0] = 1;
		hideArr[5] = 1;
		hideArr[7] = 1;
		for (int i = 0; i < HIDEOBJ_SIZE; i++)
			hideArr[hideObj[i]] = 1;
		mac = new CAnimation(1);
		npcBefore = new CAnimation(50);
		npcAfter = new CAnimation(50);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				pic[i][j] = new CAnimation(1);
				picMove[i][j] = false;
			}
		}
		for (int i = 0; i < ADD_SIZE; i++)
		{
			if (i == 7 || i == 16 || i == 17 || i == 18 || i == 19 || i == 25 || i == 31)
				add[i] = new CAnimation(20);
			else if(i == 6 || i == 29)
				add[i] = new CAnimation(2);
			else if (i == 26 || i == 27 || i == 28)
				add[i] = new CAnimation(3);
			else
			    add[i] = new CAnimation(1);
		}
		for (int i = 0; i < ADD_SIZE; i++)
			addMove[i] = false;
		addMove[22] = true;
	}

	CGameStateRun::~CGameStateRun()
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < OBJ_SIZE; j++)
				delete mapArr[i][j];
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 15; j++)
				delete pic[i][j];
		}
		for (int i = 0; i < ADD_SIZE; i++)
			delete add[i];
		delete mac;
		delete npcBefore;
		delete npcAfter;
	}

	void CGameStateRun::OnBeginState()
	{
		level.SetInteger(0);
		level.SetTopLeft(20, 80);
		experience.SetInteger(0);
		experience.SetTopLeft(20, 99);
		money.SetInteger(0);
		money.SetTopLeft(20, 118);
		levelExpMoney.SetTopLeft(0, 80);
		cama.SetTopLeft(560, 80);
		gamble.SetTopLeft(560, 160);
		pinball.SetTopLeft(0, 0);
		pull1.SetTopLeft(340, 444);
		pull2.SetTopLeft(340, 444);
		pull3.SetTopLeft(340, 444);
		pubg.SetTopLeft(560, 240);
		background2.SetTopLeft(0, 0);
		background.SetTopLeft(0, 0);
		end.SetTopLeft(0, 0);
		for (int i = 0; i < 7; i++)
		{
			rotationLeft[i].SetTopLeft(0, 0);
			rotationRight[i].SetTopLeft(0, 0);
		}
		for (int i = 0; i < 12; i++)
		{
			gameCard[i].SetTopLeft(animalX[i], animalY[i]);
			growButton[i].SetTopLeft(animalX[i], animalY[i] + 80);
			for (int j = 0; j < 4; j++)
				animal[i][j].SetTopLeft(animalX[i], animalY[i]);
		}
	}

	void CGameStateRun::OnMove()	// ���ʹC������
	{
		if (mapMove)
		    mes = true;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < OBJ_SIZE; j++)
			{
				if (mapMove && mapNow == i + 1)
				{
					mapArr[i][j]->Reset();
					for (int k = 0; k < BAGOBJ_SIZE; k++)
					{
						if ((mapNow != 15 && hideArr[j] == 1 && j != 0 && j != 5) || (mapNow == 15 && hideArr[j] == 0 && j == bagObj[k]))
						{
							if (!mapArr[i][j]->IsFinalBitmap())
								mapArr[i][j]->OnMove();	//�Y���O�̫�@�ӹϧΡA�NOnMove��̫�@�ӹϧΫᰱ��C
							break;
						}
					}
				}
				else if (mapMove)
				{
					if (!mapArr[i][j]->IsFinalBitmap())
						mapArr[i][j]->OnMove();	//�Y���O�̫�@�ӹϧΡA�NOnMove��̫�@�ӹϧΫᰱ��C
				}
			}
		}
		if (mapNow != 4)
		{
			npcBefore->Reset();
			npcAfter->Reset();
			npcMove = false;
		}
		else if (npcMove && objNow != 12)
		{
			if (!mapArr[3][41]->IsFinalBitmap())
				mapArr[3][41]->OnMove();
			if (!npcBefore->IsFinalBitmap())
				npcBefore->ToFirst();
		}
		else if (npcMove)
		{
			hideArr[9] = 1;
			if (!mapArr[3][41]->IsFinalBitmap())
				mapArr[3][41]->OnMove();
			if (!npcAfter->IsFinalBitmap())
				npcAfter->ToFirst();
			mapArr[3][41]->Reset();
		}
		if (macMove)
		{
			if (!mac->IsFinalBitmap())
				mac->OnMove();
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (picMove[i][j] == false)
				{
					if (!pic[i][j]->IsFinalBitmap())
						pic[i][j]->OnMove();
				}
				else
					pic[i][j]->Reset();
			}
		}
		for (int i = 0; i < ADD_SIZE; i++)
		{
			if (addMove[i])
			{
				if (!add[i]->IsFinalBitmap() && (i == 1 || i == 7 || i == 16 || i == 17 || i == 18 || i == 19 || i == 29 || i == 30))
					add[i]->ToFirst();
				else if (!add[i]->IsFinalBitmap())
					add[i]->OnMove();
				else if (i == 0)
					add[i]->Reset();
				if ((i == 1 || i == 7 || i == 16 || i == 17 || i == 18 || i == 19 || i == 29 || i == 30) && add[i]->IsFinalBitmap())
					add[i]->ToSecond();
				if ((i == 25 || i == 31) && add[i]->IsFinalBitmap())
					add[i]->Reset();
				if ((i == 26 || i == 27 || i == 28) && add[i]->IsFinalBitmap())
				{
					showPinball = false;
					add[i]->Reset();
					mapNow = mapTemp;
					mapTemp = 15;
					addMove[i] = false;
					shoot = false;
					CAudio::Instance()->Stop(15 + pinballMusic);
				}
			}
			else
			    add[i]->Reset();
		}
	}

	void CGameStateRun::OnInit()	// �C������Ȥιϧγ]�w
	{
		//
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(33);	    // ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
		//
		// �}�l���J���
		//
		Background.LoadBitmap("Bitmaps\\map\\map0.bmp");
		char test[100];
		string filePath;
		const string rootMap = "Bitmaps\\map\\map";
		const string rootObj = "Bitmaps\\obj\\obj";
		for (int i = 0; i < MAP_SIZE; i++)
		{
			filePath = rootMap + to_string(i + 1) + ".bmp";
			strcpy(test, filePath.c_str());
			mapArr[i][0]->AddBitmap(test, RGB(255, 255, 255));
			mapArr[i][0]->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
			for (int j = 1; j < OBJ_SIZE; j++)
			{
				filePath = rootObj + to_string(j) + ".bmp";
				strcpy(test, filePath.c_str());
				if (mapObj[i][j] == 1)
					mapArr[i][j]->AddBitmap(test, RGB(255, 255, 255));
				mapArr[i][j]->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
			}
		}
		const string rootNpc = "Bitmaps\\npc\\talk";
		npcBefore->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
		for (int i = 1; i <= 5; i++)
		{
			filePath = rootNpc + to_string(i) + ".bmp";
			strcpy(test, filePath.c_str());
			npcBefore->AddBitmap(test, RGB(255, 255, 255));
		}
		npcBefore->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
		npcAfter->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
		for (int i = 6; i <= 8; i++)
		{
			filePath = rootNpc + to_string(i) + ".bmp";
			strcpy(test, filePath.c_str());
			npcAfter->AddBitmap(test, RGB(255, 255, 255));
		}
		npcAfter->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
		//
		// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
		//
	    mac->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
		mac->AddBitmap("Bitmaps\\mac.bmp", RGB(255, 255, 255));
		const string rootPic = "Bitmaps\\pic\\pic";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				filePath = rootPic + to_string(j + 1) + ".bmp";
				strcpy(test, filePath.c_str());
				pic[i][j]->AddBitmap(test, RGB(255, 255, 255));
				pic[i][j]->AddBitmap("Bitmaps\\hide.bmp", RGB(255, 255, 255));
			}
		}
		const string rootAdd = "Bitmaps\\add";
		for (int i = 0; i < ADD_SIZE; i++)
		{
			for (int j = 0; j < addLength[i]; j++)
			{
				filePath = rootAdd + to_string(i) + "\\add" + to_string(j) + ".bmp";
				strcpy(test, filePath.c_str());
				add[i]->AddBitmap(test, RGB(255, 255, 255));
			}
		}
		level.LoadBitmapL();
		experience.LoadBitmapE();
		money.LoadBitmap();
		levelExpMoney.LoadBitmap("Bitmaps\\levelExpMoney.bmp", RGB(255, 255, 255));
		cama.LoadBitmap("Bitmaps\\cama.bmp", RGB(255, 255, 255));
		const string rootAnimal = "Bitmaps\\animal";
		for (int i = 0; i < 12; i++)
		{
			gameCard[i].LoadBitmap("Bitmaps\\gameCard.bmp", RGB(255, 255, 255));
			growButton[i].LoadBitmap("Bitmaps\\growButton.bmp", RGB(255, 255, 255));
			for (int j = 0; j < 4; j++)
			{
				filePath = rootAnimal + to_string(i + 1) + "\\a" + to_string(j + 1) + ".bmp";
				strcpy(test, filePath.c_str());
				animal[i][j].LoadBitmap(test, RGB(255, 255, 255));
			}
		}
		gamble.LoadBitmap("Bitmaps\\gamble.bmp", RGB(255, 255, 255));
		pinball.LoadBitmap("Bitmaps\\pinball.bmp", RGB(255, 255, 255));
		pull1.LoadBitmap("Bitmaps\\pull1.bmp", RGB(255, 255, 255));
		pull2.LoadBitmap("Bitmaps\\pull2.bmp", RGB(255, 255, 255));
		pull3.LoadBitmap("Bitmaps\\pull3.bmp", RGB(255, 255, 255));
		pubg.LoadBitmap("Bitmaps\\pubg.bmp", RGB(255, 255, 255));
		background2.LoadBitmap("Bitmaps\\background2.bmp", RGB(255, 255, 255));
		background.LoadBitmap("Bitmaps\\background.bmp", RGB(255, 255, 255));
		rotationLeft[0].LoadBitmap("Bitmaps\\rotationLeft\\rotation1.bmp", RGB(255, 255, 255));
		rotationLeft[1].LoadBitmap("Bitmaps\\rotationLeft\\rotation2.bmp", RGB(255, 255, 255));
		rotationLeft[2].LoadBitmap("Bitmaps\\rotationLeft\\rotation3.bmp", RGB(255, 255, 255));
		rotationLeft[3].LoadBitmap("Bitmaps\\rotationLeft\\rotation4.bmp", RGB(255, 255, 255));
		rotationLeft[4].LoadBitmap("Bitmaps\\rotationLeft\\rotation5.bmp", RGB(255, 255, 255));
		rotationLeft[5].LoadBitmap("Bitmaps\\rotationLeft\\rotation6.bmp", RGB(255, 255, 255));
		rotationLeft[6].LoadBitmap("Bitmaps\\rotationLeft\\rotation7.bmp", RGB(255, 255, 255));
		rotationRight[0].LoadBitmap("Bitmaps\\rotationRight\\rotation1.bmp", RGB(255, 255, 255));
		rotationRight[1].LoadBitmap("Bitmaps\\rotationRight\\rotation2.bmp", RGB(255, 255, 255));
		rotationRight[2].LoadBitmap("Bitmaps\\rotationRight\\rotation3.bmp", RGB(255, 255, 255));
		rotationRight[3].LoadBitmap("Bitmaps\\rotationRight\\rotation4.bmp", RGB(255, 255, 255));
		rotationRight[4].LoadBitmap("Bitmaps\\rotationRight\\rotation5.bmp", RGB(255, 255, 255));
		rotationRight[5].LoadBitmap("Bitmaps\\rotationRight\\rotation6.bmp", RGB(255, 255, 255));
		rotationRight[6].LoadBitmap("Bitmaps\\rotationRight\\rotation7.bmp", RGB(255, 255, 255));
		end.LoadBitmap("Bitmaps\\obj\\obj64.bmp", RGB(255, 255, 255));
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT  = 0x25; // keyboard���b�Y
		const char KEY_UP    = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
		if (nChar == KEY_LEFT || nChar == KEY_UP || nChar == KEY_RIGHT || nChar == KEY_DOWN)
		{
			back = true;
			addMove[30] = true;
			CAudio::Instance()->Play(AUDIO_GUN2, true);
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT  = 0x25; // keyboard���b�Y
		const char KEY_UP    = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
		const char KEY_SPACE = ' ';
		const char KEY_ESC = 27;
		if (nChar == KEY_ESC)								        // Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
		else if (nChar == KEY_LEFT || nChar == KEY_UP || nChar == KEY_RIGHT || nChar == KEY_DOWN)
		{
			back = false;
			addMove[30] = false;
			CAudio::Instance()->Stop(AUDIO_GUN2);
		}
		else if (nChar == KEY_SPACE)
		{
			endFlag = true;
			mapNow = 1200;
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{
		/*if (point.x > 560 && point.x < 640 && point.y > 80 && point.y < 160)
		{
			system("start chrome --allow-file-access-from-files");
			ShellExecute(NULL, "open", "JSTest\\demo\\AngryBird_demo\\game_sample.html", NULL, NULL, SW_SHOW);
			return;
		}*/
		if (mapNow == 1200)
		{
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
			return;
		}
		if (point.x > 560 && point.x < 640 && point.y > 240 && point.y < 320 && (mapNow == 1 || mapNow == 3 || mapNow == 6 || mapNow == 8 || mapNow == 9 || mapNow == 10 || mapNow == 11 || mapNow == 12 || mapNow == 13 || mapNow == 14))
		{
			mapTemp = mapNow;
			mapNow = 22;
			return;
		}
		if (mapNow == 22 && point.x < 640 && point.y > 240 && point.y < 320)
		{
			mapNow = mapTemp;
			mapTemp = 15;
			return;
		}
		if (mapNow == 21 && shoot == false)
		{
			if (point.x > 335 && point.x < 349 && point.y > 430 && point.y <= 480)
				clickPull = true;
		}
		if (mapNow == 4)
			CAudio::Instance()->Play(AUDIO_GUN, 1);
		if (point.x > 600 && point.x < 640 && point.y > 440 && point.y < 480)
		{
			if (addMove[22])
			{
				CAudio::Instance()->Pause();
				addMove[22] = false;
				addMove[23] = true;
			}
			else
			{
				CAudio::Instance()->Resume();
				addMove[22] = true;
				addMove[23] = false;
			}
			return;
		}
		if (mapNow == 7 && point.x > 420 && point.x < 500 && point.y > 80 && point.y < 240 && !chooseMovie)
		{
			addMove[24] = false;
			addMove[7] = false;
			addMove[16] = false;
			addMove[17] = false;
			addMove[18] = false;
			addMove[19] = false;
			chooseMovie = true;
		}
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 1; j < OBJ_SIZE; j++)
			{
				if (mapNow == 4)
				{
					addMove[0] = true;
					addMove[4] = false;
				}
				if (mapNow == 19 && point.x < 560)
				{
					for (int i = 0; i < MAP_SIZE; i++)
					{
						for (int j = 0; j < OBJ_SIZE; j++)
						    hideArr[j] = 0;
					}
					hideArr[0] = 1;
					hideArr[5] = 1;
					hideArr[7] = 1;
					for (int i = 0; i < HIDEOBJ_SIZE; i++)
						hideArr[hideObj[i]] = 1;
					level.SetInteger(0);
					experience.SetInteger(0);
					money.SetInteger(0);
					mapNow = 1;
					mapMove = true;
					return;
				}
				if (mapNow == 12 && j >= 61 && j <= 62 && mapObj[i][j] == 1 && hideArr[j] == 0 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mes = false;
					if (objNow != 0)
						mapArr[i][57]->Reset();
					else
					{
						mapArr[i][j + 2]->Reset();
						if (j == 62)
							mapNow *= 100;
						else
							mapNow = 19;
						return;
					}
				}
				if (mapNow == 14 && j == 61 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mapNow = 12;
					hideArr[61] = 0;
					hideArr[62] = 1;
					mapMove = true;
					return;
				}
				if (mapNow == 14 && j == 62 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mes = false;
					if (hideArr[20] != 1)
						mapArr[i][56]->Reset();
					else
					{
						mapNow = 12;
						hideArr[61] = 1;
						hideArr[62] = 0;
						mapMove = true;
						return;
					}
				}
				if (mapNow == i + 1 && j == 17 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mes = false;
					if (objNow != 10)
						mapArr[i][55]->Reset();
					else
					{
						if (!mapArr[i][56]->IsFinalBitmap())
							mapArr[i][56]->OnMove();
						if (!mapArr[i][61]->IsFinalBitmap())
							mapArr[i][61]->OnMove();
						if (!mapArr[i][62]->IsFinalBitmap())
							mapArr[i][62]->OnMove();
						mapArr[i][58]->Reset();
						mapNow = 16;
						return;
					}
				}
				if (mapNow == i + 1 && j == 15 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mes = false;
					if (!mapArr[i][40]->IsFinalBitmap())
						mapArr[i][40]->OnMove();
					if (!mapArr[i][42]->IsFinalBitmap())
						mapArr[i][42]->OnMove();
					if (!mapArr[i][43]->IsFinalBitmap())
						mapArr[i][43]->OnMove();
					if (!mapArr[i][44]->IsFinalBitmap())
						mapArr[i][44]->OnMove();
					if (!mapArr[i][45]->IsFinalBitmap())
						mapArr[i][45]->OnMove();
					if (!mapArr[i][52]->IsFinalBitmap())
						mapArr[i][52]->OnMove();
					for (int k = 30; k < 40; k++)
					{
						if (!mapArr[i][k]->IsFinalBitmap())
							mapArr[i][k]->OnMove();
						number[k - 30] = false;
					}
					if (hideArr[12] == 1 && hideArr[13] == 1 && hideArr[16] == 1 && hideArr[46] == 0)
					{
						mapArr[i][52]->Reset();
						hideArr[46] = 1;
					}
					else if(hideArr[46] == 0)
						mapArr[i][44]->Reset();
				}
				if (mapNow == i + 1 && j == 19 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					for (int k = 30; k < 40; k++)
					{
						mapArr[i][k]->Reset();
						number[k - 30] = true;
					}
					if (!mapArr[i][40]->IsFinalBitmap())
						mapArr[i][40]->OnMove();
					if (!mapArr[i][42]->IsFinalBitmap())
						mapArr[i][42]->OnMove();
					if (!mapArr[i][43]->IsFinalBitmap())
						mapArr[i][43]->OnMove();
					if (!mapArr[i][44]->IsFinalBitmap())
						mapArr[i][44]->OnMove();
					if (!mapArr[i][45]->IsFinalBitmap())
						mapArr[i][45]->OnMove();
					if (!mapArr[i][52]->IsFinalBitmap())
						mapArr[i][52]->OnMove();
					passwordInput = 0;
					digit = 0;
				}
				if (mapNow == i + 1 && j >= 30 && j <= 39 && number[j - 30] && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mes = false;
					digit++;
					number[j - 30] = false;
					passwordInput = passwordInput * 10 + j - 30;
					CAudio::Instance()->Play(j - 30);
					if (!mapArr[i][j]->IsFinalBitmap())
						mapArr[i][j]->OnMove();
					if ((mapNow == 7 && passwordInput == password7) || (mapNow == 7 && digit == 4 && passwordInput != password7) || (mapNow == 9 && passwordInput == password9) || (mapNow == 9 && digit == 5 && passwordInput != password9))
					{
						for (int k = 30; k < 40; k++)
						{
							if (!mapArr[i][k]->IsFinalBitmap())
								mapArr[i][k]->OnMove();
						}
					}
					if (mapNow == 7 && passwordInput == password7 && hideArr[10] == 0)
					{
						hideArr[10] = 1;
						mapArr[i][42]->Reset();
					}
					else if (mapNow == 9 && passwordInput == password9 && hideArr[11] == 0)
					{
						hideArr[11] = 1;
						mapArr[i][43]->Reset();
					}
					else if ((mapNow == 7 && digit == 4 && passwordInput != password7) || (mapNow == 9 && digit == 5 && passwordInput != password9))
					{
						CAudio::Instance()->Play(AUDIO_ERROR);
						mapArr[i][40]->Reset();
					}
				}
				if (mapNow == i + 1 && j >= 26 && j <= 29 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mapArr[i][j + 21]->Reset();
				}
				if (mapNow == i + 1 && j == 7 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					if (objNow == 8 || objNow == 11 || objNow == 13)
					{
						if (!mapArr[i][j]->IsFinalBitmap())
							mapArr[i][j]->OnMove();
						mapArr[i][54]->Reset();
					}
				}
				if (mapNow == i + 1 && j >= 1 && j <= 4 && mapObj[i][j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					mes = false;
					if (mapNow == 6 && objNow != 3 && j == 1)
					{
						if (!mapArr[i][43]->IsFinalBitmap())
							mapArr[i][43]->OnMove();
						mapArr[i][41]->Reset();
					}
					else if (mapNow == 6 && objNow != 5 && j == 4)
					{
						if (!mapArr[1][41]->IsFinalBitmap())
							mapArr[i][41]->OnMove();
						mapArr[i][43]->Reset();
					}
					else if (mapNow == 8 && objNow != 4 && j == 3)
						mapArr[i][42]->Reset();
					else
					{
						mapNow = mapChange[i][j - 1];
						mapMove = true;
						if (mapNow != 4 && mapNow != 6)
						{
							addMove[21] = true;
							CAudio::Instance()->Play(AUDIO_DOOR);
						}
						if (mapNow == 6 && j == 3)
							CAudio::Instance()->Play(AUDIO_GUN2);
						CAudio::Instance()->Play(AUDIO_DING);
						return;
					}
				}
				else if (mapNow == i + 1 && j == 5 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
				{
					Swap(mapTemp, mapNow);
					mapMove = true;
					return;
				}
				for (int k = 0; k < BAGOBJ_SIZE; k++)
				{
					mes = false;
					if (mapNow == i + 1 && mapNow == 15 && j == bagObj[k] && hideArr[j] == 1 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
					{
						Swap(mapTemp, mapNow);
						objNow = k;
						mapMove = true;
						return;
					}
					else if (mapNow == i + 1 && mapNow != 15 && j == bagObj[k] && hideArr[j] == 0 && point.x > mapArr[i][j]->Left() && point.x < mapArr[i][j]->Left() + mapArr[i][j]->Width() && point.y > mapArr[i][j]->Top() && point.y < mapArr[i][j]->Top() + mapArr[i][j]->Height())
					{
						hideArr[j] = 1;
						if (hideArr[20] == 0 && hideArr[21] == 1 && hideArr[22] == 1 && hideArr[23] == 1 && ((mapNow == 6) || (mapNow == 7) || (mapNow == 10)))
						{
							hideArr[20] = 1;
							mapArr[i][45]->Reset();
							if (!mapArr[i][40]->IsFinalBitmap())
								mapArr[i][40]->OnMove();
							if (!mapArr[i][42]->IsFinalBitmap())
								mapArr[i][42]->OnMove();
							if (!mapArr[i][43]->IsFinalBitmap())
								mapArr[i][43]->OnMove();
							if (!mapArr[i][44]->IsFinalBitmap())
								mapArr[i][44]->OnMove();
							if (!mapArr[i][52]->IsFinalBitmap())
								mapArr[i][52]->OnMove();
							for (int k = 30; k < 40; k++)
							{
								if (!mapArr[i][k]->IsFinalBitmap())
									mapArr[i][k]->OnMove();
								number[k - 30] = false;
							}
						}
						mapArr[i][j]->OnMove();	//�Y���O�̫�@�ӹϧΡA�NOnMove��̫�@�ӹϧΫᰱ��C
						return;
					}
				}
			}
		}
		if (mapNow == 4)
		{
			if (npcBefore->IsFinalBitmap())
				npcBefore->Reset();
			if (npcAfter->IsFinalBitmap())
				npcAfter->Reset();
			npcMove = true;
			/*if (objNow != 12)
				mapArr[3][53]->Reset();
			else
			{
				mapArr[3][51]->Reset();
				if (hideArr[9] == 0)
				{
					hideArr[9] = 1;
					mapArr[3][41]->Reset();
				}
			}*/
		}
		else if (mapNow == 16)
		{
			if (!mapArr[13][58]->IsFinalBitmap())
				mapArr[13][58]->OnMove();
			mapArr[13][59]->Reset();
			mapNow = 17;
		}
		else if (mapNow == 17)
		{
			if (!mapArr[13][59]->IsFinalBitmap())
				mapArr[13][59]->OnMove();
			mapArr[13][60]->Reset();
			mapNow = 18;
		}
		else if (mapNow == 18 && point.x < 560)
		{
			if (!mapArr[13][60]->IsFinalBitmap())
				mapArr[13][60]->OnMove();
			mapArr[13][61]->Reset();
			mapArr[13][62]->Reset();
			mapNow = 14;
		}
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{
		if (showPull1 && point.y > 430 && point.y <= 456)
		{
			srand((unsigned)time(NULL));
			pinballMusic = (rand() % 4);
			CAudio::Instance()->Play(15 + pinballMusic, true);
			shoot = true;
			addMove[26] = true;
		}
		else if (showPull2 && point.y > 456 && point.y <= 468)
		{
			srand((unsigned)time(NULL));
			pinballMusic = (rand() % 4);
			CAudio::Instance()->Play(15 + pinballMusic, true);
			shoot = true;
			addMove[27] = true;
		}
		else if (showPull3 && point.y > 468 && point.y <= 480)
		{
			srand((unsigned)time(NULL));
			pinballMusic = (rand() % 4);
			CAudio::Instance()->Play(15 + pinballMusic, true);
			shoot = true;
			addMove[28] = true;
		}
		clickPull = false;
		showPull1 = false;
		showPull2 = false;
		showPull3 = false;
		if (shoot)
			return;
		if ((mapNow == 1 || mapNow == 3 || mapNow == 6 || mapNow == 8 || mapNow == 9 || mapNow == 10 || mapNow == 11 || mapNow == 12 || mapNow == 13 || mapNow == 14) && point.x > 560 && point.x < 640 && point.y > 160 && point.y < 240)
		{
			mapTemp = mapNow;
			mapNow = 21;
			showPinball = true;
			return;
		}
		if ((mapNow == 1 || mapNow == 3 || mapNow == 6 || mapNow == 8 || mapNow == 9 || mapNow == 10 || mapNow == 11 || mapNow == 12 || mapNow == 13 || mapNow == 14) && point.x > 560 && point.x < 640 && point.y > 80 && point.y < 160)
		{
			mapTemp = mapNow;
			mapNow = 20;
			return;
		}
		if (mapNow == 20 && point.x > 560 && point.x < 640 && point.y > 80 && point.y < 160)
		{
			mapNow = mapTemp;
			mapTemp = 15;
			return;
		}
		if (mapNow == 20)
		{
			for (int i = 0; i < 12; i++)
			{
				if (point.x > growButtonXY[i][0] && point.x < growButtonXY[i][1] && point.y > growButtonXY[i][2] && point.y < growButtonXY[i][3] && animalBlock[i] == false && money.GetInteger() >= 50000 && animalFlag[i] < 4)
				{
					animalFlag[i]++;
					money.Add(-50000);
				}
			}
			return;
		}
		if (mapNow >= 1 && mapNow <= 14 && money.GetInteger() < 99999)
		{
			srand((unsigned)time(NULL));
			money.Add(rand() % 5000 + 1);
			if (money.GetInteger() > 99999)
				money.SetInteger(99999);
		} 
		mapMove = false;
		if (!mapArr[3][51]->IsFinalBitmap())
			mapArr[3][51]->OnMove();
		if (mapNow == 8)
		{
			if (!mapArr[7][54]->IsFinalBitmap())
				mapArr[7][54]->OnMove();
			mapArr[7][7]->Reset();
		}
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 1; j < OBJ_SIZE; j++)
			{
				if (mapNow == i + 1 && j >= 26 && j <= 29 && mapObj[i][j] == 1)
				{
					if (!mapArr[i][j + 21]->IsFinalBitmap())
						mapArr[i][j + 21]->OnMove();
				}
			}
		}
		if (mapNow == 4)
		{
			addMove[0] = false;
			add[0]->Reset();
		}
		CAudio::Instance()->Stop(AUDIO_GUN);
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{
		// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
		for (int i = 0; i < 7; i++)
		{
			rotationL[i] = false;
			rotationR[i] = false;
		}
		if (mapNow == 22)
		{
			if (point.x >= 37 && point.x < 74)
				rotationL[6] = true;
			else if (point.x >= 74 && point.x < 111)
				rotationL[5] = true;
			else if (point.x >= 111 && point.x < 148)
				rotationL[4] = true;
			else if (point.x >= 148 && point.x < 185)
				rotationL[3] = true;
			else if (point.x >= 185 && point.x < 222)
				rotationL[2] = true;
			else if (point.x >= 222 && point.x < 259)
				rotationL[1] = true;
			else if (point.x >= 259 && point.x < 296)
				rotationL[0] = true;
			else if (point.x >= 333 && point.x < 370)
				rotationR[0] = true;
			else if (point.x >= 370 && point.x < 407)
				rotationR[1] = true;
			else if (point.x >= 407 && point.x < 444)
				rotationR[2] = true;
			else if (point.x >= 444 && point.x < 481)
				rotationR[3] = true;
			else if (point.x >= 481 && point.x < 518)
				rotationR[4] = true;
			else if (point.x >= 518 && point.x < 555)
				rotationR[5] = true;
			else if (point.x >= 555 && point.x < 592)
				rotationR[6] = true;
			addMove[31] = true;
		}
		else
			addMove[31] = false;
		if (mapNow == 21 && clickPull)
		{
			if (point.y > 430 && point.y <= 456)
			{
				showPull1 = true;
				showPull2 = false;
				showPull3 = false;
			}
			else if (point.y > 456 && point.y <= 468)
			{
				showPull1 = false;
				showPull2 = true;
				showPull3 = false;
			}
			else if (point.y > 468 && point.y <= 480)
			{
				showPull1 = false;
				showPull2 = false;
				showPull3 = true;
			}
			else
			{
				showPull1 = false;
				showPull2 = false;
				showPull3 = false;
			}
		}
		if (((mapNow >= 1 && mapNow <= 14) || mapNow == 22) && experience.GetInteger() < 99999)
			experience.Add(813);
		else if (((mapNow >= 1 && mapNow <= 14) || mapNow == 22) && experience.GetInteger() == 99999 && level.GetInteger() < 99999)
		{
			level.Add(1);
			experience.Add(-99999);
		}
		if (mapNow != 7 && mapNow != 15)
			chooseMovie = false;
		for (int i = 0; i < ADD_SIZE; i++)
		{
			if (i != 21 && i != 22 && i != 23 && i != 25 && i != 26 && i != 27 && i != 28 && i != 29 && i != 30 && i != 31)
				addMove[i] = false;
		}
		if (add[21]->IsFinalBitmap())
			addMove[21] = false;
		if (point.y < 120)
			macMove = true;
		else
		{
			mac->Reset();
			macMove = false;
		}
		for (int i = 0; i < 8; i++)
		{
			if (point.y > 360 && point.x > (i * 80) && point.x < (i * 80) + 80)
			{
				for (int j = 0; j < 8; j++)
				{
					for (int k = 0; k < 15; k++)
					{
						picMove[j][k] = false;
						if (k == (7 + i - j))
							picMove[j][k] = true;
					}
				}
				break;
			}
		}
		if (point.y < 360)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 15; j++)
					picMove[i][j] = false;
			}
		}
		if (point.x > 320 && mapNow == 1)
			addMove[1] = true;
		if (mapNow == 2 || mapNow == 5)
		{
			addMove[mapNow] = true;
			if (add[mapNow]->IsFinalBitmap())
				add[mapNow]->Reset();
		}
		if (point.x < 320 && mapNow == 3)
			addMove[3] = true;
		if (mapNow == 4)
		{
			if (!add[4]->IsFinalBitmap())
				CAudio::Instance()->Play(AUDIO_GUN2);
			addMove[4] = true;
		}
		if (mapNow == 2 || mapNow == 4 || mapNow == 5)
			macMove = false;
		if (mapNow == 2 || mapNow == 4 || mapNow == 5 || mes == false)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 15; j++)
					picMove[i][j] = false;
			}
		}
		if (mapNow == 7 && point.x > 320 && !chooseMovie)
		{
			addMove[7] = true;
			addMove[16] = true;
			addMove[17] = true;
			addMove[18] = true;
			addMove[19] = true;
		}
		if (mapNow == 6 && point.x > 500 && point.x < 540 && point.y > 200 && point.y < 300)
		    addMove[20] = true;
		if (addMove[20] == false)
			CAudio::Instance()->Stop(AUDIO_CAR);
		if (add[20]->GetCurrentBitmapNumber() == 1 && addMove[20])
			CAudio::Instance()->Play(AUDIO_CAR);
		if (mapNow == 6 && point.x < 320)
		{
			if (add[6]->GetCurrentBitmapNumber() == 1)
				CAudio::Instance()->Play(AUDIO_GUN2);
			addMove[6] = true;
		}
		if (mapNow == 7 && point.x > 420 && point.x < 500 && point.y > 80 && point.y < 240 && !chooseMovie)
			addMove[24] = true;
	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{
	
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{
		
	}

	void CGameStateRun::OnShow()
	{
		//
		//  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
		//        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
		//        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
		//
		Background.ShowBitmap();
		for (int i = MAP_SIZE - 1; i >= 0; i--)
		{
			for (int j = 0; j < OBJ_SIZE; j++)
			{
				mapArr[i][j]->SetTopLeft(mapX[i][j], mapY[i][j]);
				mapArr[i][j]->OnShow();
			}
		}
		npcBefore->SetTopLeft(0, 0);
		npcBefore->OnShow();
		npcAfter->SetTopLeft(0, 0);
		npcAfter->OnShow();
		mac->SetTopLeft(80, 440);
		mac->OnShow();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				pic[i][j]->SetTopLeft((80 * i), 0);
				pic[i][j]->OnShow();
			}
		}
		if (mapNow == 1 || mapNow == 3 || mapNow == 6 || mapNow == 8 || mapNow == 9 || mapNow == 10 || mapNow == 11 || mapNow == 12 || mapNow == 13 || mapNow == 14 || mapNow == 20)
		{
			cama.ShowBitmap();
			gamble.ShowBitmap();
		}
		if (showPinball)
		    pinball.ShowBitmap();
		if (showPull1 || showPull2 || showPull3 || !showPinball)
			addMove[25] = false;
		else
			addMove[25] = true;
		if (mapNow == 22 && back)
		{
			addMove[29] = true;
			background.ShowBitmap();
		}
		else if (mapNow == 22)
		{
			background2.ShowBitmap();
			addMove[29] = false;
		}
		if (mapNow == 1 || mapNow == 3 || mapNow == 6 || mapNow == 8 || mapNow == 9 || mapNow == 10 || mapNow == 11 || mapNow == 12 || mapNow == 13 || mapNow == 14 || mapNow == 22)
			pubg.ShowBitmap();
		for (int i = 0; i < ADD_SIZE; i++)
		{
			add[i]->SetTopLeft(addX[i], addY[i]);
			add[i]->OnShow();
			if (addMove[26] || addMove[27] || addMove[28])
			{
				srand((unsigned)time(NULL));
				if ((rand() % 50 + 1) % 7 == 0)
					experience.Add(rand() % 50 + 1);
				if (experience.GetInteger() > 99999)
					experience.SetInteger(99999);
			}
			if (mapNow == 22 && money.GetInteger() < 99999 && back)
			{
				money.Add(1);
				if (money.GetInteger() > 99999)
					money.SetInteger(99999);
			}
		}
		for (int i = 0; i < 7; i++)
		{
			if (rotationL[i])
			{
				rotationLeft[i].ShowBitmap();
				break;
			}
			if (rotationR[i])
			{
				rotationRight[i].ShowBitmap();
				break;
			}
		}
		if (showPull1)
			pull1.ShowBitmap();
		if (showPull2)
			pull2.ShowBitmap();
		if (showPull3)
			pull3.ShowBitmap();
		if ((mapNow >= 1 && mapNow <= 14) || mapNow == 20 || mapNow == 21 || mapNow == 22)
		{
			level.ShowBitmapL();
			experience.ShowBitmapE();
			money.ShowBitmap();
			levelExpMoney.ShowBitmap();
		}
		for (int i = 0; i < 12; i++)
		{
			if (level.GetInteger() == animalLevel[i] && animalBlock[i])
			{
				animalBlock[i] = false;
				animalFlag[i]++;
			}
		}
		if (mapNow == 20)
		{
			for (int i = 0; i < 12; i++)
			{
				if (animalFlag[i] > 0)
				{
					animal[i][animalFlag[i] - 1].ShowBitmap();
					growButton[i].ShowBitmap();
				}
				else
					gameCard[i].ShowBitmap();
			}
		}
		if (endFlag)
			end.ShowBitmap();
	}
}