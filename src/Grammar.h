/*
 * Copyright (C) 2006, GrammarSoft Aps
 * and the VISL project at the University of Southern Denmark.
 * All Rights Reserved.
 *
 * The contents of this file are subject to the GrammarSoft Public
 * License Version 1.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.grammarsoft.com/GSPL or
 * http://visl.sdu.dk/GSPL.txt
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 */
#ifndef __GRAMMAR_H
#define __GRAMMAR_H

#include <unicode/ustring.h>
#include "Set.h"
#include "Section.h"
#include "Rule.h"

namespace CG3 {

	class Grammar {
	public:
		uint32_t last_modified;
		UChar *name;
		uint32_t lines, curline;
		stdext::hash_map<uint32_t, CompositeTag*> tags;
		stdext::hash_map<uint32_t, Set*> sets;
		Set *delimiters;
		std::vector<UChar*> preferred_targets;

		// ToDo: Implement vislcg_compat_mode
		bool vislcg_compat_mode;

		std::map<uint32_t, Section*> sections;
		stdext::hash_map<uint32_t, Rule*> rules;

		Grammar();
		~Grammar();

		void setName(const char *to);
		void setName(const UChar *to);

		void addPreferredTarget(UChar *to);

		void addSet(Set *to);
		Set *getSet(uint32_t which);
		Set *allocateSet();
		void destroySet(Set *set);

		void addCompositeTagToSet(Set *set, CompositeTag *tag);
		CompositeTag *allocateCompositeTag();
		CompositeTag *duplicateCompositeTag(CompositeTag *tag);
		void destroyCompositeTag(CompositeTag *tag);

		Rule *allocateRule();
		void addRule(Rule *rule);
		void destroyRule(Rule *rule);

		void manipulateSet(uint32_t set_a, int op, uint32_t set_b, uint32_t result);
	};

}

#endif
