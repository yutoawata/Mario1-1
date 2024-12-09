#pragma once
#include <string>
#include "..\Math\Vector2.h"

class BoxCollider {
	//�����o�֐�
	BoxCollider(int width_, int height_, std::string tag_, bool is_trigger = false);
	//�f�X�g���N�^
	~BoxCollider();

	void OnCollision();
	void OnTrigger();

private:
	std::string tag;	//�R���C�_�[�^�O
	Vector2 moveVector;	//�ړ��x�N�g��
	int width;		//����
	int height;		//�c��
	bool isTrigger;		//���蔲���t���O
};