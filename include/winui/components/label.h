#ifndef __LABEL_H
#define __LABEL_H

namespace winui {
	class WINUI_API Label : public Component {
	public:
		Label(const std::string& text);

		Label(const std::string& text, util::Vector2i size, util::Vector2i position);

		void Draw(HWND hwndFrame) override;

	private:
		std::string m_text;
	};
}

#endif /* __LABEL_H */