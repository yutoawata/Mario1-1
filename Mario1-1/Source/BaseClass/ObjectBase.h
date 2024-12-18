#pragma once
#include <vector>
#include "..\Math\Vector2.h"
#include "..\Collider\BoxCollider.h"
#include "..\Collider\CollideResult.h"

class CollideResult;

class ObjectBase : public BoxCollider {
	//�����o�֐�
public:
	//�R���X�g���N�^
	ObjectBase(std::vector<int> graph_handles, Vector2 position_, std::string tag_);
	ObjectBase(Vector2 position_, std::string tag_, int width, int height);
	//�f�X�g���N�^
	virtual ~ObjectBase();

	//�A�N�Z�T

	Vector2 GetPosition() const { return position; }
	bool IsVisible() const { return isVisible; }

	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() = 0;
	//�Փ˔��莞�̏���
	virtual void OnCollision(const CollideResult& result_);

	//�����o�ϐ�
protected:
	std::vector<int> graphHandles;//�摜�f�ނ̃n���h��
	Vector2 position;	//�I�u�W�F�N�g�̌��_���W(����)
	bool isVisible;		//�`��t���O
};