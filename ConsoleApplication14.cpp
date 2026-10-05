#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Book
{
    string name;
    string author;
    string publisher;
    string genre;
    int year;
    double price;
};

// Вивід усіх книг
void Show(Book* books, int size)
{
    if (size == 0)
    {
        cout << "Biblioteka porozhnya!\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "\n--- Kniga " << i + 1 << " ---\n";
        cout << "Nazva: " << books[i].name << endl;
        cout << "Avtor: " << books[i].author << endl;
        cout << "Vydavnytstvo: " << books[i].publisher << endl;
        cout << "Zhanr: " << books[i].genre << endl;
        cout << "Rik vydannya: " << books[i].year << endl;
        cout << "Cena: " << books[i].price << " грн\n";
    }
}

// Редагування книги
void ChangeData(Book* books, int size)
{
    int number;
    cout << "Vvedit nomer knyhy: ";
    cin >> number;
    cin.ignore();

    if (number < 1 || number > size)
    {
        cout << "Nekorektnyi nomer!\n";
        return;
    }

    number--;

    cout << "Nova nazva: ";
    getline(cin, books[number].name);

    cout << "Novyi avtor: ";
    getline(cin, books[number].author);

    cout << "Nove vydavnytstvo: ";
    getline(cin, books[number].publisher);

    cout << "Novyi zhanr: ";
    getline(cin, books[number].genre);

    cout << "Novyi rik: ";
    cin >> books[number].year;

    cout << "Nova cena: ";
    cin >> books[number].price;

    cout << "Knigu zmineno!\n";
}

// Пошук за автором
void SearchAuthor(Book* books, int size)
{
    string author;
    cin.ignore();
    cout << "Vvedit avtora: ";
    getline(cin, author);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].author == author)
        {
            cout << "\nKniga: " << books[i].name
                << ", Avtor: " << books[i].author
                << ", Cena: " << books[i].price << " грн\n";
            found = true;
        }
    }

    if (!found)
        cout << "Knig ne znaideno!\n";
}

// Пошук за назвою
void SearchName(Book* books, int size)
{
    string name;
    cin.ignore();
    cout << "Vvedit nazvu: ";
    getline(cin, name);

    for (int i = 0; i < size; i++)
    {
        if (books[i].name == name)
        {
            cout << "\nKnigu znaideno!\n";
            cout << "Avtor: " << books[i].author << endl;
            cout << "Vydavnytstvo: " << books[i].publisher << endl;
            cout << "Zhanr: " << books[i].genre << endl;
            cout << "Rik: " << books[i].year << endl;
            cout << "Cena: " << books[i].price << " грн\n";
            return;
        }
    }

    cout << "Knigu ne znaideno!\n";
}

// Пошук за видавництвом
void SearchPublisher(Book* books, int size)
{
    string publisher;
    cin.ignore();
    cout << "Vvedit vydavnytstvo: ";
    getline(cin, publisher);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].publisher == publisher)
        {
            cout << "\n" << books[i].name
                << " - " << books[i].author << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Knig ne znaideno!\n";
}

// Пошук за жанром
void SearchGenre(Book* books, int size)
{
    string genre;
    cin.ignore();
    cout << "Vvedit zhanr: ";
    getline(cin, genre);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].genre == genre)
        {
            cout << "\n" << books[i].name
                << " - " << books[i].author << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Knig ne znaideno!\n";
}

// Зміна ціни
void ChangePrice(Book* books, int size)
{
    int number;
    cout << "Vvedit nomer knyhy: ";
    cin >> number;

    if (number < 1 || number > size)
    {
        cout << "Nekorektnyi nomer!\n";
        return;
    }

    cout << "Nova cena: ";
    cin >> books[number - 1].price;

    cout << "Cinu zmineno!\n";
}

// Додавання книги
void AddBook(Book*& books, int& size)
{
    Book* newBooks = new Book[size + 1];

    for (int i = 0; i < size; i++)
        newBooks[i] = books[i];

    cin.ignore();

    cout << "Nazva: ";
    getline(cin, newBooks[size].name);

    cout << "Avtor: ";
    getline(cin, newBooks[size].author);

    cout << "Vydavnytstvo: ";
    getline(cin, newBooks[size].publisher);

    cout << "Zhanr: ";
    getline(cin, newBooks[size].genre);

    cout << "Rik vydannya: ";
    cin >> newBooks[size].year;

    cout << "Cena: ";
    cin >> newBooks[size].price;

    delete[] books;

    books = newBooks;
    size++;

    cout << "Knigu dodano!\n";
}

// Видалення книги
void DeleteBook(Book*& books, int& size)
{
    int number;

    cout << "Vvedit nomer knyhy: ";
    cin >> number;

    if (number < 1 || number > size)
    {
        cout << "Nekorektnyi nomer!\n";
        return;
    }

    Book* newBooks = new Book[size - 1];

    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != number - 1)
        {
            newBooks[j] = books[i];
            j++;
        }
    }

    delete[] books;

    books = newBooks;
    size--;

    cout << "Knigu vydaleno!\n";
}

int main()
{
    int size = 10;

    Book* books = new Book[size]
    {
        {"Kobzar", "Taras Shevchenko", "Osnovy", "Poeziya", 1840, 250},
        {"Lisova Pisnya", "Lesya Ukrainka", "Veselka", "Drama", 1911, 220},
        {"Zahar Berkut", "Ivan Franko", "A-BA-BA-GA-LA-MA", "Povist", 1883, 300},
        {"Harry Potter", "J.K. Rowling", "Bloomsbury", "Fantasy", 1997, 450},
        {"1984", "George Orwell", "Penguin", "Antiutopiya", 1949, 350},
        {"Hobbit", "J.R.R. Tolkien", "HarperCollins", "Fantasy", 1937, 400},
        {"It", "Stephen King", "Vivat", "Horror", 1986, 500},
        {"Alchemist", "Paulo Coelho", "HarperOne", "Roman", 1988, 280},
        {"Sherlock Holmes", "Arthur Conan Doyle", "Penguin", "Detective", 1887, 320},
        {"The Little Prince", "Antoine de Saint-Exupery", "Gallimard", "Kazka", 1943, 200}
    };

    int choice;

    do
    {
        cout << "\n========== BIBLIOTEKA ==========\n";
        cout << "1. Pokazaty vsi knyhy\n";
        cout << "2. Redahuvaty knyhu\n";
        cout << "3. Poshuk za avtorom\n";
        cout << "4. Poshuk za nazvoyu\n";
        cout << "5. Poshuk za vydavnytstvom\n";
        cout << "6. Poshuk za zhanrom\n";
        cout << "7. Zminyty cenu\n";
        cout << "8. Dodaty novu knyhu\n";
        cout << "9. Vydalyty knyhu\n";
        cout << "0. Vyhid\n";
        cout << "================================\n";
        cout << "Vyberit diyu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Show(books, size);
            break;

        case 2:
            ChangeData(books, size);
            break;

        case 3:
            SearchAuthor(books, size);
            break;

        case 4:
            SearchName(books, size);
            break;

        case 5:
            SearchPublisher(books, size);
            break;

        case 6:
            SearchGenre(books, size);
            break;

        case 7:
            ChangePrice(books, size);
            break;

        case 8:
            AddBook(books, size);
            break;

        case 9:
            DeleteBook(books, size);
            break;

        case 0:
            cout << "Vyhid z prohramy...\n";
            break;

        default:
            cout << "Nekorektnyi vybir!\n";
        }

    } while (choice != 0);

    delete[] books;

    return 0;
}
