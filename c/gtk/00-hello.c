#include <gtk/gtk.h>
#include <stdio.h>

static void destroy(GtkWidget *widget, gpointer data) {
	gtk_main_quit();
}

static void print_hi(GtkWidget *widget, gpointer data) {
	printf("Hi!\n");
	destroy(widget, data);
}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello World!");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

	GtkWidget *button = gtk_button_new_with_label("Hello World!");
	gtk_container_add(GTK_CONTAINER(window), button);
	g_signal_connect(button, "clicked", G_CALLBACK(print_hi), NULL);

	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
