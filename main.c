#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "prediction.h"
#include "gui.h"
#include <string.h>
#include <gtk/gtk.h>

void test(char* dictfr){
    FILE* f;
    f = fopen(dictfr,"r");
    if(f!=NULL){
        char word[LENGTH_WORD];
        while(fscanf(f,"%s",word)==1){
            if(99999999-HashFunctionFeequent(word)<0){
                printf("%s %lld\n",word,HashFunctionFeequent(word));
            }
        }
    }
    fclose(f);
}

  
//  #include <gtk/gtk.h>
  
  static void
  click1_cb (GtkButton *btn) {
    const char *s;
  
    s = gtk_button_get_label (btn);
    if (g_strcmp0 (s, "Hello.") == 0)
      gtk_button_set_label (btn, "Good-bye.");
   else
     gtk_button_set_label (btn, "Hello.");
 }
 
 static void
 click2_cb (GtkButton *btn, GtkWindow *win) {
   gtk_window_destroy (win);
 }
 
 static void
 app_activate (GApplication *app) {
   GtkWidget *win;
   GtkWidget *box;
   GtkWidget *btn1;
   GtkWidget *btn2;
 
   win = gtk_application_window_new (GTK_APPLICATION (app));
   gtk_window_set_title (GTK_WINDOW (win), "lb4");
   gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);
 
   box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
   gtk_box_set_homogeneous (GTK_BOX (box), TRUE);
   gtk_window_set_child (GTK_WINDOW (win), box);
 
   btn1 = gtk_button_new_with_label ("Hello.");
   g_signal_connect (btn1, "clicked", G_CALLBACK (click1_cb), NULL);
 
   btn2 = gtk_button_new_with_label ("Close");
   g_signal_connect (btn2, "clicked", G_CALLBACK (click2_cb), win);
 
   gtk_box_append (GTK_BOX (box), btn1);
   gtk_box_append (GTK_BOX (box), btn2);
 
   gtk_window_present (GTK_WINDOW (win));
 }
 
 int
 main (int argc, char **argv) {
   GtkApplication *app;
   int stat;
 
   app = gtk_application_new ("com.github.ToshioCP.lb4", G_APPLICATION_FLAGS_NONE);
   g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
   stat =g_application_run (G_APPLICATION (app), argc, argv);
   g_object_unref (app);
   return stat;
 }
 

// void main(){
//     FrequentWordTab hashtab;
//     InitializeFrequentWordTab(&hashtab);
//     //test("ods6.txt");
//     AddAllDictionnary(&hashtab,"ods6.txt");
//     //printf(" test :%lld\n",HashFunctionFeequent("cacadd"));
//     //ShowDictionnary(&hashtab);
//     AddPersonalDict(&hashtab,"mots_courants.txt");
//     //ShowPersonalDictionnary(&hashtab);
//     //printf("%d",CheckExistence(&hashtab,"test"));

//     // Element* p1;
//     // Element* p2;
//     // Element* p3;
//     // p1 = (Element*) malloc(sizeof(Element));
//     // p2 = (Element*) malloc(sizeof(Element));
//     // p3 = (Element*) malloc(sizeof(Element));
//     // //printf(" test :%lld\n",HashFunctionFeequent("es"));
//     // PropositionFreq(&hashtab,"zt",p1,p2,p3,0);
//     // printf("%s %s %s\n",p1->word,p2->word,p3->word);
    
// }





// #include <ncurses.h>

// int main() {
//     char str[100];
//     int ch, i = 0;

//     initscr();
//     cbreak();
//     noecho();
//     keypad(stdscr, TRUE);

//     printw("Enter a string (press Ctrl + G to exit): ");

//     while ((ch = getch()) != 7) { // Ctrl + G
//         printf("%s",str);
//         if (ch == KEY_BACKSPACE && i > 0) {
//             i--;
//             str[i] = '\0';
//             printw("\b \b");
//         } else if (ch >= 32 && ch <= 126 && i < 99) {
//             str[i] = (char) ch;
//             i++;
//             str[i] = '\0';
//             printw("%c", ch);
//         }
//     }

//     endwin();

//     printf("\nYou entered: %s\n", str);

//     return 0;
// }

// ouiiiiiiii
// #include <stdio.h>
// #include <ncurses.h>

// char* add_char_to_string(char* str, char c) {
//     int len = strlen(str);
//     char* new_str = (char*) malloc(len + 2);
//     strcpy(new_str, str);
//     new_str[len] = c;
//     new_str[len + 1] = '\0';
//     return new_str;
// }

// int main() {
//     int i = 0;
//     char* test;
//     test = (char*) malloc(30*sizeof(char));
//     char ch;
//     initscr(); // initialize ncurses mode
//     cbreak(); // disable line buffering
//     noecho(); // disable input echoing
//     keypad(stdscr, TRUE); // enable special key handling
//     while ((ch = getch()) != '\n') {
//         test[i] = ch;
//         //add_char_to_string(test,ch);
//         printf("You typed: %s\n", test);
//         i++;
//     }

//     endwin(); // end ncurses mode
//     //add_char_to_string(test,'c');
//     //printf("You typed: %s\n", test);

//     return 0;
// }

