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
	
	Collider_Box* box = nullptr;
	box = new Collider_Box;
	box->Initialize(D3DXVECTOR3(-1.0f, 0.0f, -1.0f), D3DXVECTOR3(1.0f, 2.0f, 1.0f));
	box->SetPosition(D3DXVECTOR3(5, 0, 5));
	box->Update();
	boxList.push_back(box);

	box = new Collider_Box;
	box->Initialize(D3DXVECTOR3(-1.0f, 0.0f, -1.0f), D3DXVECTOR3(1.0f, 2.0f, 1.0f));
	box->SetPosition(D3DXVECTOR3(-5, 0, 5));
	box->Update();
	boxList.push_back(box);

	Collider_Sphere* sphere = nullptr;
	sphere = new Collider_Sphere;
	sphere->Initialize(D3DXVECTOR3(3, 1, -3), 1.0f);
	sphere->Update();
	sphereList.push_back(sphere);

	sphere = new Collider_Sphere;
	sphere->Initialize(D3DXVECTOR3(-3, 1, -3), 1.0f);
	sphere->Update();
	sphereList.push_back(sphere);

	D3DXVECTOR3 pos;
	D3DXVECTOR2 size;

	UI_Image* uiImageMain = new  UI_Image;
	uiImageMain->SetTexture("./UI/menu.png");
	size = uiImageMain->GetSize();
	pos = D3DXVECTOR3(RESOLUTION_X / 2 - size.x / 2, RESOLUTION_Y - size.y, 0);
	uiImageMain->SetPosition(pos.x, pos.y, 0);
	UI_Manager::Get().SetRoot(uiImageMain);

	UI_Image* uiImagePanelOption = new  UI_Image;
	uiImagePanelOption->SetTexture("./UI/panel.png");
	uiImagePanelOption->SetPosition(-pos.x, -500, 0);
	uiImageMain->AddChild(uiImagePanelOption);

	UI_Image* uiImageOptionBox = new  UI_Image;
	uiImageOptionBox->SetTexture("./UI/box.png");
	uiImageOptionBox->SetPosition(80, 120, 0);
	uiImagePanelOption->AddChild(uiImageOptionBox);

	UI_Image* uiImageOptionSphere = new  UI_Image;
	uiImageOptionSphere->SetTexture("./UI/sphere.png");
	uiImageOptionSphere->SetPosition(83, 130, 0);
	uiImageOptionSphere->SetShow(false);
	uiImagePanelOption->AddChild(uiImageOptionSphere);

	UI_Text* uiTextOptionHeading = new UI_Text;
	uiTextOptionHeading->SetFont(Font::GetFont(Font::HEADING));
	uiTextOptionHeading->SetText("Choose Object");
	uiTextOptionHeading->SetPosition(10, 30, 0);
	size = uiImagePanelOption->GetSize();
	uiTextOptionHeading->SetSize(size.x, 50);
	uiTextOptionHeading->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	uiTextOptionHeading->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImagePanelOption->AddChild(uiTextOptionHeading);

	UI_Button* uiButtonOptionBox1 = new UI_Button;
	uiButtonOptionBox1->SetTexture("./UI/btn-box-up.png", "./UI/btn-box-over.png", "./UI/btn-box-down.png");
	uiButtonOptionBox1->SetPosition(240, 85, 0);
	uiButtonOptionBox1->OnClick = std::bind(
		&UI_Functions::ClickOptionButton,
		std::ref(UI_Manager::Get().func),
		uiImageOptionBox, boxList,
		uiImageOptionSphere, sphereList,
		BoundingVolumeType::BOUNDING_AABB, 0);
	uiImagePanelOption->AddChild(uiButtonOptionBox1);

	UI_Text* uiTextOptionBox1 = new UI_Text;
	uiTextOptionBox1->SetFont(Font::GetFont(Font::BUTTON));
	uiTextOptionBox1->SetText("Box No. 1");
	uiTextOptionBox1->SetPosition(10, 0, 0);
	size = uiButtonOptionBox1->GetSize();
	uiTextOptionBox1->SetSize(size.x, size.y);
	uiTextOptionBox1->SetTextColor(D3DCOLOR_XRGB(255, 0, 0));
	uiTextOptionBox1->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiButtonOptionBox1->AddChild(uiTextOptionBox1);

	UI_Button* uiButtonOptionBox2 = new UI_Button;
	uiButtonOptionBox2->SetTexture("./UI/btn-box-up.png", "./UI/btn-box-over.png", "./UI/btn-box-down.png");
	uiButtonOptionBox2->SetPosition(240, 135, 0);
	uiButtonOptionBox2->OnClick = std::bind(
		&UI_Functions::ClickOptionButton,
		std::ref(UI_Manager::Get().func),
		uiImageOptionBox, boxList,
		uiImageOptionSphere, sphereList,
		BoundingVolumeType::BOUNDING_AABB, 1);
	uiImagePanelOption->AddChild(uiButtonOptionBox2);

	UI_Text* uiTextOptionBox2 = new UI_Text;
	uiTextOptionBox2->SetFont(Font::GetFont(Font::BUTTON));
	uiTextOptionBox2->SetText("Box No. 2");
	uiTextOptionBox2->SetPosition(10, 0, 0);
	size = uiButtonOptionBox2->GetSize();
	uiTextOptionBox2->SetSize(size.x, size.y);
	uiTextOptionBox2->SetTextColor(D3DCOLOR_XRGB(255, 0, 0));
	uiTextOptionBox2->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiButtonOptionBox2->AddChild(uiTextOptionBox2);

	UI_Button* uiButtonOptionSphere1 = new UI_Button;
	uiButtonOptionSphere1->SetTexture("./UI/btn-sphere-up.png", "./UI/btn-sphere-over.png", "./UI/btn-sphere-down.png");
	uiButtonOptionSphere1->SetPosition(240, 185, 0);
	uiButtonOptionSphere1->OnClick = std::bind(
		&UI_Functions::ClickOptionButton,
		std::ref(UI_Manager::Get().func),
		uiImageOptionBox, boxList,
		uiImageOptionSphere, sphereList,
		BoundingVolumeType::BOUNDING_SPHERE, 0);
	uiImagePanelOption->AddChild(uiButtonOptionSphere1);

	UI_Text* uiTextOptionSphere1 = new UI_Text;
	uiTextOptionSphere1->SetFont(Font::GetFont(Font::BUTTON));
	uiTextOptionSphere1->SetText("Sphere No. 1");
	uiTextOptionSphere1->SetPosition(10, 0, 0);
	size = uiButtonOptionSphere1->GetSize();
	uiTextOptionSphere1->SetSize(size.x, size.y);
	uiTextOptionSphere1->SetTextColor(D3DCOLOR_XRGB(255, 0, 0));
	uiTextOptionSphere1->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiButtonOptionSphere1->AddChild(uiTextOptionSphere1);

	UI_Button* uiButtonOptionSphere2 = new UI_Button;
	uiButtonOptionSphere2->SetTexture("./UI/btn-sphere-up.png", "./UI/btn-sphere-over.png", "./UI/btn-sphere-down.png");
	uiButtonOptionSphere2->SetPosition(240, 235, 0);
	uiButtonOptionSphere2->OnClick = std::bind(
		&UI_Functions::ClickOptionButton,
		std::ref(UI_Manager::Get().func),
		uiImageOptionBox, boxList,
		uiImageOptionSphere, sphereList,
		BoundingVolumeType::BOUNDING_SPHERE, 1);
	uiImagePanelOption->AddChild(uiButtonOptionSphere2);

	UI_Text* uiTextOptionSphere2 = new UI_Text;
	uiTextOptionSphere2->SetFont(Font::GetFont(Font::BUTTON));
	uiTextOptionSphere2->SetText("Sphere No. 2");
	uiTextOptionSphere2->SetPosition(10, 0, 0);
	size = uiButtonOptionSphere2->GetSize();
	uiTextOptionSphere2->SetSize(size.x, size.y);
	uiTextOptionSphere2->SetTextColor(D3DCOLOR_XRGB(255, 0, 0));
	uiTextOptionSphere2->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiButtonOptionSphere2->AddChild(uiTextOptionSphere2);

	UI_Button* uiButtonCloseOption = new UI_Button;
	uiButtonCloseOption->SetTexture("./UI/btnR-close-up.png", "./UI/btnR-close-over.png", "./UI/btnR-close-down.png");
	size = uiImagePanelOption->GetSize();
	uiButtonCloseOption->SetPosition(size.x, 10, 0);
	uiButtonCloseOption->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiImagePanelOption);
	uiImagePanelOption->AddChild(uiButtonCloseOption);

	UI_Image* uiImagePanelFPS = new  UI_Image;
	uiImagePanelFPS->SetTexture("./UI/panel-fps.png");
	size = uiImageMain->GetSize();
	pos = uiImageMain->GetPosition();
	uiImagePanelFPS->SetPosition(size.x - 25, -pos.y, 0);
	uiImageMain->AddChild(uiImagePanelFPS);

	UI_Image* uiImagePanelQuest = new  UI_Image;
	uiImagePanelQuest->SetTexture("./UI/panel.png");
	size = uiImageMain->GetSize();
	pos = uiImageMain->GetPosition();
	uiImagePanelQuest->SetPosition(size.x - 300, -300, 0);
	uiImageMain->AddChild(uiImagePanelQuest);

	UI_Text* uiTextQuestHeading = new UI_Text;
	uiTextQuestHeading->SetFont(Font::GetFont(Font::HEADING));
	uiTextQuestHeading->SetText("The Quest");
	uiTextQuestHeading->SetPosition(10, 30, 0);
	size = uiImagePanelQuest->GetSize();
	uiTextQuestHeading->SetSize(size.x, 50);
	uiTextQuestHeading->SetTextColor(D3DCOLOR_XRGB(255, 0, 0));
	uiTextQuestHeading->SetTextFormat(DT_CENTER | DT_VCENTER);
	uiImagePanelQuest->AddChild(uiTextQuestHeading);

	UI_Image* uiImageQuestGirl = new  UI_Image;
	uiImageQuestGirl->SetTexture("./UI/girl.png");
	uiImageQuestGirl->SetPosition(50, 50, 0);
	uiImagePanelQuest->AddChild(uiImageQuestGirl);

	UI_Text* uiTextQuestBody = new UI_Text;
	uiTextQuestBody->SetFont(Font::GetFont(Font::BODY));
	uiTextQuestBody->SetText("Lorem ipsum dolor sit amet,\nconsectetur adipiscing elit.\nUt venenatis cursus nibh.\nInteger mi lacus, tempor non\ndictum eget, interdum ut\nmagna. Morbi id lectus arcu,\nac sagittis nisi.");
	uiTextQuestBody->SetPosition(190, 90, 0);
	size = uiImagePanelQuest->GetSize();
	uiTextQuestBody->SetSize(size.x, 200);
	uiTextQuestBody->SetTextColor(D3DCOLOR_XRGB(100, 100, 100));
	uiTextQuestBody->SetTextFormat(DT_LEFT);
	uiImagePanelQuest->AddChild(uiTextQuestBody);

	UI_Button* uiButtonAcceptQuest = new UI_Button;
	uiButtonAcceptQuest->SetTexture("./UI/btn-accept-up.png", "./UI/btn-accept-over.png", "./UI/btn-accept-down.png");
	size = uiImagePanelQuest->GetSize();
	uiButtonAcceptQuest->SetPosition(size.x - 130, size.y - 57, 0);
	uiButtonAcceptQuest->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiImagePanelQuest);
	uiImagePanelQuest->AddChild(uiButtonAcceptQuest);

	UI_Button* uiButtonCloseQuest = new UI_Button;
	uiButtonCloseQuest->SetTexture("./UI/btnL-close-up.png", "./UI/btnL-close-over.png", "./UI/btnL-close-down.png");
	size = uiButtonCloseQuest->GetSize();
	uiButtonCloseQuest->SetPosition(-size.x, 10, 0);
	uiButtonCloseQuest->OnClick = std::bind(
		&UI_Functions::CloseTarget,
		std::ref(UI_Manager::Get().func)
		, uiImagePanelQuest);
	uiImagePanelQuest->AddChild(uiButtonCloseQuest);

	UI_Button* uiButtonMain1 = new UI_Button;
	uiButtonMain1->SetTexture("./UI/btn-option-up.png", "./UI/btn-option-over.png", "./UI/btn-option-down.png");
	uiButtonMain1->SetPosition(110, 79, 0);
	/*uiButton->OnClick = std::bind(
	&UI_Functions::ClickTest,
	std::ref(UI_Manager::Get().func)
	);*/
	uiButtonMain1->OnClick = std::bind(
		&UI_Functions::OpenTarget,
		std::ref(UI_Manager::Get().func)
		, uiImagePanelOption);
	uiImageMain->AddChild(uiButtonMain1);

	UI_Button* uiButtonMain2 = new UI_Button;
	uiButtonMain2->SetTexture("./UI/btn-quest-up.png", "./UI/btn-quest-over.png", "./UI/btn-quest-down.png");
	uiButtonMain2->SetPosition(155, 79, 0);
	/*uiButton->OnClick = std::bind(
	&UI_Functions::ClickTest,
	std::ref(UI_Manager::Get().func)
	);*/
	uiButtonMain2->OnClick = std::bind(
	&UI_Functions::OpenTarget,
	std::ref(UI_Manager::Get().func)
	, uiImagePanelQuest);
	uiImageMain->AddChild(uiButtonMain2);

	Reset();
}

