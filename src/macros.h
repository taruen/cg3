/*
* Copyright (C) 2007, GrammarSoft ApS
* Developed by Tino Didriksen <tino@didriksen.cc>
* Design by Eckhard Bick <eckhard.bick@mail.dk>, Tino Didriksen <tino@didriksen.cc>
*
* This file is part of VISL CG-3
*
* VISL CG-3 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* VISL CG-3 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with VISL CG-3.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MACROS_H
#define __MACROS_H

#define foreach(a, b, c, d) \
	a::iterator c; \
	a::iterator d = (b).end(); \
	for (c = (b).begin() ; c != d ; c++) 

#define const_foreach(a, b, c, d) \
	a::const_iterator c; \
	a::const_iterator d = (b).end(); \
	for (c = (b).begin() ; c != d ; c++) 

#define reverse_foreach(a, b, c, d) \
	a::reverse_iterator c; \
	a::reverse_iterator d = (b).rend(); \
	for (c = (b).rbegin() ; c != d ; c++) 

#define reverse_const_foreach(a, b, c, d) \
	a::reverse_const_iterator c; \
	a::reverse_const_iterator d = (b).rend(); \
	for (c = (b).rbegin() ; c != d ; c++) 

#endif
