#include "stdafx.h"
#include "Character_Collision.h"

Character_Collision::Character_Collision()
{
}


Character_Collision::~Character_Collision()
{
}

void Character_Collision::Initialize()
{
	Character::Initialize();

	colliderSphere = new Collider_Sphere;
	colliderSphere->Initialize(D3DXVECTOR3(0, 0.5f, 0), 0.75f, &world);
	colliderSphere->SetWireRender(true);
	colliderSphere->SetDoRender(false);

	colliderBox = new Collider_Box;
	colliderBox->Initialize(D3DXVECTOR3(-0.5f, 0.0f, -0.5f), D3DXVECTOR3(0.5f, 1.25f, 0.5f));
	colliderBox->SetWireRender(true);
	colliderSphere->SetDoRender(false);

}

void Character_Collision::Destroy()
{
	SAFE_DELETE(colliderSphere);
	SAFE_DELETE(colliderBox);

	Character::Destroy();
}

void Character_Collision::Update()
{
	float tick = (float)GameManager::GetTick();

	D3DXMatrixIdentity(&world);
	D3DXMATRIXA16 rotation;
	D3DXMatrixRotationY(&rotation, rotationAngle + BASE_ANGLE);
	world *= rotation;

	D3DXVECTOR3 baseDirection(0, 0, 1);
	D3DXVec3TransformCoord(&direction, &baseDirection, &world);

	//이동 처리
	if ((GetAsyncKeyState('A') & 0x8000) != 0)
	{
		lockPositionW = false;
		lockPositionS = false;
		rotationAngle -= (rotationSpeed * tick);
	}
	else if ((GetAsyncKeyState('D') & 0x8000) != 0)
	{
		lockPositionW = false;
		lockPositionS = false;
		rotationAngle += (rotationSpeed * tick);
	}
	if ((GetAsyncKeyState('W') & 0x8000) != 0)
	{
		if (!lockPositionW)
		{
			if (collision)
			{
				lockPositionW = true;
				position = position + (direction * moveSpeed * 0.1f);
			}

			else
			{
				lockPositionS = false;
				position -= (direction * moveSpeed * tick);
			}
		}
	}
	else if ((GetAsyncKeyState('S') & 0x8000) != 0)
	{
		if (!lockPositionS)
		{
			if (collision)
			{
				lockPositionS = true;
				position = position - (direction * moveSpeed * 0.1f);
			}

			else
			{
				lockPositionW = false;
				position += (direction * moveSpeed * tick);
			}
		}
	}

	if ((GetAsyncKeyState(VK_SPACE) & 0x8000) != 0)
	{
		if (keyWasPressed == false)
		{
			if (volumeType == BoundingVolumeType::BOUNDING_SPHERE)
			{
				volumeType = BoundingVolumeType::BOUNDING_AABB;
			}
			else if (volumeType == BoundingVolumeType::BOUNDING_AABB)
			{
				volumeType = BoundingVolumeType::BOUNDING_SPHERE;
			}

		}
		keyWasPressed = true;
	}
	else
	{
		keyWasPressed = false;
	}

	if ((GetAsyncKeyState('3') & 0x8000) != 0)
	{
		colliderSphere->SetDoRender(true);
	}

	else if ((GetAsyncKeyState('4') & 0x8000) != 0)
	{
		colliderSphere->SetDoRender(false);
	}

	D3DXMATRIXA16 translation;
	D3DXMatrixTranslation(&translation, position.x, position.y, position.z);
	world *= translation;

	//바운딩 볼륨 월드 구하기
	if (colliderSphere)
	{
		currentBoundingSphere.center = colliderSphere->GetBoundingSphere().center + position;
		currentBoundingSphere.radius = colliderSphere->GetBoundingSphere().radius;
		colliderSphere->Update();
	}
	if (colliderBox)
	{
		currentBoundingBox.min = colliderBox->GetBoundingBox().min;
		currentBoundingBox.max = colliderBox->GetBoundingBox().max;
		colliderBox->SetParent(&translation);
		colliderBox->Update();
	}

	if (aseRootFrame)
	{
		int keyFrame = GetTickCount() % (3200 - 640) + 640;
		aseRootFrame->Update(keyFrame, &world);
	}
	GameObject::Update();

}

void Character_Collision::Render()
{
	Character::Render();

	if (collision)
	{
		colliderSphere->SetMaterialColor(D3DXCOLOR(0.f, 0.f, 0.8f, 1.0f));
		colliderBox->SetMaterialColor(D3DXCOLOR(0.f, 0.f, 0.8f, 1.0f));
	}
	else
	{
		colliderSphere->SetMaterialColor(D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f));
		colliderBox->SetMaterialColor(D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f));
	}

	switch (volumeType)
	{
	case BOUNDING_SPHERE:
	{
		if (colliderSphere)
		{
			colliderSphere->Render();
		}
	}
	break;
	case BOUNDING_AABB:
	{
		if (colliderBox)
		{
			colliderBox->Render();
		}
	}
	break;
	default:
		break;
	}

}