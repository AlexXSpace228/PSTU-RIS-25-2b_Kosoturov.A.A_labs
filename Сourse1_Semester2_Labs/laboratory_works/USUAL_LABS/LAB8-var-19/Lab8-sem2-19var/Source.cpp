#include <iostream>
#include <cstdio>
#include <cstring>

struct Movie
{
    char title[30];
    char author[20];
    char country[20];
    int profit;

    void input()
    {
        std::cout << "Title: ";
        std::cin >> title;

        std::cout << "Director: ";
        std::cin >> author;

        std::cout << "Country: ";
        std::cin >> country;

        std::cout << "Profit: ";
        std::cin >> profit;

        std::cout << "-----------------\n";
    }

    void print()
    {
        std::cout << title << " | "
            << author << " | "
            << country << " | "
            << profit << "\n";
    }
};

void deleteLastTwo()
{
    FILE* f;
    fopen_s(&f, "data.bin", "rb");

    if (!f) return;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);

    int count = size / sizeof(Movie);
    int newCount = count - 2;

    if (newCount < 0) newCount = 0;

    FILE* temp;
    fopen_s(&temp, "temp.bin", "wb");

    rewind(f);

    Movie m;

    for (int i = 0; i < newCount; i++)
    {
        fread(&m, sizeof(Movie), 1, f);
        fwrite(&m, sizeof(Movie), 1, temp);
    }

    fclose(f);
    fclose(temp);

    remove("data.bin");
    rename("temp.bin", "data.bin");
}

void addAfterTitle()
{
    FILE* f;
    FILE* temp;

    fopen_s(&f, "data.bin", "rb");
    fopen_s(&temp, "temp.bin", "wb");

    if (!f || !temp) return;

    char target[30];

    std::cout << "Enter title after which to insert: ";
    std::cin >> target;

    Movie newMovie;
    std::cout << "Enter new movie:\n";
    newMovie.input();

    Movie m;

    while (fread(&m, sizeof(Movie), 1, f))
    {
        fwrite(&m, sizeof(Movie), 1, temp);

        if (strcmp(m.title, target) == 0)
        {
            fwrite(&newMovie, sizeof(Movie), 1, temp);
        }
    }

    fclose(f);
    fclose(temp);

    remove("data.bin");
    rename("temp.bin", "data.bin");
}

void printFile()
{
    FILE* f;
    fopen_s(&f, "data.bin", "rb");

    if (!f) return;

    Movie m;

    std::cout << "\nMovies in file:\n";

    while (fread(&m, sizeof(Movie), 1, f))
        m.print();

    fclose(f);
}

int main()
{
    FILE* f;
    fopen_s(&f, "data.bin", "wb");

    Movie m;

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Movie " << i + 1 << "\n";
        m.input();
        fwrite(&m, sizeof(Movie), 1, f);
    }

    fclose(f);

    deleteLastTwo();

    printFile();

    addAfterTitle();

    printFile();

    return 0;
}