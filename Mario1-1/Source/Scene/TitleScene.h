#pragma once
#include "..\BaseClass\SceneBase.h"

class TitleScene : public SceneBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	TitleScene();
	//�f�X�g���N�^
	~TitleScene();

	//�X�V����
	SceneBase* Update() override;
	//�`�揈��
	void Draw() override;
};