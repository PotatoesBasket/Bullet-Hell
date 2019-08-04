#pragma once

class Vector2
{
public:
	union
	{
		struct
		{
			float x, y;
		};
		float data[2];
	};

	Vector2() : x{ 0 }, y{ 0 } {}
	Vector2(float x, float y) : x{ x }, y{ y } {}
	Vector2(const Vector2& other) : x{ other.x }, y{ other.y } {}

	Vector2& operator = (const Vector2& other);

	Vector2 operator + (const Vector2& other) const;
	Vector2& operator += (const Vector2& other);

	Vector2 operator - (const Vector2& other) const;
	Vector2& operator -= (const Vector2& other);

	Vector2 operator * (float scalar) const;
	friend Vector2 operator * (float scalar, const Vector2& v);
	Vector2& operator *= (float scalar);

	Vector2 operator / (float scalar) const;
	Vector2& operator /= (float scalar);

	float operator [] (int index) const;
	float& operator [] (int index);

	operator float* ();
	operator const float* () const;
	
	float length(const Vector2& other) const;
	float lengthSqr(const Vector2& other) const;

	float magnitude() const;
	float magnitudeSqr() const;

	void normalise();
	Vector2 normalised() const;

	float dot(const Vector2& other) const;
};

class Vector3
{
public:
	union
	{
		struct
		{
			float x, y;
			union
			{
				float z, t;
			};
		};
		float data[3];
	};

	Vector3() : x{ 0 }, y{ 0 }, z{ 0 } {}
	Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}
	Vector3(const Vector2& other) : x{ other.x }, y{ other.y }, z{ 0 } {}
	Vector3(const Vector3& other) : x{ other.x }, y{ other.y }, z{ other.z } {}

	Vector3& operator = (const Vector2& other);
	Vector3& operator = (const Vector3& other);

	Vector3 operator + (const Vector3& other) const;
	Vector3& operator += (const Vector3& other);
	
	Vector3 operator - (const Vector3& other) const;
	Vector3& operator -= (const Vector3& other);

	Vector3 operator * (float scalar) const;
	friend Vector3 operator * (float scalar, const Vector3& v);
	Vector3& operator *= (float scalar);

	Vector3 operator / (float scalar) const;
	Vector3& operator /= (float scalar);

	float operator [] (int index) const;
	float& operator [] (int index);

	operator float* ();
	operator const float* () const;
	
	float length(const Vector3& other) const;
	float lengthSqr(const Vector3& other) const;

	float magnitude() const;
	float magnitudeSqr() const;

	void normalise();
	Vector3 normalised() const;

	float dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;
};

class Vector4
{
public:
	union
	{
		struct
		{
			float x, y, z;
			union
			{
				float w, t;
			};
		};
		float data[4];
	};

	Vector4() : x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 } {}
	Vector4(float x, float y, float z, float w) : x{ x }, y{ y }, z{ z }, w{ w } {}
	Vector4(const Vector3& other) : x{ other.x }, y{ other.y }, z{ other.z }, w{ 0 } {}
	Vector4(const Vector4& other) : x{ other.x }, y{ other.y }, z{ other.z }, w{ other.w } {}

	Vector4& operator = (const Vector3& other);
	Vector4& operator = (const Vector4& other);

	Vector4 operator + (const Vector4& other) const;
	Vector4& operator += (const Vector4& other);

	Vector4 operator - (const Vector4& other) const;
	Vector4& operator -= (const Vector4& other);

	Vector4 operator * (float scalar) const;
	friend Vector4 operator * (float scalar, const Vector4& v);
	Vector4& operator *= (float scalar);

	Vector4 operator / (float scalar) const;
	Vector4& operator /= (float scalar);

	float operator [] (int index) const;
	float& operator [] (int index);

	operator float* ();
	operator const float* () const;

	float length(const Vector4& other) const;
	float lengthSqr(const Vector4& other) const;

	float magnitude() const;
	float magnitudeSqr() const;

	void normalise();
	Vector4 normalised() const;

	float dot(const Vector4& other) const;
	Vector4 cross(const Vector4& other) const;
};

