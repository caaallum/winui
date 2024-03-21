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
#include <winui/components/label.h>i

winui::Label::Label() :
	m_text(""),
	Component({ 100, 20 }, { 0,0 }) {

}

winui::Label::Label(const std::string& text) :
	m_text(text),
	Component({ 100, 20 }, { 0, 0 }) {

}

winui::Label::Label(const std::string& text, util::Vector2i size, util::Vector2i position) :
	m_text(text),
	Component(size, position) {
}

void
winui::Label::Draw(HWND hwndWindow) {
	m_hwnd = CreateWindow(
		"STATIC",
		m_text.c_str(),
		WS_VISIBLE | WS_CHILD,
		m_position.x, m_position.y, 
		m_size.x, m_size.y,
		hwndWindow,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	OUTPUT_LAST_ERROR

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}

void
winui::Label::SetText(const std::string& text) {
	m_text = text;

	SetWindowText(m_hwnd, m_text.c_str());
}

std::string
winui::Label::GetText() const {
	return m_text;
}