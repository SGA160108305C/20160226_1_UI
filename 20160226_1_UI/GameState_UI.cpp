#include "stdafx.h"
#include "GameState_UI.h"
#include "ActionMove.h"
#include "Collision.h"


GameState_UI::GameState_UI()
{
}


GameState_UI::~GameState_UI()
{
}

void GameState_UI::Initialize()
{
	if ( grid == nullptr )
	{
		grid = new Grid;
		grid->Initialize();
	}	
	if ( girl == nullptr )
	{
		girl = new Character_Collision;
		girl->Initialize();			
	}
	
	if (sphere == nullptr)
	{
		sphere = new Collider_Sphere;
		sphere->Initialize(D3DXVECTOR3(10, 0, 0), 3.0f);
		sphere->SetMaterialColor(D3DXCOLOR(0, 1, 0, 1));
	}

	if (box == nullptr)
	{
		box = new Collider_Box;
		box->Initialize(D3DXVECTOR3(-10, 0, 0), D3DXVECTOR3(-9, 1, 1));
		box->SetMaterialColor(D3DXCOLOR(0, 0, 1, 1));
	}

	D3DXVECTOR3 pos;
	D3DXVECTOR2 size;

	UI_Image* uiImage = new  UI_Image;
	uiImage->SetTexture("./UI/menu.png");
	size = uiImage->GetSize();
	pos = D3DXVECTOR3(RESOLUTION_X / 2 - size.x / 2, RESOLUTION_Y - size.y, 0);
	uiImage->SetPosition(pos.x, pos.y, 0);
	UI_Manager::Get().SetRoot(uiImage);

	UI_Text* uiTextHeading = new UI_Text;
	uiTextHeading->SetFont(Font::GetFont(Font::HEADING));
	uiTextHeading->SetText("Choose Object");
	pos = UI_Manager::Get().GetRoot()->GetPosition();
	uiTextHeading->SetPosition(pos.x, pos.y + 80, pos.z);
	size = UI_Manager::Get().GetRoot()->GetSize();
	uiTextHeading->SetSize(size.x, 100);
	uiTextHeading->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	uiTextHeading->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImage->AddChild(uiTextHeading);

	UI_Button* uiButton1 = new UI_Button;
	uiButton1->SetTexture("./UI/btn-med-up.png", "./UI/btn-med-over.png", "./UI/btn-med-down.png");
	pos = UI_Manager::Get().GetRoot()->GetPosition();
	uiButton1->SetPosition(pos.x + 130, pos.y + 200, pos.z);
	/*uiButton->OnClick = std::bind(
		&UI_Functions::ClickTest,
		std::ref(UI_Manager::Get().func)
		);*/
	uiButton1->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiTextHeading);
	uiImage->AddChild(uiButton1);

	UI_Button* uiButton2 = new UI_Button;
	uiButton2->SetTexture("./UI/btn-med-up.png", "./UI/btn-med-over.png", "./UI/btn-med-down.png");
	pos = UI_Manager::Get().GetRoot()->GetPosition();
	uiButton2->SetPosition(pos.x + 130, pos.y + 260, pos.z);
	/*uiButton->OnClick = std::bind(
	&UI_Functions::ClickTest,
	std::ref(UI_Manager::Get().func)
	);*/
	uiButton2->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiTextHeading);
	uiImage->AddChild(uiButton2);

	UI_Button* uiButton3 = new UI_Button;
	uiButton3->SetTexture("./UI/btn-med-up.png", "./UI/btn-med-over.png", "./UI/btn-med-down.png");
	pos = UI_Manager::Get().GetRoot()->GetPosition();
	uiButton3->SetPosition(pos.x + 130, pos.y + 320, pos.z);
	/*uiButton->OnClick = std::bind(
	&UI_Functions::ClickTest,
	std::ref(UI_Manager::Get().func)
	);*/
	uiButton3->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiTextHeading);
	uiImage->AddChild(uiButton3);

	UI_Button* uiButton4 = new UI_Button;
	uiButton4->SetTexture("./UI/btn-med-up.png", "./UI/btn-med-over.png", "./UI/btn-med-down.png");
	pos = UI_Manager::Get().GetRoot()->GetPosition();
	uiButton4->SetPosition(pos.x + 130, pos.y + 380, pos.z);
	/*uiButton->OnClick = std::bind(
	&UI_Functions::ClickTest,
	std::ref(UI_Manager::Get().func)
	);*/
	uiButton4->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiTextHeading);
	uiImage->AddChild(uiButton4);
		
	UI_Text* uiTextButton1 = new UI_Text;
	uiTextButton1->SetFont(Font::GetFont(Font::BUTTON));
	uiTextButton1->SetText("Sphere 1");
	pos = uiButton1->GetPosition();
	uiTextButton1->SetPosition(pos.x, pos.y, pos.z);
	size = uiButton1->GetSize();
	uiTextButton1->SetSize(size.x, size.y);
	uiTextButton1->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	uiTextButton1->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImage->AddChild(uiTextButton1);

	UI_Text* uiTextButton2 = new UI_Text;
	uiTextButton2->SetFont(Font::GetFont(Font::BUTTON));
	uiTextButton2->SetText("Sphere 2");
	pos = uiButton2->GetPosition();
	uiTextButton2->SetPosition(pos.x, pos.y, pos.z);
	size = uiButton2->GetSize();
	uiTextButton2->SetSize(size.x, size.y);
	uiTextButton2->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	uiTextButton2->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImage->AddChild(uiTextButton2);

	UI_Text* uiTextButton3 = new UI_Text;
	uiTextButton3->SetFont(Font::GetFont(Font::BUTTON));
	uiTextButton3->SetText("Box 1");
	pos = uiButton3->GetPosition();
	uiTextButton3->SetPosition(pos.x, pos.y, pos.z);
	size = uiButton3->GetSize();
	uiTextButton3->SetSize(size.x, size.y);
	uiTextButton3->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	uiTextButton3->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImage->AddChild(uiTextButton3);

	UI_Text* uiTextButton4 = new UI_Text;
	uiTextButton4->SetFont(Font::GetFont(Font::BUTTON));
	uiTextButton4->SetText("Box 2");
	pos = uiButton4->GetPosition();
	uiTextButton4->SetPosition(pos.x, pos.y, pos.z);
	size = uiButton4->GetSize();
	uiTextButton4->SetSize(size.x, size.y);
	uiTextButton4->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	uiTextButton4->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImage->AddChild(uiTextButton4);

	Reset();
}

