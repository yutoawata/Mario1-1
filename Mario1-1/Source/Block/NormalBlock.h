#pragma once
#include "..\BaseClass\BlockBase.h"

class NormalBlock : public BlockBase
{
public:
	// �����o�֐�
	NormalBlock(Vector2 position_,int handle_); // �R���X�g���N�^
	~NormalBlock(); // �f�X�g���N�^
	void Draw() override; // �`�揈��

private:

	// �����o�ϐ�
	int imageHandle;
};