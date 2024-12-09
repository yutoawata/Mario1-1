#include"Vector2.h"

const Vector2 Vector2::ZERO = Vector2(0, 0);

Vector2::Vector2() {}

Vector2::Vector2(int x_, int y_) {
	x = x_;
	y = y_;
}

Vector2::Vector2(VECTOR vector_) {
	x = static_cast<int>(vector_.x);
	y = static_cast<int>(vector_.y);
}

//���Ϗ���
float Vector2::Dot(Vector2 vec_01, Vector2 vec_02) {
	return static_cast<float>((vec_01.x * vec_02.x) + (vec_01.y * vec_02.y));
}

//�O�Ϗ���
float Vector2::Cross(Vector2 vec_01, Vector2 vec_02) {
	return static_cast<float>((vec_01.x * vec_02.y) - (vec_01.y * vec_02.x));
}

//�T�C�Y��Ԃ�
int Vector2::getSize() const {
	float vecX = static_cast<float>(x);
	float vecY = static_cast<float>(y);
	return static_cast<int>(sqrtf(vecX * vecX + vecY * vecY));
}

Vector2 Vector2::Normalized() const {
	int size = getSize();
	return Vector2(x / size, y / size);
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(int value) const {
	return Vector2(x * value, y * value);
}

Vector2 Vector2::operator/(int value) const {
	return Vector2(x / value, y / value);
}

Vector2& Vector2::operator +=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}
Vector2& Vector2::operator -=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

bool Vector2::operator ==(const Vector2& other) {
	return (x == other.x && y == other.y);
}

bool Vector2::operator !=(const Vector2& other) {
	return (x != other.x || y != other.y);
}

Vector2::operator VECTOR() {
	return VGet(static_cast<float>(x), static_cast<float>(y), 0.0f);
}
