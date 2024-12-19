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
	static ObjectManager* GetInstance() { return instance; }

	static void DeleteInstance();
	
	static bool CheckCollision(const BoxCollider& collider_01, const BoxCollider& collider_02);

	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//���X�g�폜����
	void ClearList();
	//���X�g�o�^����
	void AddList(ObjectBase* object_);
	//�����蔻�菈��
	void CollideObjects(ObjectBase& object_,int object_num);
	CollideResult CreateResult(const ObjectBase& collider_01, const ObjectBase& collider_02);
	
	//�����o�ϐ�
private:
	static ObjectManager* instance;		//�O���Q�Ɨp�̃C���X�^���X
	std::vector<ObjectBase*> objectList;//�I�u�W�F�N�g�̃��X�g
};