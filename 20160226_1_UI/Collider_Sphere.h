#pragma once
#include "BoundingVolume.h"

class Collider_Sphere
{
public:
	Collider_Sphere();
	~Collider_Sphere();

	void Initialize(D3DXVECTOR3& center, float radius, D3DXMATRIXA16* _parent = nullptr);
	void Destroy();
	void Update();
	void Render();

	inline void SetWireRender(bool wire){ wireMode = wire; }
	inline void SetDoRender(bool render){ doRender = render; }
	inline void SetIsSelected(bool selected) { isSelected = selected; }

	inline BoundingSphere& GetBoundingSphere(){ return boundingSphere; }
	inline bool GetIsSelected() { return isSelected; }

	inline void SetMaterialColor(D3DXCOLOR& color){ material.Ambient = color; material.Diffuse = color; }

protected:
	BoundingSphere boundingSphere = BoundingSphere(D3DXVECTOR3(0, 0, 0), 1.0f);
	LPD3DXMESH sphereMesh = nullptr;

	D3DXMATRIXA16 world;
	D3DXMATRIXA16* parent = nullptr;

	bool wireMode = false;
	bool doRender = true;
	bool isSelected = false;

	D3DMATERIAL9 material;
};

