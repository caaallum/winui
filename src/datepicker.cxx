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
#include <winui/components/datepicker.h>
#include <CommCtrl.h>

winui::DatePicker::DatePicker() :
	Component({ 20, 50 }, { 0,0 }) {

}

winui::DatePicker::DatePicker(util::Vector2i size, util::Vector2i position) :
	Component(size, position) {

}

INT_PTR Dlgproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return FALSE;
}

void
winui::DatePicker::Draw(HWND hwndWindow) {
	if (!InitControl(ICC_DATE_CLASSES)) {
		OUTPUT_LAST_ERROR
	}

	m_hwndDlg = CreateDialog(HINST_THISCOMPONENT, MAKEINTRESOURCE(RT_DIALOG), hwndWindow, Dlgproc);
	if (!m_hwndDlg) {
		OUTPUT_LAST_ERROR
	}

	m_hwnd = CreateWindowEx(0,
		DATETIMEPICK_CLASS,
		TEXT("DateTime"),
		WS_BORDER | WS_CHILD | WS_VISIBLE | DTS_SHOWNONE,
		m_position.x, m_position.y,
		m_size.x, m_size.y,
		m_hwndDlg,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);
	if (!m_hwnd) {
		OUTPUT_LAST_ERROR
	}

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}