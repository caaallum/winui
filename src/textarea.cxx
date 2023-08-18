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
#include <winui/components/textarea.h>

winui::TextArea::TextArea() :
	Component({ 100, 100 }, { 0, 0 }) {

}

winui::TextArea::TextArea(util::Vector2i size, util::Vector2i position) :
	Component(size, position) {

}

void
winui::TextArea::SetValue(const std::string& value) {
	if (!m_hwnd) {
		return;
	}

	SetWindowText(m_hwnd, value.c_str());
}

std::string
winui::TextArea::GetValue() const {
	if (!m_hwnd) {
		return {};
	}

	DWORD length = GetWindowTextLength(m_hwnd) + 1;

	std::string str(length, 0);
	GetWindowText(m_hwnd, &str[0], length);

	return str;
}

void
winui::TextArea::Clear() {
	if (!m_hwnd) {
		return;
	}

	SetValue("");
}

void
winui::TextArea::Draw(HWND hwndWindow) {
	m_hwnd = CreateWindow(
		"",
		NULL,
		WS_VISIBLE | WS_BORDER | WS_CHILD | WS_TABSTOP |
		ES_LEFT | ES_AUTOVSCROLL | ES_AUTOHSCROLL |
		ES_MULTILINE | WS_VSCROLL | WS_HSCROLL,
		m_position.x, m_position.y,
		m_size.x, m_size.y,
		hwndWindow,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}