/* keysmenu.h  -  The GNU Privacy Assistant
 *      Copyright (C) 2000 Free Software Foundation, Inc.
 *
 * This file is part of GPA
 *
 * GPA is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GPA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

extern void keys_selectKey (
  GtkWidget *clistKeys, gint row, gint column,
  GdkEventButton *event, gpointer param
);
extern void keys_unselectKey (
  GtkWidget *clistKeys, gint row, gint column,
  GdkEventButton *event, gpointer param
);
extern GtkWidget *gpa_tableKey_new ( GpapaKey *key, GtkWidget *window );
                  
extern void keys_openPublic ( void );
extern void keys_openSecret ( void );
extern void keys_generateKey ( void );
extern void keys_generateRevocation ( void );
extern void keys_import ( void );
extern void keys_importOwnertrust ( void );
extern void keys_updateTrust ( void );