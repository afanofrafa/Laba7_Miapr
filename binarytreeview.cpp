#include "BinaryTreeView.h"
#include "TreeNodeWidget.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
using namespace std;
map<vector<QString>, QString> BinaryTreeView::get_grammar_map() {
    return grammar_map;
}
map<int, vector<QString>> BinaryTreeView::get_index_map() {
    return index_map;
}
void BinaryTreeView::drawFigure(QPainter &painter, const vector<double>& xValues, const vector<double>& yValues, double x, double y, bool b, bool fl) {
    vector<double> coefficients(yValues.size());
    if (fl)
        coefficients = lagrangeCoefficients(xValues, yValues);
    else
        coefficients = lagrangeCoefficients(yValues, xValues);
    for (size_t i = 0; i < 100; i++) {
        double x1 = i;
        double x2 = i + 1;
        double y1;
        double y2;
        if (fl) {
            y1 = lagrangeInterpolation(x1, xValues, coefficients);
            y2 = lagrangeInterpolation(x2, xValues, coefficients);
            if (b)
                m_scene->addLine(x1 + x, y1 + y, x2 + x, y2 + y);
            painter.drawLine(x1 + x, y1 + y, x2+ x, y2 + y);
        }
        else {
            y1 = lagrangeInterpolation(x1, yValues, coefficients);
            y2 = lagrangeInterpolation(x2, yValues, coefficients);
            if (b)
                m_scene->addLine(y1 + x, x1 + y, y2 + x, x2 + y);
            painter.drawLine(y1 + x, x1 + y, y2 + x, x2 + y);
        }
    }
}
bool BinaryTreeView::checkLastEightPoints(const std::vector<QPoint>& points, const QPoint point) {
    int size;
    if (points.size() < 20)
        size = points.size();
    else
        size = 20;
    for (int i = points.size() - size; i < points.size(); ++i) {
        if (points[i] == point) {
            return true;
        }
    }

    return false;
}
QPoint BinaryTreeView::drawPicture1(bool b) {
    scene()->clear();
    m_scene->clear();
    pixmap.fill(Qt::white);
    painter.begin(&pixmap);
    painter.setPen(Qt::black);
    drawFigure(painter, xValuesB3, yValuesB3, 100.0, 100.0, b, true);
    drawFigure(painter, xValuesA1, yValuesA1, 200.0, 0.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 300.0, 100.0, b, true);
    drawFigure(painter, xValuesC4, yValuesC4, 400.0, 200.0, b, true);
    drawFigure(painter, xValuesB3, yValuesB3, 500.0, 100.0, b, true);
    drawFigure(painter, xValuesA1, yValuesA1, 600.0, 0.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 700.0, 100.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 800.0, 200.0, b, true);
    drawFigure(painter, xValuesD1, yValuesD1, 800.0, 300.0, b, false);
    drawFigure(painter, xValuesB2, yValuesB2, 800.0, 400.0, b, true);
    drawFigure(painter, xValuesB2, yValuesB2, 700.0, 500.0, b, true);
    drawFigure(painter, xValuesA4, yValuesA4, 600.0, 600.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 500.0, 500.0, b, true);
    drawFigure(painter, xValuesC1, yValuesC1, 400.0, 400.0, b, true);
    drawFigure(painter, xValuesB2, yValuesB2, 300.0, 500.0, b, true);
    drawFigure(painter, xValuesA4, yValuesA4, 200.0, 600.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 100.0, 500.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 0.0, 400.0, b, true);
    drawFigure(painter, xValuesD2, yValuesD2, 0.0, 300.0, b, false);
    drawFigure(painter, xValuesB3, yValuesB3, 0.0, 200.0, b, true);
    painter.end();
    return {0, 900};
}
QPoint BinaryTreeView::drawPicture2(bool b) {
    scene()->clear();
    m_scene->clear();
    pixmap.fill(Qt::white);
    painter.begin(&pixmap);
    painter.setPen(Qt::black);
    drawFigure(painter, xValuesB3, yValuesB3, 100.0, 100.0, b, true);
    drawFigure(painter, xValuesA1, yValuesA1, 200.0, 0.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 300.0, 100.0, b, true);
    drawFigure(painter, xValuesC4, yValuesC4, 400.0, 200.0, b, true);
    drawFigure(painter, xValuesB3, yValuesB3, 500.0, 100.0, b, true);
    drawFigure(painter, xValuesA1, yValuesA1, 600.0, 0.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 700.0, 100.0, b, true);
    drawFigure(painter, {0, 100, 200, 100}, {0, 33, 66, 100}, 800.0, 200.0, b, false);
    drawFigure(painter, xValuesD1, yValuesD1, 800.0, 300.0, b, false);
    drawFigure(painter, xValuesB2, yValuesB2, 800.0, 400.0, b, true);
    drawFigure(painter, xValuesB2, yValuesB2, 700.0, 500.0, b, true);
    drawFigure(painter, xValuesA4, yValuesA4, 600.0, 600.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 500.0, 500.0, b, true);
    drawFigure(painter, xValuesC1, yValuesC1, 400.0, 400.0, b, true);
    drawFigure(painter, xValuesB2, yValuesB2, 300.0, 500.0, b, true);
    drawFigure(painter, xValuesA4, yValuesA4, 200.0, 600.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 100.0, 500.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 0.0, 400.0, b, true);
    drawFigure(painter, xValuesD2, yValuesD2, 0.0, 300.0, b, false);
    drawFigure(painter, xValuesB3, yValuesB3, 0.0, 200.0, b, true);
    painter.end();
    return {0, 900};
}
QPoint BinaryTreeView::drawPicture3(bool b) {
    scene()->clear();
    m_scene->clear();
    pixmap.fill(Qt::white);
    painter.begin(&pixmap);
    painter.setPen(Qt::black);
    drawFigure(painter, xValuesE1, yValuesE1, 200.0, 0.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 300.0, 100.0, b, true);
    drawFigure(painter, xValuesB1, yValuesB1, 400.0, 200.0, b, true);
    drawFigure(painter, xValuesA4, yValuesA4, 400.0, 300.0, b, true);
    drawFigure(painter, xValuesB4, yValuesB4, 300.0, 200.0, b, true);
    drawFigure(painter, xValuesC1, yValuesC1, 200.0, 100.0, b, true);
    drawFigure(painter, xValuesB2, yValuesB2, 100.0, 200.0, b, true);
    drawFigure(painter, xValuesA4, yValuesA4, 0.0, 300.0, b, true);
    drawFigure(painter, xValuesB3, yValuesB3, 0.0, 200.0, b, true);
    drawFigure(painter, xValuesB3, yValuesB3, 100.0, 100.0, b, true);
    painter.end();
    return {0, 900};
}
vector<double> BinaryTreeView::lagrangeCoefficients(const vector<double>& xValues, const vector<double>& yValues) {
    vector<double> coefficients(yValues.size());
    for (size_t i = 0; i < yValues.size(); i++) {
        double term = yValues[i];
        for (size_t j = 0; j < yValues.size(); j++) {
            if (j != i) {
                term /= (xValues[i] - xValues[j]);
            }
        }
        coefficients[i] = term;
    }
    return coefficients;
}

