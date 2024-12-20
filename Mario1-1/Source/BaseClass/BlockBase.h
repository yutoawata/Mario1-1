#pragma once
#include "ObjectBase.h"

class BlockBase : public ObjectBase
{
public:
	// �����o�֐�
	BlockBase(Vector2 position_, int handle_); // �R���X�g���N�^
	~BlockBase(); // �f�X�g���N�^
	void Update() override; // �X�V����

private:
	// �����o�֐�
	void Move(); // �X�N���[������

	// �����o�萔
	const std::string TAG = "Block"; // Object���ʗp�̃^�O

};