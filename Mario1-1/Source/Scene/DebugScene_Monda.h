#pragma once
#include "..\BaseClass\SceneBase.h"

class DebugScene_Monda : public SceneBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugScene_Monda();
	//�f�X�g���N�^
	~DebugScene_Monda();

	SceneBase* Update() override;

	void Draw() override;

	//�����o�ϐ�
private:
};