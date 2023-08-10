#ifndef __FRAME_H
#define __FRAME_H

namespace winui {
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    class WINUI_API Frame {
    public:
        Frame(HINSTANCE instance, const std::string &title, util::Vector2i size);

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

#endif /* __FRAME_H */