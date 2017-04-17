#include <stdio.h>
#include <string.h>
#include <glib.h>

void count_words(FILE *file, GHashTable *hash)
{
    char word[256];
    int count;

    while (fscanf(file, "%s", word) == 1) {
        count = GPOINTER_TO_INT(g_hash_table_lookup(hash, word));
        g_hash_table_insert(hash, strdup(word), GINT_TO_POINTER(count + 1));
    }
}

void print_word_count(gpointer key, gpointer value, gpointer user_data)
{
    printf("%s: %d\n", key, GPOINTER_TO_INT(value));
}

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);

    count_words(file, hash);
    fclose(file);

    g_hash_table_foreach(hash, print_word_count, NULL);
    return 0;
}
