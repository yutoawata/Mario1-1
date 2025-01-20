#pragma once
#include"../BaseClass/ObjectBase.h"
#include "../Move_D/DebugBlockMove.h"

class Pole: public ObjectBase
{
public:
	Pole(Vector2 position_, int image_handle);
	~Pole();

	void Update() override;
	void Draw() override;

private:

	DebugBlockMove* debugBlockMove = new DebugBlockMove();
	int imageHandle;
};