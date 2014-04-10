/********************************************************************\
 * GNCId.h -- Gnucash entity identifier API                         *
 * Copyright (C) 2000 Dave Peticolas <peticola@cs.ucdavis.edu>      *
 *                                                                  *
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652       *
 * Boston, MA  02111-1307,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/

#ifndef GNC_ID_H
#define GNC_ID_H 

/* This file defines an API for using gnucash entity identifiers.
 *
 * Identifiers can be used to reference Accounts, Transactions, and
 * Splits. These four Gnucash types are referred to as Gnucash
 * entities. Identifiers are globally-unique and permanent, i.e., once
 * an entity has been assigned an identifier, it retains that same
 * identifier for its lifetime.
 *
 * Identifiers can be encoded as hex strings. */

#include "guid.h"

/* Identifiers are 'typed' with strings. The ids used in gnucash are
 * defined below. An id with type GNC_ID_NONE does not refer to any
 * entity, although that may change as new ids are created. An id with
 * type GNC_ID_NULL does not refer to any entity, and will never refer
 * to any entity. An identifier with any other type may refer to an
 * actual entity, but that is not guaranteed. If an id does refer to
 * an entity, the type of the entity will match the type of the
 * identifier. */

typedef const char * GNCIdType;
typedef const char * GNCIdTypeConst;

#define GNC_ID_NONE           NULL
#define GNC_ID_ACCOUNT        "Account"
#define GNC_ID_BOOK           "Book"
#define GNC_ID_COMMODITY_TABLE "CommodityTable"
#define GNC_ID_FREQSPEC       "FreqSpec"
#define GNC_ID_GROUP          "AccountGroup"
#define GNC_ID_LOT            "Lot"
#define GNC_ID_NULL           "null"
#define GNC_ID_PERIOD	      "Period"
#define GNC_ID_PRICE          "Price"
#define GNC_ID_PRICEDB        "PriceDB"
#define GNC_ID_SPLIT          "Split"
#define GNC_ID_SCHEDXACTION   "SchedXaction"
#define GNC_ID_SESSION        "Session"
#define GNC_ID_SXTT           "SXTT"
#define GNC_ID_TRANS          "Trans"


typedef struct gnc_entity_table GNCEntityTable;

GNCIdType xaccGUIDTypeEntityTable (const GUID * guid,
                                   GNCEntityTable *entity_table);

/* Return the type of an identifier.
 * Equivalent function prototype:
 * GNCIdType xaccGUIDType (const GUID * guid, QofBook *book); 
 */

#define xaccGUIDType(guid,book)      \
    xaccGUIDTypeEntityTable ((guid), qof_book_get_entity_table (book))


/* Returns a GUID which is guaranteed to never reference any entity. */
const GUID * xaccGUIDNULL (void);

/* Efficiently allocate & free memory for GUIDs */
GUID * xaccGUIDMalloc (void);
void   xaccGUIDFree (GUID *guid);

/* Callback type for xaccForeachEntity */
typedef void (*foreachObjectCB) (gpointer object, gpointer user_data);

#endif