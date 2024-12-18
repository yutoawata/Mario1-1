#pragma once
#include <string>
#include "..\BaseClass\ObjectBase.h"

class ObjectBase;

class CollideResult {
	//�����o�֐�
public:
	CollideResult(const ObjectBase& object_, std::string collideDirection);
	~CollideResult();

	//�A�N�Z�T

	const ObjectBase& GetCollideObject() const;
	//���������̏Փ˃t���O��n��
	bool IsUpCollide() const;
	//����������̏Փ˃t���O��n��
	bool IsBottomCollide() const;
	//����������̏Փ˃t���O��n��
	bool IsLeftCollide() const;
	//�E��������̏Փ˃t���O��n��
	bool IsRightCollide() const;

private:
	const ObjectBase& object;
	bool isUpCollide = false;
	bool isBottomCollide = false;
	bool isLeftCollide = false;
	bool isRightCollide = false;

};