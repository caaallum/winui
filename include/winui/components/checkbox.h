#ifndef __CHECK_BOX_H
#define __CHECK_BOX_H

namespace winui {
	class WINUI_API CheckBox : public Component {
	public:
		CheckBox();

		CheckBox(util::Vector2i size, util::Vector2i position);

		bool GetState() const;

		void SetState(bool state);

		void Draw(HWND hwndWindow) override;
	};
}

#endif /* __CHECK_BOX_H */