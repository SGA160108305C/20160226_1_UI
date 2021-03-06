#pragma once
#include "GameObject.h"
#include "AseFrame.h"
#include "ActionMove.h"

class Character :
	public GameObject
{
public:
	Character();
	virtual ~Character();

	virtual void Initialize();
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	inline D3DXMATRIXA16* GetWorld(){ return &world; }

protected:
	D3DXMATRIXA16 world;
	AseFrame* aseRootFrame = nullptr;

	bool textureOn = false;

	const float BASE_ANGLE = D3DX_PI;

	float moveSpeed = 5.0f;
	float rotationSpeed = 2.0f;

	bool keyWasPressed = false;	//스페이스만 체크

};

