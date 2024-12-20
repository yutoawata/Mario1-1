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
	ObjectBase(Vector2 position_, int image_handle, std::string tag_ = "");
	ObjectBase(Vector2 position_, std::string tag_, int width, int height);
	//�f�X�g���N�^
	virtual ~ObjectBase();

	//�A�N�Z�T

	Vector2 GetPosition() const { return position; }
	bool IsVisible() const { return isVisible; }
	bool IsActive() const { return isActive; }

	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() = 0;
	//�Փ˔��莞�̏���
	virtual void OnCollision(const CollideResult& result_);

	//�����o�ϐ�
protected:
	Vector2 position;	//�I�u�W�F�N�g�̌��_���W(����)
	bool isVisible;		//�`��t���O
	bool isActive;
	bool isActive;		//�������t���O
};