void GameState_UI::Destroy()
{
	SAFE_DELETE(box);
	SAFE_DELETE(sphere);
	SAFE_DELETE(girl);
	SAFE_DELETE(grid);	
}

void GameState_UI::Reset()
{
}

void GameState_UI::Update()
{
	if ((GetAsyncKeyState('1') & 0x8000) != 0)
	{
		setViewType(GameState_UI::TOP);
		isCameraSet = false;
	}
	else if ((GetAsyncKeyState('2') & 0x8000) != 0)
	{
		setViewType(GameState_UI::FPS);
		isCameraSet = false;
	}

	if (viewType == GameState_UI::FPS)
	{
		if (isCameraSet == false)
		{
			GameManager::GetCamera()->SetDistance(3.0f);
			GameManager::GetCamera()->setCamRotY(girl->getRotationAngleAddress());
		}

		isCameraSet = true;
	}

	else
	{
		if (isCameraSet == false)
		{
			GameManager::GetCamera()->setCamRotY(nullptr);
			GameManager::GetCamera()->SetDistance(20.0f);
		}
		
		isCameraSet = true;
	}

	if ( girl )
	{
		girl->Update();
	}

	if (sphere)
	{
		sphere->Update();
	}

	if (box)
	{
		box->Update();
	}
}

void GameState_UI::Render()
{
	if ( grid )
	{
		grid->Render();
	}

	if ( girl )
	{
		girl->Render();
	}

	if (sphere)
	{
		sphere->Render();
	}

	if (box)
	{
		box->Render();
	}
}

void GameState_UI::OnEnterState()
{
	GameManager::GetCamera()->SetDistance(20.0f);
	Initialize();

	GameManager::GetCamera()->SetLookTarget(girl->GetPositionAdress());
}

void GameState_UI::OnLeaveState()
{
	Destroy();
}

LRESULT GameState_UI::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	if (girl)
	{
		girl->InputProc(hWnd, message, wParam, lParam);
	}
	return result;
}
