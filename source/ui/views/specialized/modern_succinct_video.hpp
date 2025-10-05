#pragma once
#include "ui/views/specialized/succinct_video.hpp"

struct ModernSuccinctVideoView : public SuccinctVideoView {
    ModernSuccinctVideoView(double x0, double y0, double width, double height)
        : SuccinctVideoView(x0, y0, width, height) {}

    void draw_() const override;
};