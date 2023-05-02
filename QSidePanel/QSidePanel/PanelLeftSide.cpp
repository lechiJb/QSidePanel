#include "PanelLeftSide.hpp"

#include "side_panel_helpers.hpp"

PanelLeftSide::PanelLeftSide(QWidget *parent)
    : SidePanel(parent)
{

    this->_button_text_opening = "<";
    this->_button_text_opened = "<";
    this->_button_text_closing = ">";
    this->_button_text_closed = ">";

    this->_button_x = 120;
    this->_button_y = 60;

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_left(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_left(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_right_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = [this]() -> QSize {
        return {_button_y, _button_x};
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

PanelLeftSide::~PanelLeftSide()
{

}
