/* types.h -  Some type definitions
 *	Copyright (C) 2000 Werner Koch (dd9jn)
 *
 * This file is part of GPGME.
 *
 * GPGME is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GPGME is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#ifndef TYPES_H
#define TYPES_H

#define GPAPA  /* should be in local Makefile */

#ifdef GPAPA
  extern const char *gpapa_private_get_gpg_program (void);
# ifdef GPG_PATH
#  undef GPG_PATH
# endif
# define GPG_PATH gpapa_private_get_gpg_program ()
#else /* not GPAPA */
# ifndef GPG_PATH
#  define GPG_PATH "/usr/local/bin/gpg"
# endif
#endif /* not GPAPA */

#include "gpgme.h"  /* external objects and prototypes */

#ifndef GPAPA
typedef unsigned char byte;
#endif /* not GPAPA */


typedef enum {
    GPGME_DATA_MODE_NONE  = 0,
    GPGME_DATA_MODE_IN    = 1,
    GPGME_DATA_MODE_OUT   = 2,
    GPGME_DATA_MODE_INOUT = 3
} GpgmeDataMode;


/*
 * Declaration of internal objects
 */

/*-- rungpg.c --*/
struct gpg_object_s;
typedef struct gpg_object_s *GpgObject;


/*-- verify.c --*/
struct verify_result_s;
typedef struct verify_result_s *VerifyResult;

/*-- decrypt.c --*/
struct decrypt_result_s;
typedef struct decrypt_result_s *DecryptResult;

/*-- sign.c --*/
struct sign_result_s;
typedef struct sign_result_s *SignResult;

/*-- key.c --*/


#endif /* TYPES_H */





