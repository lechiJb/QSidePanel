#include "PanelTopSide.hpp"

#include "side_panel_helpers.hpp"

PanelTopSide::PanelTopSide(QWidget *parent)
    : SidePanel(parent)
{
    this->_button_text_opening = "^^^";
    this->_button_text_opened = "^^^";
    this->_button_text_closing = "vvv";
    this->_button_text_closed = "vvv";

    this->_button_x = 120;
    this->_button_y = 60;
    
    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_top(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_top(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_bottom_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = [this]() -> QSize
    {
        return {_button_x, _button_y};
    };

    this->updateHandler = [this](const SidePanelState state, HandlerWidgetT* handler)
    {
        switch (state) {
        case SidePanelState::Opening: { handler->setText(_button_text_opening); } break;
        case SidePanelState::Opened:  { handler->setText(_button_text_opened); } break;
        case SidePanelState::Closing: { handler->setText(_button_text_closing); } break;
        case SidePanelState::Closed:  { handler->setText(_button_text_closed); } break;
        default: break;
        }
    };

}

PanelTopSide::~PanelTopSide()
{

}
