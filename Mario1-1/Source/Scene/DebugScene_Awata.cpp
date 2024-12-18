#include "DebugScene_Awata.h"
#include "..\ManagerClass\ObjectManager.h"

DebugObject::DebugObject(std::vector<int> handle_)
	: ObjectBase(Vector2(40, 40), "test01",30, 30) {}

DebugObject::~DebugObject() {}

//�R���X�g���N�^
DebugObject02::DebugObject02(std::vector<int> handle_)
	: ObjectBase(Vector2(80, 80), "Block", 30, 30) {}
//�f�X�g���N�^
DebugObject02::~DebugObject02() {}

void DebugObject02::Update() {}
void DebugObject02::Draw() {}

//�R���X�g���N�^
DebugScene_Awata::DebugScene_Awata()
	: SceneBase("DebugScene : Awata") {
	std::vector<int> handle = { 1 };
	DebugObject* object = new DebugObject(handle);
	DebugObject02* object02 = new DebugObject02(handle);
}

void DebugObject::Update() {

	if (CheckHitKey(KEY_INPUT_A)) {
		position.x -= 1;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		position.x += 1;
	}
	if (CheckHitKey(KEY_INPUT_W)) {
		position.y -= 1;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		position.y += 1;
	}
}

void DebugObject::Draw() {}

void DebugObject02::OnCollision(const CollideResult& other_) {
	DrawCircle(100, 100, 20, GetColor(0, 0, 255), TRUE);
}

//�f�X�g���N�^
DebugScene_Awata::~DebugScene_Awata() {}

//�X�V����
SceneBase* DebugScene_Awata::Update() {
	
	//�Q�[�����̃I�u�W�F�N�g�̍X�V����
	ObjectManager::getInstance()->Update();

	return this;
}

//�`�揈��
void DebugScene_Awata::Draw() {
	//�V�[���̎�ނ�\��
	DrawType();
	//�Q�[�����̃I�u�W�F�N�g�̕`�揈��
	ObjectManager::getInstance()->Draw();
}