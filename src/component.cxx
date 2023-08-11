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

#include <winui/stdafx.h>
#include <winui/components/component.h>

winui::Component::Component(util::Vector2i size, util::Vector2i position) :
	m_size(size),
	m_position(position),
	m_event_listener(NULL),
	m_hwnd(NULL) {

}

void
winui::Component::SetPosition(util::Vector2i position) {
	if (!m_hwnd) {
		return;
	}

	RECT rect;
	GetWindowRect(m_hwnd, &rect);
	m_position.x = rect.right - rect.left;
	m_position.y = rect.bottom - rect.top;

	SetWindowPos(m_hwnd, NULL, m_size.x, m_size.y, m_position.x, m_position.y, 0);
}

void
winui::Component::SetSize(util::Vector2i size) {
	if (!m_hwnd) {
		return;
	}

	RECT rect;
	GetWindowRect(m_hwnd, &rect);
	m_size.x = rect.left;
	m_size.y = rect.top;
	SetWindowPos(m_hwnd, NULL, m_size.x, m_size.y, m_position.x, m_position.y, 0);
}

winui::util::Vector2i
winui::Component::GetPosition() const {
	return m_position;
}

winui::util::Vector2i
winui::Component::GetSize() const {
	return m_size;
}

void
winui::Component::AddEventListener(void (*event)()) {
	m_event_listener = event;
}