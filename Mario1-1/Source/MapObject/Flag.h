#pragma once
#include "../BaseClass/ObjectBase.h"
#include "../Move_D/DebugBlockMove.h"

class Flag : ObjectBase
{
public:
	Flag(Vector2 position_, int image_handle);
	~Flag();

	void Update() override;
	void Draw() override;

private:

	DebugBlockMove* debugBlockMove = new DebugBlockMove();
	Vector2 move_val;
	int imageHandle;

};
