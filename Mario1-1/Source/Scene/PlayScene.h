#pragma once
#include "..\BaseClass\SceneBase.h"

class PlayScene : public SceneBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	PlayScene();
	//�f�X�g���N�^
	~PlayScene();

	//�X�V����
	SceneBase* Update() override;
	//�`�揈��
	void Draw() override;
};