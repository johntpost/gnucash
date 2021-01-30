/* gnc-mod-withdep.c : the Gnucash plugin that wraps the library
 * 'libwithdep.so'. it does this by being linked against libwithdep.so */
/********************************************************************\
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
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652       *
 * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/


#include <config.h>
#include <stdio.h>
#include <gmodule.h>

#include "gnc-module.h"
#include "gnc-module-api.h"

GNC_MODULE_API_DECL(libgncmod_withdep)

int libgncmod_withdep_gnc_module_system_interface = 0;

int libgncmod_withdep_gnc_module_current = 0;
int libgncmod_withdep_gnc_module_age = 0;
int libgncmod_withdep_gnc_module_revision = 0;

char *
libgncmod_withdep_gnc_module_path(void)
{
    return g_strdup("gnucash/withdep");
}

char *
libgncmod_withdep_gnc_module_description(void)
{
    return g_strdup("this is the withdep module");
}

int
libgncmod_withdep_gnc_module_init(int refcount)
{
    /* load libfoo */
    if (gnc_module_load("gnucash/ordinary", 0))
        return TRUE;
    else
        return FALSE;
}
