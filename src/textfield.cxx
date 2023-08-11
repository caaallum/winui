#include <winui/stdafx.h>
#include <winui/components/component.h>
#include <winui/components/textfield.h>

winui::TextField::TextField() :
	Component({ 100, 20 }, { 0, 0 }) {

}

winui::TextField::TextField(util::Vector2i size, util::Vector2i position) :
	Component(size, position) {
}

std::string 
winui::TextField::GetValue() const {
	if (!m_hwnd) {
		return {};
	}

	DWORD length = GetWindowTextLength(m_hwnd) + 1;

	std::string str(length, 0);
	GetWindowText(m_hwnd, &str[0], length);

	return str;
}


void
winui::TextField::Draw(HWND hwndFrame) {
	m_hwnd = CreateWindow(
		"EDIT",
		NULL,
		WS_VISIBLE | WS_BORDER | WS_CHILD | WS_TABSTOP,
		m_position.x, m_position.y,
		m_size.x, m_size.y,
		hwndFrame,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	SetWindowLongPtr(hwndFrame, GWLP_USERDATA, (LONG_PTR)this);
}