// 
// Copyright(c) 2009 Syntext, Inc. All Rights Reserved.
// Contact: info@syntext.com, http://www.syntext.com
// 
// This file is part of Syntext Serna XML Editor.
// 
// COMMERCIAL USAGE
// Licensees holding valid Syntext Serna commercial licenses may use this file
// in accordance with the Syntext Serna Commercial License Agreement provided
// with the software, or, alternatively, in accorance with the terms contained
// in a written agreement between you and Syntext, Inc.
// 
// GNU GENERAL PUBLIC LICENSE USAGE
// Alternatively, this file may be used under the terms of the GNU General 
// Public License versions 2.0 or 3.0 as published by the Free Software 
// Foundation and appearing in the file LICENSE.GPL included in the packaging 
// of this file. In addition, as a special exception, Syntext, Inc. gives you
// certain additional rights, which are described in the Syntext, Inc. GPL 
// Exception for Syntext Serna Free Edition, included in the file 
// GPL_EXCEPTION.txt in this package.
// 
// You should have received a copy of appropriate licenses along with this 
// package. If not, see <http://www.syntext.com/legal/>. If you are unsure
// which license is appropriate for your use, please contact the sales 
// department at sales@syntext.com.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// 
// Copyright (c) 2004 Syntext Inc.
//
// This is a copyrighted commercial software.
// Please see COPYRIGHT file for details.

/** \file
 */

#include "proputils/proputils_exports.h"
#include "PropertyAccessor.h"

#include "common/PropertyTree.h"
#include "common/String.h"
#include "common/StringCvt.h"

namespace PropUtils {

using namespace Common;

PropertyAccessor::PropertyAccessor()
{
}

PropertyAccessor::PropertyAccessor(PropertyNode* node)
 :  PropertyTree(node)
{
}

PropertyAccessor::PropertyAccessor(const char* name, unsigned len)
 :  PropertyTree(new PropertyNode(from_latin1(name, len)))
{
}

PropertyNode& PropertyAccessor::getRoot()
{
    if (0 == root())
        setRoot(new PropertyNode);
    return *root();
}

PropertyNode& PropertyAccessor::getProp(const String& propName)
{
    return *(getRoot().makeDescendant(propName, String::null(), false));
}

PropertyNode& PropertyAccessor::getProp(const char* propName, unsigned len)
{
    return getProp(from_latin1(propName, len));
}

}
