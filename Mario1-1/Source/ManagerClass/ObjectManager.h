#pragma once
#include<vector>
#include "..\BaseClass\ObjectBase.h"

class ObjectManager {
	//�����o�֐�
private:
	//�R���X�g���N�^
	ObjectManager();
	//�R�s�[�R���X�g���N�^���폜
	ObjectManager(const ObjectManager&) = delete;
	//�f�X�g���N�^
	~ObjectManager();

	//�A�N�Z�T
public:
	static ObjectManager* getInstance() { return instance; }

	//�o�^����
	static void AddList(ObjectBase* object_);
	static void ClearList();
	static void DeleteInstance();

	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	
	static ObjectManager* instance;
	//�����o�ϐ�
private:
	static std::vector<ObjectBase*> objectList;//�I�u�W�F�N�g�̃��X�g
};