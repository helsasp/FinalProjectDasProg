#include <stdio.h>
#include <stdlib.h>

void inputmahasiswa();
void lihatdatamahasiswa();
void carimahasiswa();
void inputdosen();
void lihatdatadosen();
void caridosen();
void inputmatkul();
void lihatdatamatkul();
void carimatkul();

struct mahasiswa
{
    char nama_depan[20];
    char nama_belakang[20];
    int nrp;
    char kelas[10];
    char email[20];
    float ipk;
};

struct dosen
{
    char nama_depan[20];
    char nama_belakang[20];
    int nip;
    char fakultas[10];
    char email[20];
};

struct matkul
{
    int id;
    char nama[100];
    char namados[100];
    char namapes[100];
};

void main()
{

    int pilihan;
    while (pilihan != 0)
    {

        printf("\t\t\t=====DATABASE DOSEN DAN MAHASISWA=====");
        printf("\n\n\t=====INSTITUT TEKNOLOGI SEPULUH NOPEMBER SURABAYA 2022/2023=====");
        printf("\n\n\n\t\t\t\t     1. Input Data Mahasiswa\n");
        printf("\t\t\t\t     2. Lihat Data Mahasiswa\n");
        printf("\t\t\t\t     3. Cari Data Mahasiswa\n");
        printf("\t\t\t\t     4. Input Data Dosen\n");
        printf("\t\t\t\t     5. Lihat Data Dosen\n");
        printf("\t\t\t\t     6. Cari Data Dosen\n");
        printf("\t\t\t\t     7. Input Data Mata Kuliah\n");
        printf("\t\t\t\t     8. Lihat Data Mata Kuliah\n");
        printf("\t\t\t\t     9. Cari Data Matkul\n");
        printf("\t\t\t\t     0. Exit\n");
        printf("\t\t\t\t    _______\n");
        printf("\t\t\t\t     ");

        printf("Masukkan pilihan!\n");
        printf("\t\t\t\t     ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            system("cls");
            inputmahasiswa();
            system("cls");
            break;
        case 2:
            system("cls");

            lihatdatamahasiswa();
            printf("\t\t\t\t  press any key to exit..... \n");
            getchar();
            system("cls");

            break;

        case 3:
            system("cls");

            carimahasiswa();
            printf("\t\t\t\t  press any key to exit..... \n");
            getchar();
            system("cls");

            break;

        case 4:
            system("cls");
            inputdosen();
            system("cls");
            break;

        case 5:
            system("cls");

            lihatdatadosen();
            printf("\t\t\t\t  press any key to exit..... \n");
            getchar();
            system("cls");

            break;

        case 6:
            system("cls");

            caridosen();
            printf("\t\t\t\t  press any key to exit..... \n");
            getchar();
            system("cls");

            break;

        case 7:
            system("cls");
            inputmatkul();
            system("cls");
            break;

        case 8:
            system("cls");

            lihatdatamatkul();
            printf("\t\t\t\t  press any key to exit..... \n");
            getchar();
            system("cls");

            break;

        case 9:
            system("cls");

            carimatkul();
            printf("\t\t\t\t  press any key to exit..... \n");
            getchar();
            system("cls");

            break;

        default:
            system("cls");
            getchar();
            printf("\n\t\t\t\t\tMasukkan angka yang benar!\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getchar();
            system("cls");
            break;
        }
    }

    getchar();
}

void inputmahasiswa()
{

    char jwb;
    FILE *fp;
    int n, i;
    struct mahasiswa mhs;
    do
    {
        system("cls");
        fp = fopen("datamahasiswa.dat", "a");

        printf("\t\t\t\t=======INPUT DATA MAHASISWA=======\n\n\n");

        printf("\n\t\t\tMasukkan Nama Depan    : ");
        scanf("%s", &mhs.nama_depan);
        printf("\n\t\t\tMasukkan Nama Belakang    : ");
        scanf("%s", &mhs.nama_belakang);
        printf("\n\t\t\tMasukkan NRP       : ");
        scanf("%d", &mhs.nrp);
        printf("\n\t\t\tMasukkan Kelas : ");
        scanf("%s", &mhs.kelas);
        printf("\n\t\t\tMasukkan Email       : ");
        scanf("%s", &mhs.email);
        printf("\n\t\t\tMasukkan IPK    : ");
        scanf("%f", &mhs.ipk);
        printf("\n\t\t\t____________\n");

        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tData berhasil disimpan!\n");
        }

        fwrite(&mhs, sizeof(struct mahasiswa), 1, fp);
        fclose(fp);

        printf("\t\t\tApakah ingin menambahkan data lagi?(y/n) : ");

        scanf("%s", &jwb);

    } while (jwb == 'y' || jwb == 'Y');
}

