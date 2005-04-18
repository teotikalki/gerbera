/*  array.h - this file is part of MediaTomb.
                                                                                
    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
                       Sergey Bostandzhyan <jin@deadlock.dhs.org>
                                                                                
    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
                                                                                
    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
                                                                                
    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __ZMMF_ARRAY_H__
#define __ZMMF_ARRAY_H__

#include "zmm/zmm.h"

#define DEFAULT_ARRAY_CAPACITY 16

namespace zmm
{

class ArrayBase
{
public:
    ArrayBase();
    ~ArrayBase();
    void init(int capacity);
    void append(Object *el);
    void set(Object *el, int index);
    Object *get(int index);
    void remove(int index, int count);
    void insert(int index, Object *el);
    int size();
protected:
    void resize(int requiredSize);
public:
    Object **arr;
protected:
    int siz;
    int capacity;
};


template <class T>
class Array : public Object
{
protected:
    ArrayBase base;

public:
    Array() : Object()
    {
        base.init(DEFAULT_ARRAY_CAPACITY);
    }
    Array(int capacity) : Object()
    {
        base.init(capacity);
    }

    void append(Ref<T> el)
    {
        base.append(el.getPtr());
    }
    void set(Ref<T> el, int index)
    {
        base.set(el.getPtr(), index);
    }
    Ref<T> get(int index)
    {
        return Ref<T>( (T *)base.get(index) );
    }
    void remove(int index, int count=1)
    {
        base.remove(index, count);
    }
    void insert(int index, Ref<T> el)
    {
        base.insert(index, el.getPtr());
    }
    int size()
    {
        return base.size();
    }
	Object **getObjectArray()
	{
		return base.arr;
	}
};


} // namespace

#endif // __ZMMF_ARRAY_H__
