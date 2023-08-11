#include <winui/stdafx.h>
#include <winui/components/component.h>
#include <winui/components/combobox.h>
#include <CommCtrl.h>

winui::ComboBox::ComboBox() :
	Component({ 200, 200 }, { 0, 0 }) {

}

winui::ComboBox::ComboBox(util::Vector2i size, util::Vector2i position) :
	Component(size, position) {

}

std::string
winui::ComboBox::GetSelectedValue() const {
	if (!m_hwnd) {
		return {};
	}

	int bytes = SendMessage(m_hwnd, CB_GETLBTEXTLEN, 0, 0);
	
	std::string value(bytes, 0);
	SendMessage((HWND)m_hwnd, (UINT)CB_GETLBTEXT, (WPARAM)GetSelectedIndex(), (LPARAM)&value[0]);

	return value;
}

int
winui::ComboBox::GetSelectedIndex() const {
	if (!m_hwnd) {
		return {};
	}

	return SendMessage((HWND)m_hwnd, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
}

void
winui::ComboBox::RemoveOption(int index) {
	if (!m_hwnd) {
		return;
	}

	SendMessage(m_hwnd, CB_DELETESTRING, index, 0);
}

void
winui::ComboBox::RemoveAllOptions() {
	if (!m_hwnd) {
		return;
	}

	SendMessage(m_hwnd, CB_RESETCONTENT, 0, 0);
}

void
winui::ComboBox::AddOption(const std::string& option) {
	if (!m_hwnd) {
		return;
	}

	SendMessage(m_hwnd, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)option.c_str());
}

void
winui::ComboBox::AddOptions(const std::vector<std::string>& options) {
	if (!m_hwnd) {
		return;
	}

	for (const auto& option : options) {
		AddOption(option);
	}
}

void
winui::ComboBox::Draw(HWND hwndWindow) {
	m_hwnd = CreateWindow(
		WC_COMBOBOX,
		"",
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
		m_position.x, m_position.y,
		m_size.x, m_size.y,
		hwndWindow,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}