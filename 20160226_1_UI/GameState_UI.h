#pragma once
#include <list>
#include "GameState.h"
#include "Grid.h"
#include "Collider_Sphere.h"
#include "Collider_Box.h"
#include "Character_Collision.h"
#include "UI_Text.h"
#include "UI_Image.h"

class GameState_UI :
	public GameState
{
public:
	enum ViewType
	{
		FPS,
		TOP
	};

	GameState_UI();
	virtual ~GameState_UI();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual void OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	void setViewType(GameState_UI::ViewType type) { viewType = type; }

protected:
	Grid* grid = nullptr;
	Character_Collision* girl = nullptr;

	ViewType viewType = GameState_UI::TOP;
	bool isCameraSet = false;

	std::list<Collider_Box*> boxList;
	std::list<Collider_Sphere*> sphereList;
};

