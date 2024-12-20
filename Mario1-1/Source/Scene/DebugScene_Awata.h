#pragma once
#include <functional>
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"

class DebugObject : public ObjectBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugObject(int* handles_);
	//�f�X�g���N�^
	~DebugObject();

	void Update() override {
		int i = 0;
	}
	void Draw() override;

	int GetValue() { return i; }

private:
	int i = 0;
};

class DebugObject02 : public ObjectBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	DebugObject02(std::function<int(void)> add_func);
	//�f�X�g���N�^
	~DebugObject02();

	void Update() override;
	void Draw() override;


	void OnCollision(const CollideResult& other_) override;

	std::function<int(void)> addFunc;
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