#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <winui/util/vector2.h>

namespace winui {
	class WINUI_API Component {
	public:
		Component(util::Vector2i size, util::Vector2i position);

		virtual void Draw(HWND hwndFrame) = 0;

		void SetPosition(util::Vector2i pos);

		void SetSize(util::Vector2i size);

		util::Vector2i GetPosition() const;

		util::Vector2i GetSize() const;

		void AddEventListener(void (*event)());

		void (*m_event_listener)();
	protected:
		util::Vector2i m_size;
		util::Vector2i m_position;
		HWND m_hwnd;
	};
}

#endif /* __COMPONENT_H */