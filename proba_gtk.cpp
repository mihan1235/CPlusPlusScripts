#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

gchar *domain, *dns1, *dns2;

/* Массив из трех полей ввода. Первое предназначено
 для ввода имени домена, два вторых – [1] и [2] – для
  ввода IP-адресов серверов DNS */

GtkWidget *edit[3];

/* Наш файл */
FILE *resolv;

/* Функция записи в файл */
void writetofile( GtkWidget *widget,
               gpointer   data )
{

/* С помощью функции gtk_entry_get_text() мы получаем
 введенный пользователем текст из полей ввода */

domain = gtk_entry_get_text(GTK_ENTRY(edit[0]));
dns1 = gtk_entry_get_text(GTK_ENTRY(edit[1]));
dns2 = gtk_entry_get_text(GTK_ENTRY(edit[2]));

/* Выводим прочитанный текст на консоль */
g_print ("Domain %s\n", domain);
g_print ("DNS1 %s\n", dns1);
g_print ("DNS2 %s\n", dns2);

/* Перезаписываем файл resolv.conf в текущем каталоге */
if ((resolv = fopen("resolv.conf","w")) == NULL)
{
/* Наверное, нет места на диске или прав маловато... */
g_print ("ERR: Cannot to open resolve.conf file\n");
gtk_main_quit ();
}

/* Запись в файл */
fprintf(resolv,"domain %s\n",domain);
fprintf(resolv,"nameserver %s\n",dns1);
fprintf(resolv,"nameserver %s\n",dns2);
fclose(resolv);

}

/* Эта функция будет запущена, когда пользователь нажмет
 кнопку закрытия окна или кнопку Quit */

gint delete_event( GtkWidget *widget,
                   GdkEvent  *event,
                   gpointer   data )
{
/* Функция gtk_main_quit() используется для завершения
работы GTK-программы.
 Не нужно для этого использовать exit() */

    gtk_main_quit ();
    return(FALSE);
}

/* Когда пользователь введет текст и нажмет Enter, введенный
 им текст будет выведен на консоль */

void enter_callback( GtkWidget *widget,
                     GtkWidget *entry )
{
  domain = gtk_entry_get_text(GTK_ENTRY(entry));
  printf("Domain: %s\n", domain);
}


int main( int   argc,
          char *argv[] )
{

    GtkWidget *window; /* Окно */
    GtkWidget *button; /* Кнопка */
    GtkWidget *table; /* Таблица для размещения виджитов */
    GtkWidget *label; /* Надпись */
/* Как видите, все виджиты одного типа – GtkWidget, поэтому
мы могли бы обойтись даже тремя виджитами – для окна,
 таблицы и для всех остальных элементов GUI*/

    int i;

    /* Инициализация любой GTK-программы */
    gtk_init (&argc, &argv);

    /* Создаем новое окно */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* Устанавливаем заголовок окна */
    gtk_window_set_title (GTK_WINDOW (window), "Resolver");

    /* Устанавливаем реакцию на кнопку закрытия окна.
     Сигнал – delete_event
       Вызываем функцию delete_event(), которая описана выше */

    gtk_signal_connect (GTK_OBJECT (window), "delete_event",
                        GTK_SIGNAL_FUNC (delete_event), NULL);

    /* Устанавливаем рамку окна */
    gtk_container_set_border_width (GTK_CONTAINER (window), 20);

    /* Создаем таблицу 3x3 */
    table = gtk_table_new (3, 3, TRUE);

    /* Помещаем таблицу в контейнер. Обязательно! */
    gtk_container_add (GTK_CONTAINER (window), table);

    /* Рисуем надписи, помещаем их в ТАБЛИЦУ и отображаем.
     Обратите внимание, что в этом случае нам не нужно
      объявлять отдельную переменную для каждой надписи*/

    label = gtk_label_new("Domain: ");
    /* О координатах ячеек поговорим после этого листинга */
    gtk_table_attach_defaults (GTK_TABLE(table), label, 0, 1, 0, 1);
    gtk_widget_show (label);

    label = gtk_label_new("DNS #1: ");
    gtk_table_attach_defaults (GTK_TABLE(table), label, 0, 1, 1, 2);
    gtk_widget_show (label);

    label = gtk_label_new("DNS #2: ");
    gtk_table_attach_defaults (GTK_TABLE(table), label, 0, 1, 2, 3);
    gtk_widget_show (label);

    /* Заполняем наш массив полей ввода. По аналогии с Delphi, я назвал
 	массив edit[]*/
    for(i=0; i<3; i++)
    {
    /* Новое поле */
    edit[i] = gtk_entry_new();
    /* Если забыть этот оператор, пользователь ничего не сможет ввести */
    gtk_entry_set_editable(GTK_ENTRY(edit[i]), 1);
    /* Определяем одну для всех реакцию на сигнал activate – нажатие Enter*/
    gtk_signal_connect(GTK_OBJECT(edit[i]), "activate",
                       GTK_SIGNAL_FUNC(enter_callback),
                       edit[i]);
    /* Помещаем edit[i] в таблицу */
    gtk_table_attach_defaults (GTK_TABLE(table), edit[i], 1, 2, i, i+1);
    /* Показываем */
    gtk_widget_show (edit[i]);
    }

    /* Создаем кнопку "Ok", помещаем в таблицу,
     определяем реакцию на нажатие и показываем */
    button = gtk_button_new_with_label ("Ok");
    gtk_table_attach_defaults (GTK_TABLE(table), button, 2, 3, 0, 1);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(writetofile),NULL);
    gtk_widget_show (button);

    /* Тоже самое для кнопки Quit */
    button = gtk_button_new_with_label ("Quit");
    gtk_table_attach_defaults (GTK_TABLE(table), button, 2, 3, 2, 3);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(delete_event),NULL);
    gtk_widget_show (button);

    gtk_widget_show (table);   /* Показываем таблицу */
    gtk_widget_show (window); /* Показываем окно */

    /* Запускаем GTK-программу */
    gtk_main ();

    return 0;
}
