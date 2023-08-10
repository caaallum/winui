#ifndef __VECTOR2_H
#define __VECTOR2_H

namespace winui::util {
	template <typename T>
	class Vector2 {
	public:
		T x;
		T y;

	public:
		explicit Vector2() : x(0), y(0) {}

		Vector2(T x, T y) : x(x), y(y) {}

		template <typename U>
		Vector2(U x, U y) : x(static_cast<T>(x)), y(static_cast<T>(x)) {}
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2u;
	typedef Vector2<double> Vector2d;
	typedef Vector2<float> Vector2f;
}

#endif /* __VECTOR2_H */