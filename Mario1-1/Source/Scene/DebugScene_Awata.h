#pragma once
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"

class DebugObject : public ObjectBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugObject(std::vector<int> handle_, int* handles_);
	//�f�X�g���N�^
	~DebugObject();

	void Update() override;
	void Draw() override;

private:
	int handle[];

};

class DebugObject02 : public ObjectBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugObject02(std::vector<int> handle_);
	//�f�X�g���N�^
	~DebugObject02();

	void Update() override;
	void Draw() override;


	void OnCollision(const CollideResult& other_) override;
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