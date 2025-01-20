#pragma once
#include "../BaseClass/ObjectBase.h"
#include "../Move_D/MoveValueManager.h"
#include "../Mario/Mario.h"

class Flag : ObjectBase
{
public:
	Flag(Vector2 position_, int image_handle);
	~Flag();

	void Update() override;
	void Draw() override;

private:
	int imageHandle;

};
