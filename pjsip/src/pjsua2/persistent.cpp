/* $Id: persistent.cpp 4704 2014-01-16 05:30:46Z ming $ */
/*
 * Copyright (C) 2013 Teluu Inc. (http://www.teluu.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <pjsua2/persistent.hpp>

using namespace pj;
using namespace std;


bool PersistentDocument::hasUnread() const
{
    return getRootContainer().hasUnread();
}

string PersistentDocument::unreadName() const throw(Error)
{
    return getRootContainer().unreadName();
}

int PersistentDocument::readInt(const string &name) const throw(Error)
{
    return (int)getRootContainer().readNumber(name);
}

float PersistentDocument::readNumber(const string &name) const throw(Error)
{
    return getRootContainer().readNumber(name);
}

bool PersistentDocument::readBool(const string &name) const throw(Error)
{
    return getRootContainer().readBool(name);
}

string PersistentDocument::readString(const string &name) const throw(Error)
{
    return getRootContainer().readString(name);
}

StringVector PersistentDocument::readStringVector(const string &name) const
						  throw(Error)
{
    return getRootContainer().readStringVector(name);
}

void PersistentDocument::readObject(PersistentObject &obj) const throw(Error)
{
    getRootContainer().readObject(obj);
}

ContainerNode PersistentDocument::readContainer(const string &name) const
					        throw(Error)
{
    return getRootContainer().readContainer(name);
}

ContainerNode PersistentDocument::readArray(const string &name) const
					    throw(Error)
{
    return getRootContainer().readArray(name);
}

void PersistentDocument::writeNumber(const string &name,
				     float num) throw(Error)
{
    getRootContainer().writeNumber(name, num);
}

void PersistentDocument::writeInt(const string &name,
				  int num) throw(Error)
{
    getRootContainer().writeNumber(name, (float)num);
}

void PersistentDocument::writeBool(const string &name,
				   bool value) throw(Error)
{
    getRootContainer().writeBool(name, value);
}

void PersistentDocument::writeString(const string &name,
                                     const string &value) throw(Error)
{
    getRootContainer().writeString(name, value);
}

void PersistentDocument::writeStringVector(const string &name,
                                           const StringVector &value)
					   throw(Error)
{
    getRootContainer().writeStringVector(name, value);
}

void PersistentDocument::writeObject(const PersistentObject &obj) throw(Error)
{
    getRootContainer().writeObject(obj);
}

ContainerNode PersistentDocument::writeNewContainer(const string &name)
						    throw(Error)
{
    return getRootContainer().writeNewContainer(name);
}

ContainerNode PersistentDocument::writeNewArray(const string &name)
						    throw(Error)
{
    return getRootContainer().writeNewArray(name);
}

///////////////////////////////////////////////////////////////////////////////

bool ContainerNode::hasUnread() const
{
    return op->hasUnread(this);
}

string ContainerNode::unreadName() const throw(Error)
{
    return op->unreadName(this);
}

int ContainerNode::readInt(const string &name) const throw(Error)
{
    return (int)op->readNumber(this, name);
}

float ContainerNode::readNumber(const string &name) const throw(Error)
{
    return op->readNumber(this, name);
}

bool ContainerNode::readBool(const string &name) const throw(Error)
{
    return op->readBool(this, name);
}

string ContainerNode::readString(const string &name) const throw(Error)
{
    return op->readString(this, name);
}

StringVector ContainerNode::readStringVector(const string &name) const
					     throw(Error)
{
    return op->readStringVector(this, name);
}

void ContainerNode::readObject(PersistentObject &obj) const throw(Error)
{
    obj.readObject(*this);
}

ContainerNode ContainerNode::readContainer(const string &name) const
					   throw(Error)
{
    return op->readContainer(this, name);
}

ContainerNode ContainerNode::readArray(const string &name) const
					   throw(Error)
{
    return op->readArray(this, name);
}

void ContainerNode::writeNumber(const string &name,
				float num) throw(Error)
{
    return op->writeNumber(this, name, num);
}

void ContainerNode::writeInt(const string &name,
			     int num) throw(Error)
{
    return op->writeNumber(this, name, (float)num);
}

void ContainerNode::writeBool(const string &name,
			      bool value) throw(Error)
{
    return op->writeBool(this, name, value);
}

void ContainerNode::writeString(const string &name,
				const string &value) throw(Error)
{
    return op->writeString(this, name, value);
}

void ContainerNode::writeStringVector(const string &name,
				      const StringVector &value)
				      throw(Error)
{
    return op->writeStringVector(this, name, value);
}

void ContainerNode::writeObject(const PersistentObject &obj) throw(Error)
{
    obj.writeObject(*this);
}

ContainerNode ContainerNode::writeNewContainer(const string &name)
					       throw(Error)
{
    return op->writeNewContainer(this, name);
}

ContainerNode ContainerNode::writeNewArray(const string &name)
					   throw(Error)
{
    return op->writeNewArray(this, name);
}
