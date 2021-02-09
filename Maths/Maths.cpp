#include <iostream>

namespace maths4games
{
	constexpr double PI{ 3.141592653589793 };
	
	template<class T>
	class Vector2
	{
	public:
		static float DotProduct(const Vector2<T>& x, const Vector2<T>& y)
		{
			return x.GetX() * y.GetX() + x.GetY() * y.GetY();
		}

		static float AngleDeg(Vector2<T>& x, Vector2<T>& y)
		{
			return acos(DotProduct(x, y) / (x.Magnitude() * y.Magnitude())) * (180 / PI);
		}

		static float AngleRad(Vector2<T>& x, Vector2<T>& y)
		{
			return acos(DotProduct(x, y) / (x.Magnitude() * y.Magnitude()));
		}

		Vector2(T x, T y) :
			m_x(x),
			m_y(y)
		{
		}

		T Magnitude()
		{
			return sqrt(pow(m_x, 2) + pow(m_y, 2));
		}

		T SqrMag()
		{
			return pow(m_x, 2) + pow(m_y, 2);
		}

		Vector2<T> Normalise()
		{
			return { m_x / Magnitude(), m_y / Magnitude() };
		}


		void Add(const Vector2<T>& vec)
		{
			m_x += vec.m_x;
			m_y += vec.m_y;
		}

		void Sub(const Vector2<T>& vec)
		{
			m_x = vec.m_x - m_x;
			m_y = vec.m_y - m_y;
		}

		T GetX() const { return m_x; }
		T GetY() const { return m_y; }

	private:
		T m_x;
		T m_y;
	};
}


std::ostream& operator<<(std::ostream& lhs, const maths4games::Vector2<float>& rhs)
{
	lhs << rhs.GetX() << " " << rhs.GetY();
	return lhs;
}

int main()
{
	maths4games::Vector2<float> v1{ 13, 10 };
	maths4games::Vector2<float> v2{ 3, 4 };

	std::cout << maths4games::Vector2<float>::AngleDeg(v1, v2) << std::endl;
	/*v1.Sub(v2);
	std::cout << v1 << std::endl;

	std::cout << v1.Normalise() << std::endl;*/

}