#include "BoxCollider.h"

//コンストラクタ(画像素材の大きさ)
BoxCollider::BoxCollider(int graph_hndle, std::string tag_, bool is_trigger)
	:moveVector(Vector2::ZERO), tag(tag_),isTrigger(is_trigger) {
	GetGraphSize(graph_hndle, &length.x, &length.y);
}

//コンストラクタ(画像無し)
BoxCollider::BoxCollider(Vector2 position, int width_, int height_, std::string tag_, bool is_trigger)
	:moveVector(Vector2::ZERO), length(Vector2(width_, height_)), tag(tag_), isTrigger(is_trigger) {}


//デストラクタ
BoxCollider::~BoxCollider() {}

void BoxCollider::OnCollision(const ObjectBase& other_) {}

void BoxCollider::OnTrigger(const ObjectBase& other_) {}