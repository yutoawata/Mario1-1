#pragma once
#include "../BaseClass/ObjectBase.h"
#include "../Move_D/MoveValueManager.h"
#include "../Mario/Mario.h"

class Fort : ObjectBase
{
public:
	Fort(Vector2 position_, int image_handle);
	~Fort();

	void Update() override;
	void Draw() override;

private:
	int imageHandle;

};
