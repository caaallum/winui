/**********************************************************
 * This file is part of winui.
 *
 * winui is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License
 * as published by the Free SoftwareFoundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * winui is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with winui. If not, see <https://www.gnu.org/licenses/>.
 **********************************************************/

#ifndef __WINDOW_H
#define __WINDOW_H

namespace winui {
    class WINUI_API Window {
    public:
        Window(HINSTANCE instance, const std::string &title, util::Vector2i size);

        void Show();

        HWND GetHandle() const;

        util::Vector2i GetSize() const;

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