void lihatdatamahasiswa()
{

    FILE *fp;

    struct mahasiswa mhs;
    fp = fopen("datamahasiswa.dat", "r");

    printf("\t\t\t\t=======DATA MAHASISWA 2022/2023=======\n\n\n");

    if (fp == NULL)
    {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tDATA :\n");
        printf("\t\t\t\t_____\n\n");
    }

    while (fread(&mhs, sizeof(struct mahasiswa), 1, fp))
    {
        printf("\n\t\t\t\t Nama  : %s %s", mhs.nama_depan, mhs.nama_belakang);
        printf("\n\t\t\t\t NRP       : %d", mhs.nrp);
        printf("\n\t\t\t\t Kelas         : %s", mhs.kelas);
        printf("\n\t\t\t\t Email  : %s", mhs.email);
        printf("\n\t\t\t\t IPK    : %.1f", mhs.ipk);
        printf("\n\t\t\t\t ____________\n");
    }
    fclose(fp);
    getchar();
}

void carimahasiswa()
{
    struct mahasiswa mhs;
    FILE *fp;
    int nrp, ketemu = 0;

    fp = fopen("datamahasiswa.dat", "r");

    printf("\t\t\t\t=======MENCARI DATA MAHASISWA=======\n\n\n");
    printf("\t\t\tMasukkan NRP Mahasiswa : ");

    scanf("%d", &nrp);

    while (fread(&mhs, sizeof(struct mahasiswa), 1, fp) > 0)
    {

        if (mhs.nrp == nrp)
        {

            ketemu = 1;
            printf("\n\t\t\t\t Nama  : %s %s", mhs.nama_depan, mhs.nama_belakang);
            printf("\n\t\t\t\t NRP       : %d", mhs.nrp);
            printf("\n\t\t\t\t Kelas         : %s", mhs.kelas);
            printf("\n\t\t\t\t Email  : %s", mhs.email);
            printf("\n\t\t\t\t IPK    : %.1f", mhs.ipk);
            printf("\n\t\t\t\t ____________\n");
        }
    }

    if (!ketemu)
    {
        printf("\n\t\t\tTidak ada data yang dicari!\n");
    }

    fclose(fp);
    getchar();
}

void inputdosen()
{

    char jwb;
    FILE *fp;
    int n, i;
    struct dosen dsn;
    do
    {
        system("cls");
        fp = fopen("datadosen.dat", "a");

        printf("\t\t\t\t=======INPUT DATA DOSEN=======\n\n\n");

        printf("\n\t\t\tMasukkan Nama Depan    : ");
        scanf("%s", &dsn.nama_depan);
        printf("\n\t\t\tMasukkan Nama Belakang    : ");
        scanf("%s", &dsn.nama_belakang);
        printf("\n\t\t\tMasukkan NIP       : ");
        scanf("%d", &dsn.nip);
        printf("\n\t\t\tMasukkan Fakultas : ");
        scanf("%s", &dsn.fakultas);
        printf("\n\t\t\tMasukkan Email       : ");
        scanf("%s", &dsn.email);
        printf("\n\t\t\t____________\n");

        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tData berhasil disimpan!\n");
        }

        fwrite(&dsn, sizeof(struct dosen), 1, fp);
        fclose(fp);

        printf("\t\t\tApakah ingin menambahkan data lagi?(y/n) : ");

        scanf("%s", &jwb);

    } while (jwb == 'y' || jwb == 'Y');
}

void lihatdatadosen()
{

    FILE *fp;

    struct dosen dsn;
    fp = fopen("datadosen.dat", "r");

    printf("\t\t\t\t=======DATA DOSEN 2022/2023=======\n\n\n");

    if (fp == NULL)
    {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tDATA :\n");
        printf("\t\t\t\t_____\n\n");
    }

    while (fread(&dsn, sizeof(struct dosen), 1, fp))
    {
        printf("\n\t\t\t\t Nama  : %s %s", dsn.nama_depan, dsn.nama_belakang);
        printf("\n\t\t\t\t NIP       : %d", dsn.nip);
        printf("\n\t\t\t\t Fakultas         : %s", dsn.fakultas);
        printf("\n\t\t\t\t Email  : %s", dsn.email);
        printf("\n\t\t\t\t ____________\n");
    }
    fclose(fp);
    getchar();
}

