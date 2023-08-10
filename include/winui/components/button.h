#ifndef __BUTTON_H 
#define __BUTTON_H

namespace winui {
	class WINUI_API Button : public Component {
	public:
		Button(const std::string &title);

		Button(const std::string &title, util::Vector2i size, util::Vector2i position);

		void SetTitle(const std::string &title);

		std::string GetTitle() const;

		void Draw(HWND hwndFrame) override;

	private:
		std::string m_title;
	};
}

#endif /* __BUTTON_H */