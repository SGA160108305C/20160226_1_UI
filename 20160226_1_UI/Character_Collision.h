#pragma once
#include "Character.h"
#include "Collider_Sphere.h"
#include "Collider_Box.h"

class Character_Collision :
	public Character
{
public:
	Character_Collision();
	virtual ~Character_Collision();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;

	inline void SetCollision(bool col){ collision = col; }

	inline BoundingVolumeType GetBoundingVolumeType(){ return volumeType; }
	inline BoundingSphere& GetBoundingSphere(){ return currentBoundingSphere; }
	inline BoundingBox& GetBoundingBox(){ return currentBoundingBox; }

protected:
	BoundingVolumeType volumeType = BoundingVolumeType::BOUNDING_SPHERE;

	Collider_Sphere* colliderSphere = nullptr;
	BoundingSphere currentBoundingSphere;

	Collider_Box* colliderBox = nullptr;
	BoundingBox currentBoundingBox;

	bool collision = false;
	bool lockPositionW = false;
	bool lockPositionS = false;
};

