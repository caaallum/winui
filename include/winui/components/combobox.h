#ifndef __COMBOBOX_H
#define __COMBOBOX_H

namespace winui {
	class WINUI_API ComboBox : public Component {
	public:
		ComboBox();

		ComboBox(util::Vector2i size, util::Vector2i position);

		std::string GetSelectedValue() const;

		int GetSelectedIndex() const;

		void RemoveOption(int index);

		void RemoveAllOptions();

		void AddOption(const std::string& option);

		void AddOptions(const std::vector<std::string>& options);

		void Draw(HWND hwndFrame) override;
	};
}

#endif /* __COMBOBOX_H */