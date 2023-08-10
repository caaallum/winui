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