void GameState_UI::Destroy()
{
	for (auto iter = boxList.begin(); iter != boxList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	boxList.clear();

	for (auto iter = sphereList.begin(); iter != sphereList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	sphereList.clear();

	SAFE_DELETE(girl);
	SAFE_DELETE(grid);	
}

void GameState_UI::Reset()
{
}

void GameState_UI::Update()
{
	float tick = (float)GameManager::GetTick();

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

	bool isCollisioin = false;
	for (auto iter = boxList.cbegin(); iter != boxList.cend(); ++iter)
	{
		if ((*iter)->GetIsSelected())
		{
			if ((GetAsyncKeyState('I') & 0x8000) != 0)
			{
				(*iter)->setInstancePosition(-(directionFB * moveSpeed * tick));
			}

			else if ((GetAsyncKeyState('K') & 0x8000) != 0)
			{
				(*iter)->setInstancePosition(directionFB * moveSpeed * tick);
			}

			else if ((GetAsyncKeyState('L') & 0x8000) != 0)
			{
				(*iter)->setInstancePosition(-(directionLR * moveSpeed * tick));
			}

			else if ((GetAsyncKeyState('J') & 0x8000) != 0)
			{
				(*iter)->setInstancePosition(directionLR * moveSpeed * tick);
			}
		}

		if (girl->GetBoundingVolumeType() == BoundingVolumeType::BOUNDING_SPHERE)
		{
			isCollisioin = Collision::IsBoxToSphere((*iter)->GetBoundingBox(), girl->GetBoundingSphere());
		}
		else if (girl->GetBoundingVolumeType() == BoundingVolumeType::BOUNDING_AABB)
		{
			isCollisioin = Collision::IsBoxToBox(girl->GetBoundingBox(), (*iter)->GetBoundingBox());
		}
		if (isCollisioin == true)
		{
			girl->SetCollision(true);
			(*iter)->SetMaterialColor(D3DXCOLOR(0.8f, 0.f, 0.f, 1.0f));
			break;
		}
		else
		{
			girl->SetCollision(false);
			
			if (!((*iter)->GetIsSelected()))
			{
				(*iter)->SetMaterialColor(D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f));
			}
		}

		(*iter)->Update();
	}

	if (isCollisioin == false)
	{
		for (auto iter = sphereList.cbegin(); iter != sphereList.cend(); ++iter)
		{
			if (girl->GetBoundingVolumeType() == BoundingVolumeType::BOUNDING_SPHERE)
			{
				isCollisioin = Collision::IsSphereToSphere(girl->GetBoundingSphere(), (*iter)->GetBoundingSphere());

			}
			else if (girl->GetBoundingVolumeType() == BoundingVolumeType::BOUNDING_AABB)
			{
				isCollisioin = Collision::IsBoxToSphere(girl->GetBoundingBox(), (*iter)->GetBoundingSphere());
			}
			if (isCollisioin == true)
			{
				(*iter)->SetMaterialColor(D3DXCOLOR(0.8f, 0.f, 0.f, 1.0f));
				break;
			}
			else
			{
				if (!((*iter)->GetIsSelected()))
				{
					(*iter)->SetMaterialColor(D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f));
				}
			}

			(*iter)->Update();
		}
	}

	girl->SetCollision(isCollisioin);
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

	for (auto iter = boxList.cbegin(); iter != boxList.cend(); ++iter)
	{
		(*iter)->Render();
	}

	for (auto iter = sphereList.cbegin(); iter != sphereList.cend(); ++iter)
	{
		(*iter)->Render();
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
