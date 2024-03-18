#ifndef BINARYTREEVIEW_H
#define BINARYTREEVIEW_H

#include <QGraphicsView>
#include <vector>
using namespace std;

class BinaryTreeView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit BinaryTreeView(QWidget *parent = nullptr);
    vector<double> lagrangeCoefficients(const vector<double>& xValues, const vector<double>& yValues);
    double lagrangeInterpolation(double x, const vector<double>& xValues, vector<double>& coefficients);
    map<vector<QString>, QString> get_grammar_map();
    map<int, vector<QString>> get_index_map();
    int mp_sz = 0;
    const vector<QString> grammar = {"a", "b", "c", "d", "e", "Плечо", "Сторона", "Основание", "Правая часть", "Левая часть", "Пара плеч", "T", "S"};
    QPixmap pixmap;
    QPainter painter;
    QPixmap v_pixmaps[5];
    QGraphicsScene *m_scene;
    vector<double> xValuesA1 = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<double> yValuesA1 = {100, 40, 20, 8, 2, 0, 2, 8, 20, 40, 100};

    vector<double> xValuesC1 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    vector<double> yValuesC1 = {100, 40, 20, 8, 2, 0, 2, 8, 20, 40, 100};

    vector<double> yValuesA2 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};//
    vector<double> xValuesA2 = {100, 40, 20, 8, 2, 0, 2, 8, 20, 40, 100};

    vector<double> yValuesC2 = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};//
    vector<double> xValuesC2 = {100, 40, 20, 8, 2, 0, 2, 8, 20, 40, 100};

    vector<double> xValuesA3 = {0, 60, 80, 92, 98, 100, 98, 92, 80, 60, 0};//
    vector<double> yValuesA3 = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    vector<double> xValuesC3 = {0, 60, 80, 92, 98, 100, 98, 92, 80, 60, 0};//
    vector<double> yValuesC3 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    vector<double> yValuesA4 = {0, 60, 80, 92, 98, 100, 98, 92, 80, 60, 0};
    vector<double> xValuesA4 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    vector<double> yValuesC4 = {0, 60, 80, 92, 98, 100, 98, 92, 80, 60, 0};
    vector<double> xValuesC4 = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    vector<double> xValuesB1 = {0, 25, 75, 100};
    vector<double> yValuesB1 = {0, 25, 75,  100};

    vector<double> xValuesB2 = {100, 75, 25, 0};
    vector<double> yValuesB2 = {0, 25, 75,  100};

    vector<double> xValuesB3 = {0, 25, 75,  100};
    vector<double> yValuesB3 = {100, 75, 25, 0};

    vector<double> xValuesB4 = {100, 75, 25, 0};
    vector<double> yValuesB4 = {100, 75, 25, 0};

    vector<double> xValuesD1 = {100, 60, 30, 0, 30, 60, 100};//
    vector<double> yValuesD1 = {0, 17, 34, 50, 67, 84, 100};

    vector<double> xValuesD2 = {0, 40, 70, 100, 70, 40, 0};//
    vector<double> yValuesD2 = {100, 84, 67, 50, 34, 17, 0};

    vector<double> xValuesE1 = {0, 50, 100};
    vector<double> yValuesE1 = {100, 50, 100};
public slots:
    void buildTree(vector<int> vec_res); // Build and display the binary tree
    QPoint drawPicture1(bool b);
    QPoint drawPicture2(bool b);
    QPoint drawPicture3(bool b);
    vector<int> runAnalysis(const QPoint sz_xy);

private:
    struct Data {
        vector<double> xValues;
        vector<double> yValues;
        bool fl;
        bool operator<(const Data& other) const {
            if (xValues != other.xValues) return xValues < other.xValues;
            if (yValues != other.yValues) return yValues < other.yValues;
            return fl < other.fl;
        }
    };
    map<vector<int>, vector<Data>> map_points;
    map<Data, int> map_terms;
    void drawFigure(QPainter &painter, const vector<double>& xValues, const vector<double>& yValues, double x, double y, bool b, bool fl);
    void addNode(const QString &text, int x, int y);
    void addEdge(int parentX, int parentY, int childX, int childY);
    int checkAndPushOne(const bool b, int x, int y, vector<QPoint> &vec_add, vector<QPoint> &points);
    bool checkLastEightPoints(const std::vector<QPoint>& points, const QPoint point);
    int get_terminal(const vector<QPoint> &points, QPoint p_fr, QPoint p_bck, int nx, int ny);


    const map<vector<QString>, QString> grammar_map = { {{grammar[0]}, grammar[5]},
                                                       {{grammar[5], grammar[1]}, grammar[5]},
                                                       {{grammar[1], grammar[5]}, grammar[5]},
                                                       {{grammar[3]}, grammar[6]},
                                                       {{grammar[1]}, grammar[6]},
                                                       {{grammar[6], grammar[1]}, grammar[6]},
                                                       {{grammar[1], grammar[6]}, grammar[6]},
                                                       {{grammar[4]}, grammar[7]},
                                                       {{grammar[7], grammar[1]}, grammar[7]},
                                                       {{grammar[1], grammar[7]}, grammar[7]},
                                                       {{grammar[2], grammar[5]}, grammar[8]},
                                                       {{grammar[5], grammar[2]}, grammar[9]},
                                                       {{grammar[9], grammar[5]}, grammar[10]},
                                                       {{grammar[5], grammar[8]}, grammar[10]},
                                                       {{grammar[10], grammar[6]}, grammar[10]},
                                                       {{grammar[6], grammar[10]}, grammar[10]},
                                                       {{grammar[7], grammar[10]}, grammar[11]},
                                                       {{grammar[10], grammar[10]}, grammar[12]},
                                                       };
    const map<int, vector<QString>> index_map = {     {mp_sz++, {grammar[0]}},
                                                       {mp_sz++, {grammar[5], grammar[1]}},
                                                       {mp_sz++, {grammar[1], grammar[5]}},
                                                       {mp_sz++, {grammar[3]}},
                                                       {mp_sz++, {grammar[1]}},
                                                       {mp_sz++, {grammar[6], grammar[1]}},
                                                       {mp_sz++, {grammar[1], grammar[6]}},
                                                       {mp_sz++, {grammar[4]}},
                                                       {mp_sz++, {grammar[7], grammar[1]}},
                                                       {mp_sz++, {grammar[1], grammar[7]}},
                                                       {mp_sz++, {grammar[2], grammar[5]}},
                                                       {mp_sz++, {grammar[5], grammar[2]}},
                                                       {mp_sz++, {grammar[9], grammar[5]}},
                                                       {mp_sz++, {grammar[5], grammar[8]}},
                                                       {mp_sz++,{grammar[10], grammar[6]}},
                                                       {mp_sz++, {grammar[6], grammar[10]}},
                                                       {mp_sz++, {grammar[7], grammar[10]}},
                                                       {mp_sz++, {grammar[10], grammar[10]}},
                                                  };

};

#endif // BINARYTREEVIEW_H
