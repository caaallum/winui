#ifndef __TEXTFIELD_H
#define __TEXTFIELD_H

namespace winui {
	class WINUI_API TextField : public Component {
	public:
		TextField();

		TextField(util::Vector2i size, util::Vector2i position);

		void SetValue(const std::string& value);

		std::string GetValue() const;

		void Clear();

		void Draw(HWND hwndFrame) override;
	};
}

#endif /* __TEXTFIELD_H */