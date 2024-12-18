#include "BoxCollider.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^(�摜�f�ނ̑傫��)
BoxCollider::BoxCollider(Vector2& left_up_posision, int graph_hndle, std::string tag_)
	: leftUpPosition(left_up_posision), moveVector(Vector2::ZERO), tag(tag_) {
	//�R���C�_�[�̑傫�����摜�T�C�Y�ɍ��킹��
	GetGraphSize(graph_hndle, &length.x, &length.y);
}

//�R���X�g���N�^(�摜����)
BoxCollider::BoxCollider(Vector2& center_position, int width_, int height_, std::string tag_)
	: leftUpPosition(center_position), moveVector(Vector2::ZERO), length(Vector2(width_, height_)), tag(tag_) {}


//�f�X�g���N�^
BoxCollider::~BoxCollider() {}

void BoxCollider::DrawCollider() {
	Vector2 rightBottomPosition = leftUpPosition + length;
	DrawFillBox(leftUpPosition.x, leftUpPosition.y, rightBottomPosition.x, rightBottomPosition.y, GetColor(255, 0, 0));
	DrawCircle(GetLeftUpPosition().x, GetLeftUpPosition().y, 10, GetColor(255, 255, 255), TRUE);
	DrawCircle(GetRightBottomPosition().x, GetRightBottomPosition().y, 10, GetColor(255, 255, 255), TRUE);
}

//�Փˏ���
bool BoxCollider::Collide(BoxCollider& other_) {
	//�ړ��ʂ��Z�o
	moveVector = leftUpPosition - latePosition;
	bool isCollide = false;
	//�u���b�N�����蔲���Ȃ����ߏՓ˂��Ȃ��ꏊ�܂Ŗ߂�
	if (tag != "Block" && other_.GetTag() == "Block") {
		Vector2 checkPosition = latePosition + Vector2(moveVector.x, 0);
		BoxCollider checkCollider = BoxCollider(checkPosition, length.x, length.y, tag);
		
		//���E�����̈ړ��ʂœ����蔻����s��
		if (ObjectManager::CheckCollision(checkCollider, static_cast<const BoxCollider&>(other_))) {
			//�Փ˂��Ă���Έړ��ʂ�����
			leftUpPosition.x -= moveVector.x;
			isCollide = true;
		}

		checkPosition = latePosition + Vector2(0, moveVector.y);
		//�㉺�����̈ړ��ʂœ����蔻����s��
		if (ObjectManager::CheckCollision(checkCollider, static_cast<const BoxCollider&>(other_))) {
			//�Փ˂��Ă���Έړ��ʂ�����
			leftUpPosition.y -= moveVector.y;
			isCollide = true;
		}
	}
	else {
		if (ObjectManager::CheckCollision(*this, static_cast<const BoxCollider&>(other_))) {
			isCollide = true;
			DrawString(150, 0, "Collide", GetColor(255, 255, 255));
		}
	}
	//�ړ��O�̍��W���X�V
	latePosition = leftUpPosition;
	return isCollide;
}