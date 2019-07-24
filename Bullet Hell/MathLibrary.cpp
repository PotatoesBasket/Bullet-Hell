#include <math.h>
#include "MathLibrary.h"

/////////////////////////////////
//          Vector 2           //
/////////////////////////////////

Vector2& Vector2::operator = (const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2 Vector2::operator + (const Vector2& other) const
{
	return { x + other.x, y + other.y };
}

Vector2& Vector2::operator += (const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator - (const Vector2& other) const
{
	return { x - other.x, y - other.y };
}

Vector2& Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator * (float scalar) const
{
	return { x * scalar, y * scalar };
}

Vector2 operator * (float scalar, const Vector2& v)
{
	return { v * scalar };
}

Vector2& Vector2::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2 Vector2::operator / (float scalar) const
{
	return { x / scalar, y / scalar };
}

Vector2& Vector2::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}

float Vector2::operator [] (int index) const
{
	return data[index];
}

float& Vector2::operator [] (int index)
{
	return data[index];
}

Vector2::operator float* ()
{
	return data;
}

Vector2::operator const float* () const
{
	return data;
}

double Vector2::distance(const Vector2& other) const
{
	return sqrt(distanceSqr(other));
}

float Vector2::distanceSqr(const Vector2& other) const
{
	float dx, dy;
	dx = x - other.x;
	dy = y - other.y;
	return dx * dx + dy * dy;
}

double Vector2::magnitude() const
{
	return sqrt(magnitudeSqr());
}

float Vector2::magnitudeSqr() const
{
	return { x * x + y * y };
}

void Vector2::normalise()
{
	Vector2 vec = *this;
	float mag = vec.magnitude();
	vec /= mag;
}

Vector2 Vector2::normalised() const
{
	Vector2 vec = *this;
	float mag = vec.magnitude();
	return vec / mag;
}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

/////////////////////////////////
//          Vector 3           //
/////////////////////////////////

Vector3& Vector3::operator = (const Vector2& other)
{
	x = other.x;
	y = other.y;
	z = 0;
	return *this;
}

Vector3& Vector3::operator = (const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 Vector3::operator + (const Vector3& other) const
{
	return { x + other.x, y + other.y, z + other.z };
}

Vector3& Vector3::operator += (const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3 Vector3::operator - (const Vector3& other) const
{
	return { x - other.x, y - other.y, z - other.z };
}

Vector3& Vector3::operator -= (const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3 Vector3::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar };
}

Vector3 operator * (float scalar, const Vector3& v)
{
	return { v * scalar };
}

Vector3& Vector3::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3 Vector3::operator / (float scalar) const
{
	return { x / scalar, y / scalar, z / scalar };
}

Vector3& Vector3::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

float Vector3::operator [] (int index) const
{
	return data[index];
}

float& Vector3::operator [] (int index)
{
	return data[index];
}

Vector3::operator float* ()
{
	return data;
}

Vector3::operator const float* () const
{
	return data;
}

double Vector3::distance(const Vector3& other) const
{
	return sqrt(distanceSqr(other));
}

float Vector3::distanceSqr(const Vector3& other) const
{
	float dx, dy, dz;
	dx = x - other.x;
	dy = y - other.y;
	dz = z - other.z;
	return dx * dx + dy * dy + dz * dz;
}

double Vector3::magnitude() const
{
	return sqrt(magnitudeSqr());
}

float Vector3::magnitudeSqr() const
{
	return { x * x + y * y + z * z };
}

void Vector3::normalise()
{
	Vector3 vec = *this;
	float mag = vec.magnitude();
	vec /= mag;
}

Vector3 Vector3::normalised() const
{
	Vector3 vec = *this;
	float mag = vec.magnitude();
	return vec / mag;
}

float Vector3::dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const
{
	return
	{
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	};
}

/////////////////////////////////
//          Vector 4           //
/////////////////////////////////

Vector4& Vector4::operator = (const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = 0;
	return *this;
}

Vector4& Vector4::operator = (const Vector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

Vector4 Vector4::operator + (const Vector4& other) const
{
	return { x + other.x, y + other.y, z + other.z, w + other.w };
}

Vector4& Vector4::operator += (const Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4 Vector4::operator - (const Vector4& other) const
{
	return { x - other.x, y - other.y, z - other.z, w - other.w };
}

Vector4& Vector4::operator -= (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4 Vector4::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}

Vector4 operator * (float scalar, const Vector4& v)
{
	return { v * scalar };
}

Vector4& Vector4::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

Vector4 Vector4::operator / (float scalar) const
{
	return { x / scalar, y / scalar, z / scalar, w / scalar };
}

Vector4& Vector4::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

float Vector4::operator [] (int index) const
{
	return data[index];
}

float& Vector4::operator [] (int index)
{
	return data[index];
}

Vector4::operator float* ()
{
	return data;
}

Vector4::operator const float* () const
{
	return data;
}

double Vector4::distance(const Vector4& other) const
{
	return sqrt(distanceSqr(other));
}

float Vector4::distanceSqr(const Vector4& other) const
{
	float dx, dy, dz, dw;
	dx = x - other.x;
	dy = y - other.y;
	dz = z - other.z;
	dw = w - other.w;
	return dx * dx + dy * dy + dz * dz + dw * dw;
}

double Vector4::magnitude() const
{
	return sqrt(magnitudeSqr());
}

float Vector4::magnitudeSqr() const
{
	return { x * x + y * y + z * z + w * w };
}

void Vector4::normalise()
{
	Vector4 vec = *this;
	float mag = vec.magnitude();
	vec /= mag;
}

Vector4 Vector4::normalised() const
{
	Vector4 vec = *this;
	float mag = vec.magnitude();
	return vec / mag;
}

float Vector4::dot(const Vector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector4 Vector4::cross(const Vector4& other) const
{
	return
	{
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x,
		0
	};
}

/////////////////////////////////
//          Matrix 2           //
/////////////////////////////////

const Matrix2 Matrix2::identity = Matrix2(1, 0,
										  0, 1);

Matrix2::Matrix2(Vector2 xAxis, Vector2 yAxis) :
	xAxis{ xAxis }, yAxis{ yAxis } {}

Matrix2::Matrix2(float XX, float XY, float YX, float YY) :
	xAxis{ XX, YX }, yAxis{ YX, YY } {}

Matrix2& Matrix2::operator = (const Matrix2& other)
{
	xAxis = other.xAxis;
	yAxis = other.yAxis;
	return *this;
}

Vector2 Matrix2::operator * (const Vector2& v) const
{
	Vector2 result;
	for (int r = 0; r < 2; ++r)
	{
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1];
	}
	return result;
}

Matrix2 Matrix2::operator * (const Matrix2& other) const
{
	Matrix2 result;
	for (int r = 0; r < 2; ++r)
		for (int c = 0; c < 2; ++c)
		{
			result.data[c][r] =
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1];
		}
	return result;
}

Vector2& Matrix2::operator [] (int index)
{
	return axis[index];
}

const Vector2& Matrix2::operator [] (int index) const
{
	return axis[index];
}

Matrix2::operator float* ()
{
	return floats;
}

Matrix2::operator const float* () const
{
	return floats;
}

Matrix2 Matrix2::transposed() const
{
	Matrix2 result;
	for (int r = 0; r < 2; ++r)
		for (int c = 0; c < 2; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void Matrix2::setRotate(float radians)
{
	xAxis = { cosf(radians), sinf(radians) };
	yAxis = { -sinf(radians), cosf(radians) };
}

void Matrix2::rotate(float radians)
{
	Matrix2 m;
	m.setRotate(radians);

	*this = *this * m;
}

void Matrix2::setScaled(float x, float y)
{
	xAxis = { x, 0 };
	yAxis = { 0, y };
}

void Matrix2::setScaled(const Vector2& v)
{
	xAxis = { v.x, 0 };
	yAxis = { 0, v.y };
}

void Matrix2::scale(float x, float y)
{
	Matrix2 m;
	m.setScaled(x, y);

	*this = *this * m;
}

void Matrix2::scale(const Vector2& v)
{
	Matrix2 m;
	m.setScaled(v.x, v.y);

	*this = *this * m;
}

/////////////////////////////////
//          Matrix 3           //
/////////////////////////////////

const Matrix3 Matrix3::identity = Matrix3(1, 0, 0,
										  0, 1, 0,
										  0, 0, 1);

Matrix3::Matrix3(Vector3 xAxis, Vector3 yAxis, Vector3 zAxis) :
	xAxis{ xAxis }, yAxis{ yAxis }, zAxis{ zAxis } {}

Matrix3::Matrix3(float XX, float XY, float XZ,
	float YX, float YY, float YZ,
	float ZX, float ZY, float ZZ) :
	xAxis{ XX, XY, XZ }, yAxis{ YX, YY, YZ }, zAxis{ ZX, ZY, ZZ } {}

Matrix3::Matrix3(const Matrix3& other) :
	xAxis{ other.xAxis }, yAxis{ other.yAxis }, zAxis{ other.zAxis } {}

Matrix3& Matrix3::operator = (const Matrix3& other)
{
	xAxis = other.xAxis;
	yAxis = other.yAxis;
	zAxis = other.zAxis;
	return *this;
}

Vector3 Matrix3::operator * (const Vector3& v) const
{
	Vector3 result;
	for (int r = 0; r < 3; ++r)
	{
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2];
	}
	return result;
}

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 3; ++c)
		{
			result.data[c][r] =
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2];
		}
	return result;
}

Vector3& Matrix3::operator [] (int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator [] (int index) const
{
	return axis[index];
}

Matrix3::operator float* ()
{
	return floats;
}

Matrix3::operator const float* () const
{
	return floats;
}

Matrix3 Matrix3::transposed() const
{
	Matrix3 result;
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 3; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void Matrix3::translate(float x, float y)
{
	translation.x += x;
	translation.y += y;
}

void Matrix3::translate(const Vector3& v)
{
	translation += v;
}

void Matrix3::setRotateX(float radians)
{
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };
}

void Matrix3::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, sinf(radians) };
	yAxis = { 0, 1, 0 };
	zAxis = { -sinf(radians), 0, cosf(radians) };
}

