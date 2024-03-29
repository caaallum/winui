/**********************************************************
 * This file is part of winui.
 *
 * winui is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License
 * as published by the Free SoftwareFoundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * winui is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with winui. If not, see <https://www.gnu.org/licenses/>.
 **********************************************************/

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

		friend Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
		}

		friend Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
		}

		friend Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			return Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
		}

		friend Vector2<T> operator/(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			return Vector2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
		}

		friend Vector2<T> operator+=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			lhs.x += rhs.x;
			lhs.y += rhs.y;

			return lhs;
		}

		friend Vector2<T> operator-=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;

			return lhs;
		}

		friend Vector2<T> operator*=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			lhs.x *= rhs.x;
			lhs.y *= rhs.y;

			return lhs;
		}

		friend Vector2<T> operator/=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
			lhs.x /= rhs.x;
			lhs.y /= rhs.y;

			return lhs;
		}
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2u;
	typedef Vector2<double> Vector2d;
	typedef Vector2<float> Vector2f;
}

#endif /* __VECTOR2_H */