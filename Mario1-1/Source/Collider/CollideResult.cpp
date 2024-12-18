#include "CollideResult.h"

CollideResult::CollideResult(const ObjectBase& object_, std::string collideDirection) 
	: object(object_) {
	if (collideDirection == "��") {
		isUpCollide = true;
	}
	else if (collideDirection == "��") {
		isBottomCollide = true;
	}
	else if (collideDirection == "��") {
		isLeftCollide = true;
	}
	else if (collideDirection == "�E") {
		isRightCollide = true;
	}
}

CollideResult::~CollideResult() {}

//�Փˑ����n��
const ObjectBase& CollideResult::GetCollideObject() const { return object; }
//���������̏Փ˃t���O��Ԃ�
bool CollideResult::IsUpCollide() const { return isUpCollide; }
//����������̏Փ˃t���O��Ԃ�
bool CollideResult::IsBottomCollide() const { return isBottomCollide; }
//����������̏Փ˃t���O��Ԃ�
bool CollideResult::IsLeftCollide() const { return isLeftCollide; }
//�E��������̏Փ˃t���O��Ԃ�
bool CollideResult::IsRightCollide() const { return isRightCollide; }