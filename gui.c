#include <gtk/gtk.h>
#include "gui.h"

static void click1_cb (GtkButton *btn) {
    const char *s;
  
    s = gtk_button_get_label (btn);
    if (g_strcmp0 (s, "Hello.") == 0)
      gtk_button_set_label (btn, "Good-bye.");
   else
     gtk_button_set_label (btn, "Hello.");
 }
 
static void click2_cb (GtkButton *btn, GtkWindow *win) {
   gtk_window_destroy (win);
 }