void Matrix3::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0 };
	yAxis = { -sinf(radians), cosf(radians), 0 };
	zAxis = { 0, 0, 1 };
}

void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix3::rotate(float pitch, float yaw, float roll)
{
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	*this = z * y * x;
}

void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0 };
	yAxis = { 0, y, 0 };
	zAxis = { 0, 0, z };
}

void Matrix3::setScaled(const Vector3& v)
{
	xAxis = { v.x, 0, 0 };
	yAxis = { 0, v.y, 0 };
	zAxis = { 0, 0, v.z };
}

void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);

	*this = *this * m;
}

void Matrix3::scale(const Vector3& v)
{
	Matrix3 m;
	m.setScaled(v.x, v.y, v.z);

	*this = *this * m;
}

/////////////////////////////////
//          Matrix 4           //
/////////////////////////////////

const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0,
										  0, 1, 0, 0,
										  0, 0, 1, 0,
										  0, 0, 0, 1);

Matrix4::Matrix4() :
	xAxis{ 0, 0, 0, 0 }, yAxis{ 0, 0, 0, 0 },
	zAxis{ 0, 0, 0, 0 }, translation{ 0, 0, 0, 0 } {}

Matrix4::Matrix4(Vector4 xAxis, Vector4 yAxis, Vector4 zAxis, Vector4 translation) :
	xAxis{ xAxis }, yAxis{ yAxis }, zAxis{ zAxis }, translation{ translation } {}

