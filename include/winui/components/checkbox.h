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

#ifndef __CHECK_BOX_H
#define __CHECK_BOX_H

namespace winui {
	class WINUI_API CheckBox : public Component {
	public:
		CheckBox();

		CheckBox(util::Vector2i size, util::Vector2i position);

		bool GetState() const;

		void SetState(bool state);

		void Draw(HWND hwndWindow) override;
	};
}

#endif /* __CHECK_BOX_H */