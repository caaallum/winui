#ifndef __WINDOW_H
#define __WINDOW_H

namespace winui {
    class WINUI_API Window {
    public:
        Window(HINSTANCE instance, const std::string &title, util::Vector2i size);

        void Show();

        HWND GetHandle() const;

    private:
        void InitWindow();

    private:
        std::string m_title;
        HINSTANCE m_instance;
        util::Vector2i m_size;
        WNDCLASSEX m_wc;
        HWND m_hwnd;
    };
}

#endif /* __WINDOW_H */