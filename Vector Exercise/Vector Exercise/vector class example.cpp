#include <iostream>
#include <math.h>
class Vector2d
{
	float m_x = 0.0f; 
	float m_y = 0.0f;
	
public:
	Vector2d(float x1, float y1)
		: m_x(x1), m_y(y1) {}

	Vector2d Add(Vector2d B) 
	{ 
	Vector2d newVec = Vector2d(m_x + B.m_x, m_y + B.m_y);
	return newVec;
	};

	Vector2d Subtract(Vector2d B) 
	{
		Vector2d newVec = Vector2d(m_x - B.m_x, m_y - B.m_y);
		return newVec;
	};

	Vector2d ScalerMult(float k)
	{
		Vector2d newVec = Vector2d(m_x * k, m_y * k);
		return newVec;
	};

	float Magnitude()
	{
		float result = sqrt(m_x * m_x + m_y * m_y);
		return result;
	}
	Vector2d Normalize()
	{
		// alternate
		/*float x = sqrt(m_x + m_y);
		float A = x;						
		float B = x;						
		A = A * (m_x / A);					
		B = B * (m_y / B);
		m_x = B;
		m_y = A;*/
		Vector2d newVec = Vector2d(m_x / Magnitude(), m_y / Magnitude());
		return newVec;
	}
	float DotProduct(Vector2d B)
	{
		return (m_x*B.m_x) + (m_y * B.m_y);
	}
};

class Vector3d
{
	float m_x = 0.0f;
	float m_y = 0.0f;
	float m_z = 0.0f;
public:
	Vector3d(float x1, float y1, float z1)
		: m_x(x1), m_y(y1), m_z(z1) {}

	Vector3d Add(Vector3d B)
	{
		Vector3d newVec = Vector3d(m_x + B.m_x, m_y + B.m_y, m_z + B.m_z);
		return newVec;
	};


	Vector3d Subtract(Vector3d B)
	{
		Vector3d newVec = Vector3d(m_x - B.m_x, m_y - B.m_y, m_z - B.m_z);
		return newVec;
	};

	Vector3d ScalerMult(float k)
	{
		Vector3d newVec = Vector3d(m_x * k, m_y * k, m_z * k);
		return newVec;
	};

	float Magnitude()
	{
		float result = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
		return result;
	};

	Vector3d Normalize()
		{
			Vector3d newVec = Vector3d(m_x / Magnitude(), m_y / Magnitude(), m_z / Magnitude());
			return newVec;
		};

	float DotProduct(Vector3d B)
	{
		return (m_x*B.m_x) + (m_y * B.m_y) + (m_z * B.m_z);
	}
	Vector3d CrossProduct(Vector3d B)
	{
		Vector3d newVec = Vector3d(m_x*B.m_z - m_z*B.m_y, m_x*B.m_z - m_z*B.m_x, m_x*B.m_y - m_y*B.m_x);
		return newVec;
	}
};
int main()
{
	Vector2d* A2d = new Vector2d(0, 1);
	Vector2d B2d = Vector2d(1, 0);
	A2d->Add(B2d);
	A2d->Subtract(B2d);
	A2d->ScalerMult(2);
	A2d->Magnitude();
	A2d->Normalize();
	A2d->DotProduct(B2d);
	
	Vector3d* A3d = new Vector3d(1, 0, 0);
	Vector3d B3d = Vector3d(0, 1, 1);
	A3d->Add(B3d);
	A3d->Subtract(B3d);
	A3d->ScalerMult(2);
	A3d->Magnitude();
	A3d->Normalize();
	A3d->DotProduct(B3d);
	A3d->CrossProduct(B3d);
}