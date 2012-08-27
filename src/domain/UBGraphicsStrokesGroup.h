/*
 * Copyright (C) 2012 Webdoc SA
 *
 * This file is part of Open-Sankoré.
 *
 * Open-Sankoré is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation, version 2,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * Open-Sankoré is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with Open-Sankoré; if not, see
 * <http://www.gnu.org/licenses/>.
 */


#ifndef UBGRAPHICSSTROKESGROUP_H
#define UBGRAPHICSSTROKESGROUP_H

#include <QGraphicsItemGroup>
#include <QGraphicsSceneMouseEvent>

#include "core/UB.h"
#include "UBItem.h"

class UBGraphicsStrokesGroup : public QObject, public QGraphicsItemGroup, public UBItem, public UBGraphicsItem
{
    Q_OBJECT
public:
    UBGraphicsStrokesGroup(QGraphicsItem* parent = 0);
    ~UBGraphicsStrokesGroup();
    virtual UBItem* deepCopy() const;
    virtual void copyItemParameters(UBItem *copy) const;
    virtual void remove();
    virtual UBGraphicsItemDelegate* Delegate() const {return mDelegate;}
    enum { Type = UBGraphicsItemType::StrokeItemType };
    virtual int type() const
    {
        return Type;
    }
    virtual void setUuid(const QUuid &pUuid);

protected:

    virtual QPainterPath shape () const;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // UBGRAPHICSSTROKESGROUP_H
