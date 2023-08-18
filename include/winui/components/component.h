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

#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <winui/util/vector2.h>

namespace winui {
	class WINUI_API Component {
	public:
		Component(util::Vector2i size, util::Vector2i position);

		virtual void Draw(HWND hwndWindow) = 0;

		void SetPosition(util::Vector2i pos);

		void SetSize(util::Vector2i size);

		util::Vector2i GetPosition() const;

		util::Vector2i GetSize() const;

		void AddEventListener(void (*event)());

		void (*m_event_listener)();

	protected:
		BOOL InitControl(DWORD control);

	protected:
		util::Vector2i m_size;
		util::Vector2i m_position;
		HWND m_hwnd;
		HWND m_hwndDlg;
	};
}

#endif /* __COMPONENT_H */