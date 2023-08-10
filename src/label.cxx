#include <winui/stdafx.h>
#include <winui/components/component.h>
#include <winui/components/label.h>

winui::Label::Label(const std::string& text) :
	m_text(text),
	Component({ 100, 20 }, { 0, 0 }) {

}

winui::Label::Label(const std::string& text, util::Vector2i size, util::Vector2i position) :
	m_text(text),
	Component(size, position) {
}

void
winui::Label::Draw(HWND hwndFrame) {
	m_hwnd = CreateWindow(
		"LABEL",
		m_text.c_str(),
		WS_VISIBLE | WS_CHILD,
		m_position.x, m_position.y, 
		m_size.x, m_size.y,
		hwndFrame,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}