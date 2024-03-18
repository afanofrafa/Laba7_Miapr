#ifndef TREENODEWIDGET_H
#define TREENODEWIDGET_H

#include <QWidget>

class TreeNodeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeNodeWidget(QWidget *parent = nullptr);
    void setText(const QString &text);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString m_text;
};

#endif // TREENODEWIDGET_H