Matrix4::Matrix4(float XX, float XY, float XZ, float XW, float YX, float YY, float YZ, float YW,
	float ZX, float ZY, float ZZ, float ZW, float TX, float TY, float TZ, float TW) :
	xAxis{ XX, XY, XZ, XW }, yAxis{ YX, YY, YZ, YW },
	zAxis{ ZX, ZY, ZZ, ZW }, translation{ TX, TY, TZ, TW } {}

Matrix4::Matrix4(const Matrix4& other) :
	xAxis{ other.xAxis }, yAxis{ other.yAxis },
	zAxis{ other.zAxis }, translation{ other.translation } {}

Matrix4& Matrix4::operator = (const Matrix4& other)
{
	xAxis = other.xAxis;
	yAxis = other.yAxis;
	zAxis = other.zAxis;
	translation = other.translation;
	return *this;
}

Vector4 Matrix4::operator * (const Vector4& v) const
{
	Vector4 result;
	for (int r = 0; r < 4; ++r)
	{
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2] +
			data[3][r] * v[3];
	}
	return result;
}

Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
		{
			result.data[c][r] =
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2] +
				data[3][r] * other.data[c][3];
		}
	return result;
}

Vector4& Matrix4::operator [] (int index)
{
	return axis[index];
}

const Vector4& Matrix4::operator [] (int index) const
{
	return axis[index];
}

Matrix4::operator float* ()
{
	return floats;
}

Matrix4::operator const float* () const
{
	return floats;
}

Matrix4 Matrix4::transposed() const
{
	Matrix4 result;
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void Matrix4::translate(float x, float y, float z)
{
	translation.x += x;
	translation.y += y;
	translation.z += z;
}

void Matrix4::translate(const Vector4& v)
{
	translation += v;
}

void Matrix4::setRotateX(float radians)
{
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, sinf(radians), 0 };
	yAxis = { 0, 1, 0, 0 };
	zAxis = { -sinf(radians), 0, cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0, 0 };
	yAxis = { -sinf(radians), cosf(radians), 0, 0 };
	zAxis = { 0, 0, 1, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix4::rotate(float pitch, float yaw, float roll)
{
	Matrix4 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	*this = z * y * x;
}

void Matrix4::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0, 0 };
	yAxis = { 0, y, 0, 0 };
	zAxis = { 0, 0, z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::setScaled(const Vector4& v)
{
	xAxis = { v.x, 0, 0, 0 };
	yAxis = { 0, v.y, 0, 0 };
	zAxis = { 0, 0, v.z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::scale(float x, float y, float z)
{
	Matrix4 m;
	m.setScaled(x, y, z);

	*this = *this * m;
}

void Matrix4::scale(const Vector4& v)
{
	Matrix4 m;
	m.setScaled(v.x, v.y, v.z);

	*this = *this * m;
}