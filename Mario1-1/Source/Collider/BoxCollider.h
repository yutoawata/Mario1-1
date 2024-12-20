#pragma once
#include <string>
#include "..\Math\Vector2.h"

class BoxCollider {
	//�����o�֐�
public:
	//�R���X�g���N�^(�摜�f�ނɍ��킹���T�C�Y)
	BoxCollider(Vector2& left_up_position, int graph_handle, std::string tag_ = "");
	//�R���X�g���N�^(�摜�f�ނȂ�)
	BoxCollider(Vector2& position, int width, int height, std::string tag_ = "");
	//�f�X�g���N�^
	virtual ~BoxCollider();

	//�A�N�Z�T

	//�I�u�W�F�N�g�̔��ʃ^�O��n��
	std::string GetTag() const { return tag; }
	//���_���W(����)��n��
	Vector2 GetLeftUpPosition() const { return leftUpPosition; }
	//�E���̍��W��n��
	Vector2 GetRightBottomPosition() const { return leftUpPosition + length; }
	Vector2 GetLength()const { return length; }
	//������n��
	int GetWidth() const { return length.x; }
	//�c����n��
	int GetHeigth() const { return length.y; }

	void DrawCollider();
	bool Collide(BoxCollider& other_);
	
	//�����o�ϐ�
private:
	std::string tag;		//�R���C�_�[�^�O
	Vector2& leftUpPosition;//�I�u�W�F�N�g�̌��_���W(����)
	Vector2 latePosition;	//�ړ��O�̍��W
	Vector2 moveVector;		//�ړ��x�N�g��
	Vector2 length;			//�e�������̕�(x:����, y:�c��)
};