class Matrix2
{
public:
	union
	{
		struct
		{
			Vector2 xAxis, yAxis;
		};
		Vector2 axis[2];
		float data[2][2];
		float floats[4];
	};

	static const Matrix2 identity;

	Matrix2() : xAxis{ 0, 0 }, yAxis{ 0, 0 } {}
	Matrix2(Vector2 xAxis, Vector2 yAxis);
	Matrix2(float XX, float XY, float YX, float YY);
	Matrix2(const Matrix2& other) : xAxis{ other.xAxis }, yAxis{ other.yAxis } {}

	Matrix2& operator = (const Matrix2& other);

	Vector2 operator * (const Vector2& v) const;
	Matrix2 operator * (const Matrix2& other) const;

	Vector2& operator [] (int index);
	const Vector2& operator [] (int index) const;

	operator float* ();
	operator const float* () const;

	Matrix2 transposed() const;

	void setRotate(float radians);
	void rotate(float radians);

	void setScaled(float x, float y);
	void setScaled(const Vector2& v);
	void scale(float x, float y);
	void scale(const Vector2& v);
};

class Matrix3
{
public:
	union
	{
		struct
		{
			Vector3 xAxis, yAxis;
			union
			{
				Vector3 zAxis, translation;
			};
		};
		Vector3 axis[3];
		float data[3][3];
		float floats[9];
	};

	static const Matrix3 identity;

	Matrix3() : xAxis{ 0, 0, 0 }, yAxis{ 0, 0, 0 }, zAxis{ 0, 0, 0 } {}
	Matrix3(Vector3 xAxis, Vector3 yAxis, Vector3 zAxis);
	Matrix3(float XX, float XY, float XZ,
		float YX, float YY, float YZ,
		float ZX, float ZY, float ZZ);
	Matrix3(const Matrix3& other);

	Matrix3& operator = (const Matrix3& other);

	Vector3 operator * (const Vector3& v) const;
	Matrix3 operator * (const Matrix3& other) const;
	
	Vector3& operator [] (int index);
	const Vector3& operator [] (int index) const;

	operator float* ();
	operator const float* () const;

	Matrix3 transposed() const;

	void translate(float x, float y);
	void translate(const Vector3& v);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);
	void rotate(float pitch, float yaw, float roll);

	void setScaled(float x, float y, float z);
	void setScaled(const Vector3& v);

	void scale(float x, float y, float z);
	void scale(const Vector3& v);
};

class Matrix4
{
public:
	union
	{
		struct
		{
			Vector4 xAxis, yAxis, zAxis, translation;
		};
		Vector4 axis[4];
		float data[4][4];
		float floats[16];
	};

	static const Matrix4 identity;

	Matrix4();
	Matrix4(Vector4 xAxis, Vector4 yAxis, Vector4 zAxis, Vector4 translation);
	Matrix4(float XX, float XY, float XZ, float XW, float YX, float YY, float YZ, float YW,
		float ZX, float ZY, float ZZ, float ZW, float TX, float TY, float TZ, float TW);
	Matrix4(const Matrix4& other);

	Matrix4& operator = (const Matrix4& other);

	Vector4 operator * (const Vector4& v) const;
	Matrix4 operator * (const Matrix4& other) const;

	Vector4& operator [] (int index);
	const Vector4& operator [] (int index) const;

	operator float* ();
	operator const float* () const;

	Matrix4 transposed() const;

	void translate(float x, float y, float z);
	void translate(const Vector4& v);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);
	void rotate(float pitch, float yaw, float roll);

	void setScaled(float x, float y, float z);
	void setScaled(const Vector4& v);

	void scale(float x, float y, float z);
	void scale(const Vector4& v);
};