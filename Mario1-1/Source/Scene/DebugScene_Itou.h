#pragma once
#include "..\BaseClass\SceneBase.h"

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
};