double BinaryTreeView::lagrangeInterpolation(double x, const vector<double>& xValues, vector<double>& coefficients) {
    double result = 0.0;
    for (size_t i = 0; i < xValues.size(); i++) {
        double term = coefficients[i];
        for (size_t j = 0; j < xValues.size(); j++) {
            if (j != i) {
                term *= (x - xValues[j]);
            }
        }
        result += term;
    }
    return result;
}
// Функция для вычисления среднего значения
double mean(const vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Функция для вычисления среднеквадратического отклонения
double standardDeviation(const vector<double>& data) {
    double meanValue = mean(data);
    double sumSquaredDiff = 0.0;

    for (double value : data) {
        double diff = value - meanValue;
        sumSquaredDiff += diff * diff;
    }

    double meanSquaredDiff = sumSquaredDiff / data.size();
    return sqrt(meanSquaredDiff);
}
double findDist(double x_fr, double y_fr, double x_to, double y_to) {
    return sqrt(pow(x_fr - x_to, 2) + pow(y_fr - y_to, 2));
}
int BinaryTreeView::get_terminal(const vector<QPoint> &points, QPoint p_fr, QPoint p_bck, int nx, int ny) {
    vector<Data> v_dat = map_points[{p_fr.x(), p_fr.y(), p_bck.x(), p_bck.y()}];
    vector<double> err(v_dat.size());
    vector<double> coefficients;
    vector<QPoint> ps;
    for (int i = 0; i < points.size(); ) {
        double x = points[i].x();
        double y = points[i].y();
        int j = i + 1;
        while (j < points.size() && x == points[j].x()) {
            y += points[j].y();
            j++;
        }
        j = j - i;
        y /= j;
        QPoint p;
        p.setX(x);
        p.setY(y);
        ps.push_back(p);
        i += j;
    }
    for (int i = 0; i < ps.size(); i++) {
        double x = ps[i].x();
        double y = ps[i].y();
        int j = i + 1;
        while (j < ps.size() && y == ps[j].y()) {
            x += ps[j].x();
            j++;
        }
        j = j - i;
        x /= j;
        ps[i].setX(x);
        ps.erase(ps.begin() + i + 1,ps.begin() + i + j);
    }
    vector<double> errors(ps.size());
    for (int i = 0; i < v_dat.size(); i++) {
        if (v_dat[i].fl)
            coefficients = lagrangeCoefficients(v_dat[i].xValues, v_dat[i].yValues);
        else
            coefficients = lagrangeCoefficients(v_dat[i].yValues, v_dat[i].xValues);
        for (int j = 0; j < ps.size(); j++) {
            if (ps[j].x() == 1000) {
                int yy = 0;
            }
            if (v_dat[i].fl)
                errors[j] = abs(ps[j].y() - lagrangeInterpolation(ps[j].x() - 100 * nx, v_dat[i].xValues, coefficients));
            else
                errors[j] = abs(ps[j].x() - lagrangeInterpolation(ps[j].y() - 100 * ny, v_dat[i].yValues, coefficients));
        }
        err[i] = standardDeviation(errors);
    }
    double min = 10E20;
    int ind = -1;
    for (int i = 0; i < err.size(); i++) {
        if (min > err[i]) {
            min = err[i];
            ind = i;
        }
    }
    if (min < 3.0)
        return map_terms[v_dat[ind]];
    else
        return -1;
}
int BinaryTreeView::checkAndPushOne(const bool b, int x, int y, vector<QPoint> &vec_add, vector<QPoint> &points) {
    QColor pixelColor;
    if (b) {
        pixelColor = pixmap.toImage().pixelColor(x, y);
        if (pixelColor == Qt::black) {
            if (!checkLastEightPoints(points, {x, y})) {
                vec_add.push_back(QPoint(x, y));
                return 1;
            }
        }
    }
    return 0;
}
vector<int> BinaryTreeView::runAnalysis(const QPoint sz_xy) {
    scene()->clear();
    vector<int> res;
    vector<QPoint> points;
    int w = pixmap.width();
    int h = pixmap.height();
    bool fl = true;
    vector<QPoint> pair;
    for (int y = 0; y < h && fl; y += 100) {
        for (int x = 0; x < w && fl; x += 100) {
            QColor pixelColor = pixmap.toImage().pixelColor(x, y);
            if (pixelColor == Qt::black) {
                pair.push_back({x, y});
            }
            pixelColor = pixmap.toImage().pixelColor(x + 100, y);
            if (pixelColor == Qt::black) {
                pair.push_back({x + 100, y});
            }
            pixelColor = pixmap.toImage().pixelColor(x, y + 100);
            if (pixelColor == Qt::black) {
                pair.push_back({x, y + 100});
            }
            pixelColor = pixmap.toImage().pixelColor(x + 100, y + 100);
            if (pixelColor == Qt::black) {
                pair.push_back({x + 100, y + 100});
            }
            if (pair.size() == 2)
                fl = false;
            else
                if (!pair.empty())
                    pair.clear();
        }
    }
    QPoint start_p;
    QPoint end_p;
    if (pair.at(0).x() < pair.at(1).x()) {
        start_p = pair.at(0);
        end_p = pair.at(1);
    }
    else {
        if (pair.at(0).x() == pair.at(1).x() && pair.at(0).y() < pair.at(1).y()) {
            start_p = pair.at(0);
            end_p = pair.at(1);
        }
        else {
            start_p = pair.at(1);
            end_p = pair.at(0);
        }
    }
    points.push_back(start_p);
    fl = true;
    int y = start_p.y();
    int x = start_p.x();
    int todel = 0;
    vector<QPoint> vec_add;
    int sx = 1;
    int sy = 1;
    int zero_count = 0;
    while (fl) {
        checkAndPushOne(x > 0 && y > 0, x - sx, y - sy, vec_add, points);
        checkAndPushOne(x > 0, x - sx, y, vec_add, points);
        checkAndPushOne(x > 0 && y < h, x - sx, y + sy, vec_add, points);
        checkAndPushOne(y < h, x, y + sy, vec_add, points);
        checkAndPushOne(y < h && x < w, x + sx, y + sy, vec_add, points);
        checkAndPushOne(x < w, x + sx, y, vec_add, points);
        checkAndPushOne(y > 0 && x < w, x + sx, y - sy, vec_add, points);
        checkAndPushOne(y > 0, x, y - sy, vec_add, points);
        if (vec_add.size() == 1 || vec_add.size() == 2) {
            if (vec_add.size() == 1)
                points.push_back(vec_add.back());
            else {
                if (vec_add[0].x() % 100 == 0 && vec_add[0].y() % 100 == 0)
                    points.push_back(vec_add[0]);
                else
                    points.push_back(vec_add.back());
            }
        }
        else {
            if (vec_add.size() > 2) {
                double midx = 0;
                double midy = 0;
                int n = 4;
                if (points.size() >= n) {
                    for (int i = points.size() - n; i < points.size() - 1; i++) {
                        midx += points[i + 1].x() - points[i].x();
                        midy += points[i + 1].y() - points[i].y();
                    }
                    midx /= n - 1;
                    midy /= n - 1;
                }
                else {
                    for (int i = 0; i < points.size() - 1; i++) {
                        midx += points[i + 1].x() - points[i].x();
                        midy += points[i + 1].y() - points[i].y();
                    }
                    midx /= points.size() - 1;
                    midy /= points.size() - 1;
                }
                int ind = -1;
                double min = 10E20;
                for (int i = 0; i < vec_add.size(); i++) {
                    double dist = findDist((double)(points.back().x() + midx), (double)(points.back().y() + midy), vec_add[i].x(), vec_add[i].y());
                    if (min > dist) {
                        min = dist;
                        ind = i;
                    }
                }
                points.push_back(vec_add[ind]);
            }
        }
        if (points.back().x() % 10 == 0) {
            int yr = 0;
        }
        if ((points.back() == start_p || (points.back().x() % 100 == 0 && points.back().y() % 100 == 0)) && vec_add.size() > 0) {
            if (points.back() == start_p) {
                fl = false;
            }
            if (fl) {
                if (todel) {
                    if (points.size() > 7) {
                        points.erase(points.begin(), points.begin() + 7);
                    }
                }
                bool b = true;
                int nx = -1;
                int ny = -1;
                for (int y = 50; y < h && b; y += 100) {
                    nx = -1;
                    for (int x = 50; x < w && b; x += 100) {
                        for (int i = 0; i < points.size() && b; i += 10) {
                            double d = findDist(x, y, points[i].x(), points[i].y());
                            if (findDist(x, y, points[i].x(), points[i].y()) < 50.0) {
                                b = false;
                            }
                        }
                        nx++;
                    }
                    ny++;
                }
                QPoint pfr = points.front();
                QPoint pbck = points.back();
                pfr.setX((int)(pfr.x() - 100 * nx));
                pfr.setY((int)(pfr.y() - 100 * ny));
                pbck.setX((int)(pbck.x() - 100 * nx));
                pbck.setY((int)(pbck.y() - 100 * ny));
                /*QPoint pfr = points.front();
                QPoint pbck = points.back();
                int xmin = -1;
                int ymin = -1;
                if (pfr.x() > pbck.x())
                    xmin = pbck.x();
                else
                    xmin = pfr.x();
                if (pfr.y() > pbck.y())
                    ymin = pbck.y();
                else
                    ymin = pfr.y();
                nx = (int)(xmin / 100.0);
                ny = (int)(ymin / 100.0);
                pfr.setX((int)(pfr.x() - 100 * nx));
                pfr.setY((int)(pfr.y() - 100 * ny));
                pbck.setX((int)(pbck.x() - 100 * nx));
                pbck.setY((int)(pbck.y() - 100 * ny));*/

                res.push_back(get_terminal(points, pfr, pbck, nx, ny));
                if (todel == 0)
                    todel = 8;
                if (points.size() > 8) {
                    points.erase(points.begin(), points.end() - 8);
                }
            }
        }
        x = points.back().x();
        y = points.back().y();
        if (vec_add.size() == 0) {
            zero_count++;
            if (zero_count % 4 == 1) {
                sx++;
            }
            else {
                if (zero_count % 4 == 2) {
                    sx--;
                    sy++;
                }
                else {
                    if (zero_count % 4 == 3) {
                        sx++;
                    }
                }
            }
        }
        else {
            sx = 1;
            sy = 1;
            if (!vec_add.empty())
                vec_add.clear();
        }
    }
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] == 1 && res[i + 1] == 1) {
            res.erase(res.begin() + i + 1, res.begin() + i + 2);
        }
        if (res[i] == -1 || res[i + 1] == -1) {
            res.clear();
            return res;
        }
    }
    return res;
}
BinaryTreeView::BinaryTreeView(QWidget *parent) : QGraphicsView(parent)
{
    pixmap = QPixmap(1200, 800);
    m_scene = new QGraphicsScene(this);
    setScene(m_scene);
    vector<Data> v_dat;
    Data dat;
    dat.fl = true;
    dat.xValues = xValuesA1;
    dat.yValues = yValuesA1;
    v_dat.push_back(dat);
    map_terms[dat] = 0;
    dat.fl = true;
    dat.xValues = xValuesE1;
    dat.yValues = yValuesE1;
    v_dat.push_back(dat);
    map_terms[dat] = 4;
    map_points[{0, 100, 100, 100}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesC1;
    dat.yValues = yValuesC1;
    v_dat.push_back(dat);
    map_terms[dat] = 2;
    map_points[{100, 100, 0, 100}] = v_dat;
    v_dat.clear();
    dat.fl = false;
    dat.xValues = xValuesA2;
    dat.yValues = yValuesA2;
    v_dat.push_back(dat);
    map_terms[dat] = 0;
    map_points[{100, 100, 100, 0}] = v_dat;
    v_dat.clear();
    dat.fl = false;
    dat.xValues = xValuesC2;
    dat.yValues = yValuesC2;
    v_dat.push_back(dat);
    map_terms[dat] = 2;
    dat.fl = false;
    dat.xValues = xValuesD1;
    dat.yValues = yValuesD1;
    v_dat.push_back(dat);
    map_terms[dat] = 3;
    map_points[{100, 0, 100, 100}] = v_dat;
    v_dat.clear();
    dat.fl = false;
    dat.xValues = xValuesA3;
    dat.yValues = yValuesA3;
    v_dat.push_back(dat);
    map_terms[dat] = 0;
    map_points[{0, 0, 0, 100}] = v_dat;
    v_dat.clear();
    dat.fl = false;
    dat.xValues = xValuesC3;
    dat.yValues = yValuesC3;
    v_dat.push_back(dat);
    map_terms[dat] = 2;
    dat.fl = false;
    dat.xValues = xValuesD2;
    dat.yValues = yValuesD2;
    v_dat.push_back(dat);
    map_terms[dat] = 3;
    map_points[{0, 100, 0, 0}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesA4;
    dat.yValues = yValuesA4;
    v_dat.push_back(dat);
    map_terms[dat] = 0;
    map_points[{100, 0, 0, 0}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesC4;
    dat.yValues = yValuesC4;
    v_dat.push_back(dat);
    map_terms[dat] = 2;
    map_points[{0, 0, 100, 0}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesB1;
    dat.yValues = yValuesB1;
    v_dat.push_back(dat);
    map_terms[dat] = 1;
    map_points[{0, 0, 100, 100}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesB2;
    dat.yValues = yValuesB2;
    v_dat.push_back(dat);
    map_terms[dat] = 1;
    map_points[{100, 0, 0, 100}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesB3;
    dat.yValues = yValuesB3;
    v_dat.push_back(dat);
    map_terms[dat] = 1;
    map_points[{0, 100, 100, 0}] = v_dat;
    v_dat.clear();
    dat.fl = true;
    dat.xValues = xValuesB4;
    dat.yValues = yValuesB4;
    v_dat.push_back(dat);
    map_terms[dat] = 1;
    map_points[{100, 100, 0, 0}] = v_dat;
    QPixmap p;
    p = QPixmap(100, 100);
    QPainter pt;
    int i = 0;
    pt.begin(&p);
    pt.setPen(Qt::black);
    p.fill(Qt::white);
    drawFigure(pt, xValuesA1, yValuesA1, 0.0, 0.0, false, true);
    v_pixmaps[i++] = p;
    p.fill(Qt::white);
    drawFigure(pt, xValuesB3, yValuesB3, 0.0, 0.0, false, true);
    v_pixmaps[i++] = p;
    p.fill(Qt::white);
    drawFigure(pt, xValuesC4, yValuesC4, 0.0, 0.0, false, true);
    v_pixmaps[i++] = p;
    p.fill(Qt::white);
    drawFigure(pt, xValuesD1, yValuesD1, 0.0, 0.0, false, false);
    v_pixmaps[i++] = p;
    p.fill(Qt::white);
    drawFigure(pt, xValuesE1, yValuesE1, 0.0, 0.0, false, true);
    v_pixmaps[i++] = p;
    pt.end();
    resize(1100, 800);
}
void BinaryTreeView::buildTree(vector<int> vec_res)
{
    m_scene->clear();
    int xc = 0;
    int yc = 670;
    vector<QString> tree_lvl;
    QPoint p;
    vector<QPoint> tree_p;
    vector<QPoint> tree_prev;
    int sz = vec_res.size();
    int nx = 0;
    for (int i = 0; i < sz; i++) {
        tree_lvl.push_back(grammar[vec_res[i]]);
        p.setX(nx);
        p.setY(yc);
        tree_p.push_back(p);
        tree_prev.push_back(p);
        addNode(grammar[vec_res[i]], nx, yc);
        nx += 150;
    }
    for (int i = 0; i < mp_sz; i++) {
        vector<QString> el_pair = index_map.at(i);
        for (int j = 0; j < tree_lvl.size(); j++) {
            if ((el_pair.size() == 1) && (el_pair[0] == tree_lvl[j])) {
                tree_lvl[j] = grammar_map.at(el_pair);

                int x = (int)((tree_p[j].x() + 60));
                tree_p[j].setY(tree_p[j].y() - 80);
                addEdge(x, tree_p[j].y() + 30, x, tree_prev[j].y());
                addNode(tree_lvl[j], tree_p[j].x(), tree_p[j].y());
                tree_prev[j].setY(tree_p[j].y());
            }
            else {
                if ((el_pair.size() == 2) && (el_pair[0] == tree_lvl[j] && (j + 1 < tree_lvl.size()) && el_pair[1] == tree_lvl[j + 1])) {
                    tree_lvl[j] = grammar_map.at(el_pair);
                    int y;
                    if ( tree_p[j].y() < tree_p[j + 1].y() )
                        y = tree_p[j].y();
                    else
                        y = tree_p[j + 1].y();
                    int x = (int)( (tree_p[j].x() + tree_p[j + 1].x()) / 2);
                    tree_p[j].setY(y - 80);
                    tree_p[j].setX(x);

                    addNode(tree_lvl[j], tree_p[j].x(), tree_p[j].y());
                    addEdge(tree_p[j].x() + 60, tree_p[j].y() + 30, tree_prev[j].x() + 60, tree_prev[j].y());
                    addEdge(tree_p[j].x() + 60, tree_p[j].y() + 30, tree_prev[j + 1].x() + 60, tree_prev[j + 1].y());

                    tree_p.erase(tree_p.begin() + j + 1);
                    tree_lvl.erase(tree_lvl.begin() + j + 1);
                    tree_prev.erase(tree_prev.begin() + j + 1);
                    tree_prev[j].setY(tree_p[j].y());
                    tree_prev[j].setX(tree_p[j].x());
                    j--;
                }
            }
        }
    }
}

void BinaryTreeView::addNode(const QString &text, int x, int y)
{
    TreeNodeWidget *node = new TreeNodeWidget();
    node->setStyleSheet("background-color: #4CAF50;"
                        "font: 12pt \"Segoe UI\";"
                        "font-weight: bold;"
                        "color: white;"
                        "border: 2px solid rgb(154, 255, 143);");
    node->setText(text);
    m_scene->addWidget(node);
    node->setGeometry(x, y, 120, 30);
}

void BinaryTreeView::addEdge(int parentX, int parentY, int childX, int childY)
{
    QGraphicsLineItem *line = new QGraphicsLineItem(parentX, parentY, childX, childY);
    QPen pen(Qt::red);
    pen.setWidth(3);
    line->setPen(pen);
    m_scene->addItem(line);
}
