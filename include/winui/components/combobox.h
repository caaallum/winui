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

#ifndef __COMBOBOX_H
#define __COMBOBOX_H

namespace winui {
	class WINUI_API ComboBox : public Component {
	public:
		ComboBox();

		ComboBox(util::Vector2i size, util::Vector2i position);

		std::string GetSelectedValue() const;

		int GetSelectedIndex() const;

		void SetSelectedIndex(int index);

		void SetSelectedItem(const std::string& item);

		void RemoveOption(int index);

		void RemoveAllOptions();

		void AddOption(const std::string& option);

		void AddOptions(const std::vector<std::string>& options);

		void Draw(HWND hwndWindow) override;
	};
}

#endif /* __COMBOBOX_H */