void caridosen()
{
    struct dosen dsn;
    FILE *fp;
    int nip, ketemu = 0;

    fp = fopen("datadosen.dat", "r");

    printf("\t\t\t\t=======MENCARI DATA DOSEN=======\n\n\n");
    printf("\t\t\tMasukkan NIP Dosen : ");

    scanf("%d", &nip);

    while (fread(&dsn, sizeof(struct dosen), 1, fp) > 0)
    {

        if (dsn.nip == nip)
        {

            ketemu = 1;
            printf("\n\t\t\t\t Nama  : %s %s", dsn.nama_depan, dsn.nama_belakang);
            printf("\n\t\t\t\t NIP       : %d", dsn.nip);
            printf("\n\t\t\t\t Fakultas         : %s", dsn.fakultas);
            printf("\n\t\t\t\t Email  : %s", dsn.email);
            printf("\n\t\t\t\t ____________\n");
        }
    }

    if (!ketemu)
    {
        printf("\n\t\t\tTidak ada data yang dicari!\n");
    }

    fclose(fp);
    getchar();
}

void inputmatkul()
{

    char jwb;
    FILE *fp;
    int n, i;
    struct matkul mtk;
    do
    {
        system("cls");
        fp = fopen("datamatkul.dat", "a");

        printf("\t\t\t\t=======INPUT DATA MATA KULIAH=======\n\n\n");

        printf("\n\t\t\tMasukkan Nama Mata Kuliah    : ");
        scanf("%s", &mtk.nama);
        printf("\n\t\t\tMasukkan Kode Mata Kuliah       : ");
        scanf("%d", &mtk.id);
        printf("\n\t\t\tMasukkan Nama Dosen    : ");
        scanf("%s", &mtk.namados);
        printf("\n\t\t\tMasukkan Nama Peserta       : ");
        scanf("%s", &mtk.namapes);
        printf("\n\t\t\t____________\n");

        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tData berhasil disimpan!\n");
        }

        fwrite(&mtk, sizeof(struct matkul), 1, fp);
        fclose(fp);

        printf("\t\t\tApakah ingin menambahkan data lagi?(y/n) : ");

        scanf("%s", &jwb);

    } while (jwb == 'y' || jwb == 'Y');
}

void lihatdatamatkul()
{

    FILE *fp;

    struct matkul mtk;

    fp = fopen("datamatkul.dat", "r");

    printf("\t\t\t\t=======DATA MATA KULIAH 2022/2023=======\n\n\n");

    if (fp == NULL)
    {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tDATA :\n");
        printf("\t\t\t\t_____\n\n");
    }

    while (fread(&mtk, sizeof(struct matkul), 1, fp))
    {
        printf("\n\t\t\t\t Nama  : %s", mtk.nama);
        printf("\n\t\t\t\t Kode       : %d", mtk.id);
        printf("\n\t\t\t\t Nama Dosen  : %s", mtk.namados);
        printf("\n\t\t\t\t Nama Peserta  : %s", mtk.namapes);
        printf("\n\t\t\t\t ____________\n");
    }
    fclose(fp);
    getchar();
}

void carimatkul()
{
    struct matkul mtk;
    FILE *fp;
    int id, ketemu = 0;

    fp = fopen("datamatkul.dat", "r");

    printf("\t\t\t\t=======MENCARI DATA MATA KULIAH=======\n\n\n");
    printf("\t\t\tMasukkan ID Mata Kuliah : ");

    scanf("%d", &id);

    while (fread(&mtk, sizeof(struct matkul), 1, fp) > 0)
    {

        if (mtk.id == id)
        {

            ketemu = 1;
            printf("\n\t\t\t\t Nama  : %s", mtk.nama);
            printf("\n\t\t\t\t Kode       : %d", mtk.id);
            printf("\n\t\t\t\t Nama Dosen  : %s", mtk.namados);
            printf("\n\t\t\t\t Nama Peserta  : %s", mtk.namapes);
            printf("\n\t\t\t\t ____________\n");
        }
    }

    if (!ketemu)
    {
        printf("\n\t\t\tTidak ada data yang dicari!\n");
    }

    fclose(fp);
    getchar();
}