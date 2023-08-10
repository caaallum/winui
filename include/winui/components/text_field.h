#ifndef __TEXT_FIELD_H
#define __TEXT_FIELD_H

namespace winui {
	class WINUI_API TextField : public Component {
	public:
		TextField();

		TextField(util::Vector2i size, util::Vector2i position);

		void Draw(HWND hwndFrame) override;
	};
}

#endif /* __TEXT_FIELD_H */