#pragma once
#include "../BaseClass/ObjectBase.h"
#include "../Move_D/DebugBlockMove.h"

class Pype : public ObjectBase
{
public:
	Pype(Vector2 position_,int image_handle,std::string tag_);
	~Pype();

	void Update() override;
	void Draw() override;

private:

	DebugBlockMove* debugBlockMove = new DebugBlockMove();
	int imageHandle; // ‰æ‘œ•Û‘¶ƒnƒ“ƒhƒ‹


};