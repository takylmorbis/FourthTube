#include "modern_succinct_video.hpp"
#include "ui/draw/draw.hpp"
#include "variables.hpp"

void ModernSuccinctVideoView::draw_() const {
    float thumbnail_width = get_thumbnail_width();
    float thumbnail_height = get_thumbnail_height();

    // Draw a subtle background and border
    Draw_texture(var_square_image[0], (u32)this->get_background_color(*this), x0, y0, x1 - x0, y1 - y0);
    Draw_texture(var_square_image[0], 0xFFE0E0E0, x0, y1 - 1, x1 - x0, 1); // Border

    // Draw thumbnail
    thumbnail_draw(thumbnail_handle, x0 + 5, y0 + 5, thumbnail_width - 10, thumbnail_height - 10);

    // Draw duration overlay
    if (bottom_right_overlay.size()) {
        float overlay_width = Draw_get_width(bottom_right_overlay, 0.4);
        Draw_texture(var_square_image[0], 0xBB000000, x0 + thumbnail_width - overlay_width - 7, y0 + thumbnail_height - 17, overlay_width + 4, 12);
        Draw(bottom_right_overlay, x0 + thumbnail_width - overlay_width - 5, y0 + thumbnail_height - 18, 0.4, 0.4, (u32)-1);
    }

    // Draw playlist overlay
    if (is_playlist) {
        Draw_texture(var_square_image[0], 0xA0000000, x0 + 5, y0 + thumbnail_height - 25, thumbnail_width - 10, 20);
        Draw_x_centered("Playlist", x0 + 5, x0 + thumbnail_width - 5, y0 + thumbnail_height - 22, 0.5, 0.5, (u32)-1);
    }

    // Draw title and author
    float text_x = x0 + thumbnail_width + 5;
    float text_y = y0 + 5;
    for (const auto& line : title_lines) {
        Draw(line, text_x, text_y, 0.55, 0.55, DEFAULT_TEXT_COLOR);
        text_y += 16;
    }
    text_y += 2;
    for (const auto& line : auxiliary_lines) {
        Draw(line, text_x, text_y, 0.5, 0.5, LIGHT0_TEXT_COLOR);
        text_y += 14;
    }
}