#pragma once
#include "../BaseClass/ObjectBase.h"
#include "../Move_D/MoveValueManager.h"
#include "../Mario/Mario.h"

class Pype : public ObjectBase
{
public:
	Pype(Vector2 position_,int image_handle,std::string tag_);
	~Pype();

	void Update() override;
	void Draw() override;

private:
	
	int imageHandle; // ‰æ‘œ•Û‘¶ƒnƒ“ƒhƒ‹
};