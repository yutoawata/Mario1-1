#pragma once
#include "..\BaseClass\\BlockBase.h"

class BreakBlock : public BlockBase
{
public:
	// �����o�֐�
	BreakBlock(Vector2 position_, int handle_); // �R���X�g���N�^
	~BreakBlock(); // �f�X�g���N�^
	void Draw() override; // �`�揈��
	void OnCollision(const CollideResult& result_) override; // �Փˎ��̏���

private:

	// �����o�ϐ�
	int imageHandle; // �摜�n���h��
};
