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

#ifndef __BUTTON_H 
#define __BUTTON_H

namespace winui {
	class WINUI_API Button : public Component {
	public:
		Button();

		Button(const std::string &title);

		Button(const std::string &title, util::Vector2i size, util::Vector2i position);

		void SetTitle(const std::string &title);

		std::string GetTitle() const;

		void Draw(HWND hwndFrame) override;

	private:
		std::string m_title;
	};
}

#endif /* __BUTTON_H */