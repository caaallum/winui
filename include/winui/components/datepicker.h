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

#ifndef __DATEPICKER_H
#define __DATEPICKER_H

namespace winui {
	class WINUI_API DatePicker : public Component {
	public:
		DatePicker();

		DatePicker(util::Vector2i size, util::Vector2i position);

		void Draw(HWND hwndWindow) override;
	};
}

#endif /* __DATEPICKER_H */