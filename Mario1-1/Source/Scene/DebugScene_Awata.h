#pragma once
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"

class DebugObject : public ObjectBase {
public:
	DebugObject();
	~DebugObject();

	void Update() override;
	void Draw() override;
};

class DebugScene_Awata : public SceneBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugScene_Awata();
	//�f�X�g���N�^
	~DebugScene_Awata();

	SceneBase* Update() override;

	void Draw() override;

	//�����o�ϐ�
private:
};