#pragma once
#include "..\BaseClass\SceneBase.h"
#include "..\Map\Map.h"

class DebugScene_Itou : public SceneBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugScene_Itou();
	//�f�X�g���N�^
	~DebugScene_Itou();

	SceneBase* Update() override;

	void Draw() override;

	//�����o�ϐ�
private:
	Map *map = new Map();

};