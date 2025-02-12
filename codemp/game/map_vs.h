/*
===========================================================================
Copyright (C) 2003 - 2008, OJP contributors

This file is part of the OpenJK-OJP source code.

OpenJK-OJP is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#ifndef _MAP_VS_H_
#define _MAP_VS_H_


#include <map>

namespace ratl
{
	template <class mapKey, class mapValue, int MaxPairs>
	class map_vs : public std::map<mapKey, mapValue>
	{
	public:
	};

	/* original definition setup.
	class map_vs
	{
	public:
		/*
		struct mapPair_s 
		{
			mapKey	key;
			mapValue value;
		};
		
		typedef struct mapPair_s mapPair_t;

		mapPair_t Pairs[MaxPairs];


		//I assume this blanks out the class object.
		void clear(void);

		//finds mapKey item for given entity
		mapPair_t& find(mapKey& entityNum);

		//the first open pair in map.
		mapPair_t& end();

		//first pair in map
		mapPair_t& begin();

		//add a key/value pair to the map_vs
		void insert(mapKey key, mapValue value );

		//erases the pair with the given map key
		void erase (mapKey deleteKey);

		// CLASS iterator
		class iterator;
		friend class iterator;

		class iterator
		{	// iterator for mutable _Tree
		public:

			mapPair_t* currentPair;

			iterator()
			{	// construct with null node pointer
			}

			iterator(mapPair_t pair);

			bool operator==(mapPair_t b);
			bool operator!=(mapPair_t b);

			mapValue& operator*() const
			{
				return (currentPair->value);
			}

			mapValue* operator->() const
			{	// return pointer to the value object for the current pair
				return &(currentPair->value);
			}

			iterator& operator++();

			iterator operator++(int)
			{	// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			iterator& operator--()
			{	// predecrement
				--(*(iterator *)this);
				return (*this);
			}

			iterator operator--(int)
			{	// postdecrement
				iterator _Tmp = *this;
				--*this;
				return (_Tmp);
			}
		};
	};
	*/


	//this struct seems to be used for comparing closest neighbors for nav nodes.
	struct ratl_compare_s
	{
		int mHandle;
		int mCost;
	};
	typedef struct ratl_compare_s ratl_compare;

}

#endif





