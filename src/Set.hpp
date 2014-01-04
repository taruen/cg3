/*
* Copyright (C) 2007-2014, GrammarSoft ApS
* Developed by Tino Didriksen <mail@tinodidriksen.com>
* Design by Eckhard Bick <eckhard.bick@mail.dk>, Tino Didriksen <mail@tinodidriksen.com>
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

#pragma once
#ifndef c6d28b7452ec699b_SET_H
#define c6d28b7452ec699b_SET_H

#include "stdafx.hpp"
#include "CompositeTag.hpp"
#include "sorted_vector.hpp"

namespace CG3 {
	class Grammar;

	enum {
		ST_ANY             = (1 <<  0),
		ST_SPECIAL         = (1 <<  1),
		ST_TAG_UNIFY       = (1 <<  2),
		ST_SET_UNIFY       = (1 <<  3),
		ST_CHILD_UNIFY     = (1 <<  4),
		ST_MAPPING         = (1 <<  5),
		ST_USED            = (1 <<  6),
		ST_STATIC          = (1 <<  7),
	};

	class Set {
	public:
		static UFILE* dump_hashes_out;

		uint8_t type;
		uint32_t line;
		uint32_t hash;
		uint32_t number;
		mutable uint32_t num_fail, num_match;
		mutable double total_time;
		UString name;

		AnyTagVector tags_list;
		CompositeTagHashSet tags;
		TagHashSet single_tags;
		uint32SortedVector single_tags_hash;
		TagHashSet ff_tags;

		uint32Vector set_ops;
		uint32Vector sets;

		Set();
		Set(const Set& from);

		void setName(uint32_t to = 0);
		void setName(const UChar *to);
		void setName(const UString& to);

		bool empty() const;
		uint32_t rehash();
		void resetStatistics();
		void reindex(Grammar& grammar);
		void markUsed(Grammar& grammar);

		AnyTagSet getTagList(const Grammar& grammar) const;
	};

	struct compare_Set {
		static const size_t bucket_size = 4;
		static const size_t min_buckets = 8;

		inline size_t operator() (const Set* x) const {
			return x->hash;
		}

		inline bool operator() (const Set* a, const Set* b) const {
			return a->hash < b->hash;
		}
	};

	typedef std::set<Set*> SetSet;
	typedef std::vector<Set*> SetVector;
	typedef stdext::hash_map<uint32_t,Set*> Setuint32HashMap;
}

#endif
