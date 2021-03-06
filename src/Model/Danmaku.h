/*=======================================================================
*
*   Copyright (C) 2013-2015 Lysine.
*
*   Filename:    Danmaku.h
*   Time:        2013/03/18
*   Author:      Lysine
*
*   Lysine is a student majoring in Software Engineering
*   from the School of Software, SUN YAT-SEN UNIVERSITY.
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.

*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
=========================================================================*/

#pragma once

#include <QtGui>
#include <QtCore>

class Comment;
class Graphic;
class Record;
class DanmakuPrivate;

class Danmaku :public QAbstractItemModel
{
	Q_OBJECT
public:
	virtual QVariant data(const QModelIndex &index, int role) const override;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QModelIndex parent(const QModelIndex &) const override;
	virtual QModelIndex index(int row, int colum, const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	virtual ~Danmaku();
	QList<Record> &getPool();
	void draw(QPainter *painter, double move);
	static Danmaku *instance();

private:
	static Danmaku *ins;
	DanmakuPrivate *const d_ptr;
	Q_DECLARE_PRIVATE(Danmaku);

	explicit Danmaku(QObject *parent = 0);

signals:
	void alphaChanged(int);
	void unrecognizedComment(const Comment *);

public slots:
	const Comment *commentAt(QPointF point) const;
	void setAlpha(int alpha);
	void clearPool();
	void resetTime();
	void setTime(qint64 time);
	void appendToPool(const Record *record);
	void appendToPool(QString source, const Comment *comment);
	void clearCurrent(bool soft = false);
	void insertToCurrent(Graphic *graphic, int index = -1);
	void parse(int flag = 0);
	void delayAll(qint64 time);
	void jumpToTime(qint64 time);
	void saveToFile(QString file) const;
	qint64 getDuration() const;
};
