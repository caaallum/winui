#include <winui/stdafx.h>
#include <winui/components/component.h>
#include <winui/components/checkbox.h>

winui::CheckBox::CheckBox() :
	Component({ 50, 50 }, { 0, 0 }) {

}

winui::CheckBox::CheckBox(util::Vector2i size, util::Vector2i position) :
	Component(size, position) {

}

bool 
winui::CheckBox::GetState() const {
	return SendMessage(m_hwnd, BM_GETCHECK, 0, 0) == BST_CHECKED;
}

void
winui::CheckBox::SetState(bool state) {
	SendMessage(m_hwnd, BM_SETCHECK, state ? BST_CHECKED : BST_UNCHECKED, 0);
}

void
winui::CheckBox::Draw(HWND hwndWindow) {
	m_hwnd = CreateWindow(
		"",
		NULL,
		WS_VISIBLE | WS_TABSTOP | WS_CHILD | BS_CHECKBOX,
		m_position.x, m_position.y,
		m_size.x, m_size.y,
		hwndWindow,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}