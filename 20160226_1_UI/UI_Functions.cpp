#include "stdafx.h"
#include "UI_Functions.h"
#include "Collider_Box.h"
#include "Collider_Sphere.h"


UI_Functions::UI_Functions()
{
}


UI_Functions::~UI_Functions()
{
}

void UI_Functions::ClickTest()
{
	UI_Manager::Get().GetRoot()->SetShow(false);
}

void UI_Functions::CloseTarget(UI_Base* target)
{
	if (target)
	{
		target->SetShow(false);
	}
}

void UI_Functions::OpenTarget(UI_Base* target)
{
	if (target)
	{
		target->SetShow(true);
	}
}

void UI_Functions::ClickOptionButton(
	UI_Base* box, std::vector<Collider_Box*> &boxList,
	UI_Base* sphere, std::vector<Collider_Sphere*> &sphereList,
	BoundingVolumeType type, int idx
	)
{
	switch (type)
	{
	case BOUNDING_SPHERE:
		box->SetShow(false);
		sphere->SetShow(true);

		break;
	case BOUNDING_AABB:
		sphere->SetShow(false);
		box->SetShow(true);

		sphereList[idx]->SetMaterialColor(D3DXCOLOR(0.f, 0.8f, 0.f, 1.0f));

		break;
	default:
		break;
	}
}