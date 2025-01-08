#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell(const char *message) {
    // Simulating a notification, this is the same as your cmd notification
    char command[512];
    snprintf(command, sizeof(command), "cmd notification post -S bigtext -t '🍃 Never Line ' 'Tag' '%s' > /dev/null 2>&1", message);
    system(command);
}

int main() {
    char svc[1000];
    char cmd[1050];
    char AOT[1050];
    FILE *fp;

    // Membuka proses untuk menjalankan perintah dan membaca output-nya
    fp = popen("pm list package google | cut -f2 -d:", "r");
    if (fp == NULL) {
        printf("Gagal menjalankan perintah.\n");
        return 1;
    }

    // Output Object Aplikasi And status standby 
    printf("\n• Object :\n");

    // Membaca semua output dari perintah baris demi baris
    while (fgets(svc, sizeof(svc), fp) != NULL) {
        // Menghapus newline di akhir string
        svc[strcspn(svc, "\n")] = '\0';

        // Membuat perintah untuk set standby bucket
        sprintf(cmd, "cmd activity set-standby-bucket --user 0 %s never", svc);
        system(cmd);

        // Membuat perintah untuk mendapatkan status standby bucket
        sprintf(cmd, "cmd activity get-standby-bucket --user 0 %s", svc);

        // Membaca output status standby bucket
        FILE *fp_status = popen(cmd, "r");
        if (fp_status != NULL) {
            while (fgets(AOT, sizeof(AOT), fp_status) != NULL) {
                AOT[strcspn(AOT, "\n")] = '\0';
                printf("  - Status Standby: %s\n", AOT);
            }
            pclose(fp_status);
        }

        // Menampilkan output objek
        printf("  - %s\n", svc);
    }
    printf("\n\n");
    printf(" ⚠️ Module ini dilindungi oleh hak cipta dan hanya\n");
    printf(" dapat digunakan oleh pengguna biasa Penggunaan ini\n");
    printf(" tidak diperbolehkan untuk pengembang lain, termasuk\n");
    printf(" penggunaan kode, desain, atau fitur lain dalam module\n");
    printf(" tanpa izin tertulis dari pemilik hak cipta module.\n");
    printf("______________________________________________(+)\n");
    printf("\n");
    // Menutup proses
  shell("Successfully standby ");
    pclose(fp);

    return 0;
}