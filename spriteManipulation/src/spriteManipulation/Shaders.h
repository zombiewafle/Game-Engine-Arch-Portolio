#include "Game/Graphics/PixelShader.h"

namespace Shaders {

    PixelShader grayscale = {
        [](Uint32 color) -> Uint32 {
            Uint8 r = (color >> 24) & 0xFF;
            Uint8 g = (color >> 16) & 0xFF;
            Uint8 b = (color >> 8) & 0xFF;
            
            Uint8 gray = (r + g + b) / 3;

            return (gray << 24) | (gray << 16) | (gray << 8) | (color & 0xFF);
        },
        "grayscale"
    };

    PixelShader shadow = {
        [](Uint32 color) -> Uint32 {
            Uint8 r = (color >> 24) & 0xFF;
            Uint8 g = (color >> 16) & 0xFF;
            Uint8 b = (color >> 8) & 0xFF;
            Uint8 a = color & 0xFF;

            float factor = 0.9;
            
            r = static_cast<Uint8>(r * factor);
            g = static_cast<Uint8>(g * factor);
            b = static_cast<Uint8>(b * factor);

            return (r << 24) | (g << 16) | (b << 8) | a;
        },
        "shadow"
    };


    PixelShader red = {
        [](Uint32 color) -> Uint32 { 
            return (color == 0xF3F2C0FF) ? 0xD2B48CFF : color ; 
        }, 
        "red"
    };

}
