#pragma once
#include "..\BaseClass\\BlockBase.h"

class BreakBlock : public BlockBase
{
public:
	// �����o�֐�
	BreakBlock(); // �R���X�g���N�^
	~BreakBlock(); // �f�X�g���N�^
	void Update() override; // �X�V����
	void Draw() override; // �`�揈��
	void OnCollision(const CollideResult& result_) override; // �Փˎ��̏���

private:

	// �����o�ϐ�
	int imageHandle; // �摜�n���h��
};
