#pragma once
#include "..\Math\Vector2.h"

class ObjectBase {
	//�����o�֐�
public:
	//�R���X�g���N�^
	ObjectBase(Vector2 position_, int image_handle);
	//�f�X�g���N�^
	virtual ~ObjectBase();

	//�A�N�Z�T

	Vector2 GetPosition() { return position; }
	bool IsVisible() { return isVisible; }

	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() = 0;

	//�����o�ϐ�
protected:
	Vector2 position;	//�I�u�W�F�N�g�̒��S���W
	int imageHandle;	//�摜�f�ނ̃n���h��
	bool isVisible;		//�`��t���O
};