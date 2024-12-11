#pragma once
#include <string>
#include "..\Math\Vector2.h"
#include"..\BaseClass\ObjectBase.h"

class ObjectBase;

class BoxCollider {
	//�����o�֐�
public:
	//�R���X�g���N�^(�摜�f�ނɍ��킹���T�C�Y)
	BoxCollider(int graph_handle, std::string tag_ = "", bool is_trigger = false);
	//�R���X�g���N�^(�摜�f�ނȂ�)
	BoxCollider(Vector2 position, int width, int height, std::string tag_ = "", bool is_trigger = false);
	//�f�X�g���N�^
	virtual ~BoxCollider();

	//�A�N�Z�T
	bool IsTrigger() { return isTrigger; }

	void OnCollision(const ObjectBase& other_);
	void OnTrigger(const ObjectBase& other_);

private:
	std::string tag;	//�R���C�_�[�^�O
	Vector2 moveVector;	//�ړ��x�N�g��
	Vector2 length;
	bool isTrigger;		//���蔲���t���O
};