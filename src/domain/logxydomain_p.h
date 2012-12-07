/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

//  W A R N I N G
//  -------------
//
// This file is not part of the QtCommercial Chart API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef LOGXYDOMAIN_H
#define LOGXYDOMAIN_H
#include "abstractdomain_p.h"
#include <QRectF>
#include <QSizeF>

QTCOMMERCIALCHART_BEGIN_NAMESPACE

class QTCOMMERCIALCHART_AUTOTEST_EXPORT LogXYDomain: public AbstractDomain
{
    Q_OBJECT
public:
    explicit LogXYDomain(QObject *object = 0);
    virtual ~LogXYDomain();

    DomainType type(){ return AbstractDomain::LogXYDomain;}

    void setRange(qreal minX, qreal maxX, qreal minY, qreal maxY);

    friend bool QTCOMMERCIALCHART_AUTOTEST_EXPORT operator== (const LogXYDomain &domain1, const LogXYDomain &domain2);
    friend bool QTCOMMERCIALCHART_AUTOTEST_EXPORT operator!= (const LogXYDomain &domain1, const LogXYDomain &domain2);
    friend QDebug QTCOMMERCIALCHART_AUTOTEST_EXPORT operator<<(QDebug dbg, const LogXYDomain &domain);

    void zoomIn(const QRectF &rect);
    void zoomOut(const QRectF &rect);
    void move(qreal dx, qreal dy);

    QPointF calculateGeometryPoint(const QPointF &point, bool &ok) const;
    QPointF calculateDomainPoint(const QPointF &point) const;
    QVector<QPointF> calculateGeometryPoints(const QList<QPointF>& vector) const;

    bool attachAxis(QAbstractAxis* axis);
    bool detachAxis(QAbstractAxis* axis);

public Q_SLOTS:
    void handleHorizontalAxisBaseChanged(qreal baseX);

private:
    qreal m_logLeftX;
    qreal m_logRightX;
    qreal m_logBaseX;
};

QTCOMMERCIALCHART_END_NAMESPACE

#endif // LOGXYDOMAIN_H
