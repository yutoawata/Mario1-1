#pragma once
#include"../BaseClass/ObjectBase.h"
#include "../Move_D/MoveValueManager.h"
#include "../Mario/Mario.h"

class Pole: public ObjectBase
{
public:
	Pole(Vector2 position_, int image_handle);
	~Pole();

	void Update() override;
	void Draw() override;

private:
	int imageHandle;
};