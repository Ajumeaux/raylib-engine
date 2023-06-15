/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-felix.guitton
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "./BaseRaylib.hpp"

using namespace OriginalRaylib;

namespace Raylib
{
    class Text
    {
    public:
        // default constructor
        Text(const std::string &ntext)
        {
            text = ntext;
            fontSize = 1;
            color = WHITE;
            font = ::GetFontDefault();
            spacing = 20;
            position = {0, 0};
            active = true;
        }
        Text(const std::string &ntext, float nfontSize)
        {
            text = ntext;
            fontSize = nfontSize;
            color = WHITE;
            font = ::GetFontDefault();
            spacing = 20;
            position = {0, 0};
            active = true;
        }
        Text(const std::string &ntext, float nfontSize, const ::Color &ncolor)
        {
            text = ntext;
            fontSize = nfontSize;
            color = ncolor;
            font = ::GetFontDefault();
            spacing = 20;
            position = {0, 0};
            active = true;
        }
        Text(const std::string &ntext, float nfontSize, const ::Color &ncolor, const std::string fontpath, Raylib::Vector2 nposition)
        {
            text = ntext;
            fontSize = nfontSize;
            color = ncolor;
            font = ::LoadFont(fontpath.c_str());
            spacing = 20;
            position = nposition;
            active = true;
        }
        Text(const std::string &ntext, float nfontSize, const ::Color &ncolor, const std::string fontpath, Raylib::Vector2 nposition, float nspacing)
        {
            text = ntext;
            fontSize = nfontSize;
            color = ncolor;
            font = ::LoadFont(fontpath.c_str());
            spacing = nspacing;
            position = nposition;
            active = true;
        }
        inline void draw(int posX, int posY)
        {
            if (active)
                ::DrawTextEx(font, text.c_str(), {static_cast<float>(posX), static_cast<float>(posY)}, fontSize, spacing, color);
        }
        inline void draw()
        {
            if (active)
                ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
        }
        inline void draw(const Raylib::Vector2 &nposition)
        {
            if (active)
                ::DrawTextEx(font, text.c_str(), nposition, fontSize, spacing, color);
        }
        inline void draw(const Raylib::Vector2 &nposition, const Raylib::Vector2 scale, float rotation)
        {
            if (active)
                ::DrawTextEx(font, text.c_str(), nposition, fontSize, spacing, color);
        }
        inline void unload()
        {
            ::UnloadFont(font);
        }
        inline void setFontSize(float nfontSize)
        {
            fontSize = nfontSize;
        }
        inline void setColor(const ::Color &ncolor)
        {
            color = ncolor;
        }
        inline void setFont(const std::string &fontpath)
        {
            font = ::LoadFont(fontpath.c_str());
        }
        inline void setSpacing(float nspacing)
        {
            spacing = nspacing;
        }
        inline void setText(const std::string &ntext)
        {
            text = ntext;
        }
        inline void setPosition(const Raylib::Vector2 &nposition)
        {
            position = nposition;
        }
        inline void setActive(bool nactive)
        {
            active = nactive;
        }
        inline bool isActive() const
        {
            return active;
        }
        inline const std::string &getText() const
        {
            return text;
        }
        inline const int getTextWidth() const
        {
            return (::MeasureText(text.c_str(), fontSize) + spacing * (text.length() - 1));
        }
        std::string text;
        float fontSize;
        ::Color color;
        ::Font font;
        float spacing;
        Raylib::Vector2 position;
        bool active;
    };
}

#endif