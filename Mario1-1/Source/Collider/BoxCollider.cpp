#include "BoxCollider.h"

//�R���X�g���N�^
BoxCollider::BoxCollider(int width_, int height_, std::string tag_, bool is_trigger)
	:moveVector(Vector2::ZERO), width(width_),height(height_),tag(tag_),isTrigger(is_trigger) {}

//�f�X�g���N�^
BoxCollider::~BoxCollider() {}

void BoxCollider::OnCollision() {}

void BoxCollider::OnTrigger() {}