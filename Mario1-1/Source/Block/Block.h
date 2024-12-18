#pragma once
#include "..\BaseClass\ObjectBase.h"
#include<vector>
#include<string>

class Block : public ObjectBase
{
public:
	enum class InItem
	{
		NONE,
		MUSHROOM,
		ONEUP_MASHROOM,
		FIRE_FLOWER,
		STAR
	};

	// �����o�֐�

	Block(Vector2 position_,std::vector<int> handle_,bool can_break); // �R���X�g���N�^(�A�C�e���Ȃ�) 
	Block(Vector2 position_,std::vector<int> handle_, InItem type_, int value_); // �R���X�g���N�^(�A�C�e������)
	~Block(); // �f�X�g���N�^
	void Update() override; // �X�V����
	void Draw() override; // �`�揈��
	// �ړ�
	// �v���C���[�ƐڐG
	
private:
	// �����o�萔
	static const std::string TAG;

	// �����o�ϐ�

	InItem inItem; // ���ɓ����Ă���A�C�e���̎��
	int itemValue; // �A�C�e���̌�
	bool canBreak; // ���邩���Ȃ����̃t���O


};