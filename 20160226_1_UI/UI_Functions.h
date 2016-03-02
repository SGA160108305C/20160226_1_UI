#pragma once

class Collider_Box;
class Collider_Sphere;

class UI_Functions
{
public:
	UI_Functions();
	~UI_Functions();

	void ClickTest();
	void CloseTarget(UI_Base* target);
	void OpenTarget(UI_Base* target);
	void ClickOptionButton(
		UI_Base* box, std::vector<Collider_Box*> &boxList,
		UI_Base* sphere, std::vector<Collider_Sphere*> &sphereList,
		BoundingVolumeType type, int idx
		);
};

