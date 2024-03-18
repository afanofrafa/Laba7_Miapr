// TreeNodeWidget.cpp
#include "TreeNodeWidget.h"
#include <QPainter>

TreeNodeWidget::TreeNodeWidget(QWidget *parent) : QWidget(parent) {}

void TreeNodeWidget::setText(const QString &text)
{
    m_text = text;
    update();
}

void TreeNodeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawText(rect(), Qt::AlignCenter, m_text);
}
