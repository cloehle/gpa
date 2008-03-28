/* gpa.h  -  main header
   Copyright (C) 2000, 2001 G-N-U GmbH.
   Copyright (C) 2008 g10 Code GmbH.

   This file is part of GPA.

   GPA is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   GPA is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.  */

#ifndef GPA_H
#define GPA_H

#include <glib.h>
#include <gtk/gtk.h>
#include <gpgme.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assuan.h>

#include "gpadefs.h"
#include "gpgmetools.h"
#include "options.h"
#include "icons.h"

/* For mkdir() */
#ifdef G_OS_WIN32
#include <direct.h>
#include <io.h>
#define mkdir(p,m) _mkdir(p)
#ifndef S_ISDIR
#define S_ISDIR(mode) ((mode)&_S_IFDIR)
#endif
#endif

#include "i18n.h"   /* fixme: file should go into each source file */
#include "options.h" /* ditto */


extern GtkWidget *global_windowMain;
extern GtkWidget *global_windowTip;
extern GList *global_defaultRecipients;
extern gchar *gnupg_homedir;
extern gboolean cms_hack;


/* Show the keyring editor dialog.  */
void gpa_open_keyring_editor (GtkAction *action, void *data);

/* Show the filemanager dialog.  */
void gpa_open_filemanager (GtkAction *action, void *data);

/* Show the filemanager dialog.  */
void gpa_open_clipboard (GtkAction *action, void *data);


static const GtkActionEntry gpa_windows_menu_action_entries[] =
  {
      { "Windows", NULL, N_("_Windows"), NULL },

      { "WindowsKeyringEditor", GPA_STOCK_KEYRING, NULL, NULL,
	N_("Open the keyring editor"), G_CALLBACK (gpa_open_keyring_editor) },
      { "WindowsFileManager", GPA_STOCK_FILEMAN,
	N_("_File Manager") /* FIXME: Use stock item.  */, NULL,
	N_("Open the file manager"), G_CALLBACK (gpa_open_filemanager) },
      { "WindowsClipboard", GPA_STOCK_CLIPBOARD,
	N_("_Clipboard") /* FIXME: Use stock item.  */, NULL,
	N_("Open the clipboard"), G_CALLBACK (gpa_open_clipboard) }
  };


/* Show the settings dialog.  */
void gpa_open_settings_dialog (GtkAction *action, void *data);

/* Show the backend configuration dialog.  */
void gpa_open_backend_config_dialog (GtkAction *action, void *data);

static const GtkActionEntry gpa_preferences_menu_action_entries[] =
  {
      { "EditPreferences", GTK_STOCK_PREFERENCES, NULL, NULL,
	N_("Configure the application"),
	G_CALLBACK (gpa_open_settings_dialog) },
      { "EditBackendPreferences", GTK_STOCK_PREFERENCES,
	N_("_Backend Preferences"), NULL,
	N_("Configure the backend programs"),
	G_CALLBACK (gpa_open_backend_config_dialog) }
  };


typedef void (*GPADefaultKeyChanged) (gpointer user_data);

void gpa_run_server_continuation (assuan_context_t ctx, gpg_error_t err);
void gpa_start_server (void);
void gpa_stop_server (void);

/*-- utils.c --*/
/* We are so used to these function thus provide them.  */
void *xmalloc (size_t n);
void *xcalloc (size_t n, size_t m);
char *xstrdup (const char *str);
#define xfree(a) g_free ((a))

int translate_sys2libc_fd (assuan_fd_t fd, int for_write);


/*-- Convenience macros. -- */
#define DIM(v)		     (sizeof(v)/sizeof((v)[0]))
#define DIMof(type,member)   DIM(((type *)0)->member)

/*-- Macros to replace ctype ones to avoid locale problems. --*/
#define spacep(p)   (*(p) == ' ' || *(p) == '\t')
#define digitp(p)   (*(p) >= '0' && *(p) <= '9')
#define hexdigitp(a) (digitp (a)                     \
                      || (*(a) >= 'A' && *(a) <= 'F')  \
                      || (*(a) >= 'a' && *(a) <= 'f'))
  /* Note this isn't identical to a C locale isspace() without \f and
     \v, but works for the purposes used here. */
#define ascii_isspace(a) ((a)==' ' || (a)=='\n' || (a)=='\r' || (a)=='\t')

/* The atoi macros assume that the buffer has only valid digits. */
#define atoi_1(p)   (*(p) - '0' )
#define atoi_2(p)   ((atoi_1(p) * 10) + atoi_1((p)+1))
#define atoi_4(p)   ((atoi_2(p) * 100) + atoi_2((p)+2))
#define xtoi_1(p)   (*(p) <= '9'? (*(p)- '0'): \
                     *(p) <= 'F'? (*(p)-'A'+10):(*(p)-'a'+10))
#define xtoi_2(p)   ((xtoi_1(p) * 16) + xtoi_1((p)+1))
#define xtoi_4(p)   ((xtoi_2(p) * 256) + xtoi_2((p)+2))

#define tohex(n) ((n) < 10 ? ((n) + '0') : (((n) - 10) + 'A'))


/*--  Error codes not yet available --*/
#ifndef GPG_ERR_UNFINISHED
#define GPG_ERR_UNFINISHED 199
#endif

#endif /*GPA_H */

