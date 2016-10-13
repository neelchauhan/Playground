#include <gtk/gtk.h>
#include <stdio.h>

static void destroy(GtkWidget *widget, gpointer data) {
	gtk_main_quit();
}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello World!");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

	GtkWidget *grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	GtkWidget *button1 = gtk_button_new_with_label("Button 1");
	gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);

	GtkWidget *label2 = gtk_label_new("Label 2");
	gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);

	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
