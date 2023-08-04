#include "Math.h"

//vertor2
bool Vector2::operator == (Vector2& vertex) {
	if (fabs(x - vertex.x) < _EPSILON)
		if (fabs(y - vertex.y) < _EPSILON)
				return true;
	
	return false;
}
bool Vector2::operator != (Vector2& vertex) {
	return !(*this == vertex);
}
Vector2 Vector2::operator + (Vector2& vertex) {
	return Vector2(x + vertex.x, y + vertex.y);
}
Vector2 Vector2::operator - (Vector2& vertex) {
	return Vector2(x - vertex.x, y - vertex.y);
}
Vector2 Vector2::operator * (float Value) {
	return Vector2(x * Value, y * Value);
}
Vector2 Vector2::operator / (float Value) {
	return Vector2(x /Value, y /Value);
}
Vector2& Vector2::operator /= (float Value) {
	x = x / Value;
	y = y / Value;
	return *this;
}
float Vector2::Length()
{
	float fDistance = sqrt(x * x + y * y);
	return fDistance;
}
float Vector2::Length(Vector2& p)
{
	float fDistance = sqrt(p.x * p.x + p.y * p.y);
	return fDistance;
}


//vertor3
float Vector3::operator  | (Vector3& vertex) {
	return (x * vertex.x + y * vertex.y + z * vertex.z);
}
Vector3 Vector3::operator ^ (Vector3& vertex) {
	return Vector3(y * vertex.z - z * vertex.y,
		z * vertex.x - x * vertex.z,
		x * vertex.y - y * vertex.x);
}
bool Vector3::operator == (Vector3& vertex) {
	if (fabs(x - vertex.x) > _EPSILON)
		if (fabs(y - vertex.y) > _EPSILON)
			if (fabs(z - vertex.z) > _EPSILON)
				return true;
	return false;
}
bool Vector3::operator != (Vector3 vertex) {
	return !(*this == vertex);
}
Vector3 Vector3::operator + (Vector3& vertex) {
	return Vector3(x + vertex.x, y + vertex.y, z + vertex.z);
}
Vector3 Vector3::operator - (Vector3& vertex) {
	return Vector3(x - vertex.x, y - vertex.y, z - vertex.z);
}
Vector3 Vector3::operator * (float Value) {
	return Vector3(x * Value, y * Value, z * Value);
}
Vector3 Vector3::operator / (float Value) {
	return Vector3(x / Value, y / Value, z / Value);
}
Vector3& Vector3::operator /= (float Value) {
	x = x / Value;
	y = y / Value;
	z = z / Value;
	return *this;
}
float Vector3::Length() {
	float fDistance = sqrt(x * x + y * y + z * z);
	return fDistance;
}
static float Length(Vector3& p) {
	float fDistance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	return fDistance;
}

