#pragma once
#include <string>
#include "DxLib.h"

class SceneBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	SceneBase(std::string type_);
	//�f�X�g���N�^
	~SceneBase();

public:
	//�X�V����
	virtual SceneBase* Update() = 0;
	//�`�揈��
	virtual void Draw() = 0;

	//�V�[���J�ڏ���
	template<class Scene>
	SceneBase* ChangeScene();

	void DrawType();

	//�����o�ϐ�
protected:
	std::string type = "Base";
};