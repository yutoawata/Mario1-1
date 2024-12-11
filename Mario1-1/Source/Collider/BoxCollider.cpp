#include "BoxCollider.h"

//�R���X�g���N�^(�摜�f�ނ̑傫��)
BoxCollider::BoxCollider(int graph_hndle, std::string tag_, bool is_trigger)
	:moveVector(Vector2::ZERO), tag(tag_),isTrigger(is_trigger) {
	GetGraphSize(graph_hndle, &length.x, &length.y);
}

//�R���X�g���N�^(�摜����)
BoxCollider::BoxCollider(Vector2 position, int width_, int height_, std::string tag_, bool is_trigger)
	:moveVector(Vector2::ZERO), length(Vector2(width_, height_)), tag(tag_), isTrigger(is_trigger) {}


//�f�X�g���N�^
BoxCollider::~BoxCollider() {}

void BoxCollider::OnCollision(const ObjectBase& other_) {}

void BoxCollider::OnTrigger(const ObjectBase& other_) {}