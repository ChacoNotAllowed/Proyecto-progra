#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;


class Movie {

private:

    string moviename = "";
    string movieyear = "";
    string movieduration = "";
    string moviecountry = "";
    string moviereview = "";


public:

    void setMovieName(string name) {
        moviename = name;
    }

    void setMovieYear(string year) {
        movieyear = year;
    }

    void setMovieDuration(string duration) {
        movieduration = duration;
    }

    void setMovieCountry(string country) {
        moviecountry = country;
    }

    void setMovieReview(string review) {
        moviereview = review;
    }

    string getMovieName() {
        return moviename;
    }

    string getMovieYear() {
        return movieyear;
    }

    string getMovieDuration() {
        return movieduration;
    }

    string getMovieCountry() {
        return moviecountry;
    }

    string getMovieReview() {
        return moviereview;
    }

    void PrintMovieDetails() {

        cout << "Nombre: " << moviename << endl;
        cout << "Año: " << movieyear << endl;
        cout << "Duracion: " << movieduration << endl;
        cout << "Pais: " << moviecountry << endl;
        cout << "Reseña: " << moviereview << endl;
        cout << "----------------------------" << endl;
    }
   
};


class Movies {

private:

    Movie movies[3];

public:

    void FillMovies();
    void PrintMovies();
    void PrintMovie(int option);
};

void Movies::FillMovies() {

    movies[0].setMovieName("Deadpool vs Wolverine");
    movies[0].setMovieYear("2024");
    movies[0].setMovieDuration("128 minutos");
    movies[0].setMovieCountry("USA");
    movies[0].setMovieReview("Esta muy buena FR");

    movies[1].setMovieName("Mi villano favorito 4");
    movies[1].setMovieYear("2024");
    movies[1].setMovieDuration("94 minutos");
    movies[1].setMovieCountry("USA");
    movies[1].setMovieReview("Pues normal");

    movies[2].setMovieName("Intensamente 2");
    movies[2].setMovieYear("2024");
    movies[2].setMovieDuration("96 minutos");
    movies[2].setMovieCountry("USA");
    movies[2].setMovieReview("Ni idea no soy psicologo");
}

void Movies::PrintMovies() {

    for (int i=0; i < 3; i++) {

        cout << "Pelicula " << (i + 1) << ":" << endl;
        movies[i].PrintMovieDetails();
    }

}
void Movies::PrintMovie(int option) {

    cout << movies[option-1].getMovieName() << endl;
 

}

class Seat{

private:

    int seatnumber;
    char seatrow;
    char seatstate;


public:

    void setSeatNumber(int number) {
        seatnumber = number;
    }

    void setSeatRow(char row) {
        seatrow = row;
    }

    void setSeatState(char state) {
        seatstate = state;
    }

    int getSeatNumber() {
        return seatnumber;
    }

    char getSeatRow() {
        return seatrow;
    }

    char getSeatState() {
        return seatstate;
    }

    void PrintSeatDetails() {

        cout << "Numero de asiento : " << seatrow << seatnumber << endl;
        cout << "Estado : " << seatstate << endl;
        cout << "----------------------------" << endl;
    }
    
};

class Theater {

private:
    
    Seat seats[12][12];

public:

    void FillSeats();
    void PrintSeats();
    void ReserveSeat(int row, int seatnum);
    void BuySeat(int row, int seatnum);
};

void Theater::FillSeats() {

    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++) {

            seats[i][j].setSeatNumber(j + 1);
            seats[i][j].setSeatRow(i + 65);
            seats[i][j].setSeatState(0);
        }
    }
}

void Theater::PrintSeats() {

    char cuadrado=177;
    char libre =' ';
    char reservado = 207;
    char comprado = 158;
    
    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++) {

            cout << cuadrado << " " << seats[i][j].getSeatRow() << seats[i][j].getSeatNumber();

            if (seats[i][j].getSeatState() == 0) {
                cout << " " << libre << " ";
            } 
            else if (seats[i][j].getSeatState() == 1) {
                cout << " " << reservado << " ";
            }
            else if (seats[i][j].getSeatState() == 2) {
                cout << " " << comprado << " ";
            }

        }
        cout << cuadrado;
        cout << endl<<endl;
     
    }
    cout << endl;
    cout << libre << " = Asiento Libre" << endl << reservado << " = Asiento Reservado" << endl << comprado << " = Asiento Comprado" <<endl<< "Cada Asiento tiene un costo de $5 " << endl<<endl;

}
void Theater::ReserveSeat(int row, int seatnum) {

    seats[row][seatnum].setSeatState(1);

}
void Theater::BuySeat(int row, int seatnum) {

    if (seats[row][seatnum].getSeatState() == 1) {

        seats[row][seatnum].setSeatState(2);
    }

}

class Theaters {

private:

    Theater theater[3];

public:

    void FillTheaters();
    void PrintTheater(int theater);
    void ReserveTheaterSeat(int theaternum,int row, int seatnum);
    void BuyTheaterSeat(int theaternum, int row, int seatnum);

};

void Theaters::ReserveTheaterSeat(int theaternum, int row, int seatnum) {

    theater[theaternum].ReserveSeat(row, seatnum);
}

void Theaters::BuyTheaterSeat(int theaternum, int row, int seatnum) {

    theater[theaternum].BuySeat(row, seatnum);
}

void Theaters::FillTheaters() {

    for (int i = 0; i < 3; i++) {

        theater[i].FillSeats();
    }
}

void Theaters::PrintTheater(int option) {

    theater[option-1].PrintSeats();
}




class Menu {

public:
    Movies moviesCollection;
    Theaters theatersCollection;
    void ShowMenu();
    void RunMenu(int option);
    void PrintAbout();
};


void Menu::ShowMenu(){

    cout << "===== Menu =====" << endl;
    cout << "1. Archivo" << endl;
    cout << "2. Mantenimiento" << endl;
    cout << "3. Reserva" << endl;
    cout << "4. Venta" << endl<<endl;
    cout << "Elija una opcion: "<<endl;

}

void Menu::PrintAbout() {

    cout << endl;
    cout << "  _   _           _         " << endl;
    cout << " | | | |   ___   | |   __ _ " << endl;
    cout << " | |_| |  / _ \\  | |  / _` |" << endl;
    cout << " |  _  | | (_) | | | | (_| |" << endl;
    cout << " |_| |_|  \\___/  |_|  \\__,_|" << endl;
    cout << endl << endl;
    cout << endl;
    cout << " ____                  " << endl;
    cout << "/ ___|    ___    _   _ " << endl;
    cout << "\\___ \\   / _ \\  | | | |" << endl;
    cout << " ___) | | (_) | | |_| |" << endl;
    cout << "|____/   \\___/   \\__, |" << endl;
    cout << "                  |___/ " << endl;
    cout << endl;
    cout << endl;
    cout << "  ___                              " << endl;
    cout << " |_ _|  ___    __ _    __ _    ___ " << endl;
    cout << "  | |  / __|  / _` |  / _` |  / __|" << endl;
    cout << "  | |  \\__ \\ | (_| | | (_| | | (__ " << endl;
    cout << " |___| |___/  \\__,_|  \\__,_|  \\___|" << endl;
    cout << endl;
}

void Menu::RunMenu(int option) {   

    switch (option) {

    case 1:

        cout << "1. Acerca de" << endl;
        cout << "2. Salir" << endl<<endl;
        cout << "Elija una opcion: " << endl;
        int option2;
        cin >> option2;
        cout << endl;
        system("cls");

        switch (option2)
        {

        case 1:

            PrintAbout();

            break;

        case 2:

            exit(0);

        default:
            cout << "Opcion no valida " << endl;
            break;
        }

        break;

    case 2:

        cout << "===== Mantenimiento =====" << endl;
        cout << "1. Peliculas" << endl;
        cout << "2. Salas" << endl;
        cout << "3. Horarios " << endl<<endl;
        cout << "Elija una opcion: " << endl;

        int option3;
        cin >> option3;
        cout << endl;
        system("cls");

        switch (option3)
        {

        case 1:

            moviesCollection.PrintMovies();
            break;
        case 2:
            
            cout << "===== Salas =====" << endl;
            cout << "1. Sala 1" << endl;
            cout << "2. Sala 2" << endl;
            cout << "3. Sala 3" << endl << endl;
            cout << "Elija una sala: " << endl;

            int option4;
            cin >> option4;
            cout << endl;
            system("cls");

            cout << "===== Sala "<<option4<<" =====" << endl<<endl;
            theatersCollection.PrintTheater(option4);
            break;

        case 3:
            cout << "Horario (en proceso porque pienso agregarlo dentro de cada sala y peli)/n";
            break;

        default:
            cout << "Opcion no valida " << endl;
            break;
        }

        break;

        
    case 3:

        cout << "===== Reserva =====" << endl;
        cout << "1. Deadpool vs Wolverine" << endl;
        cout << "2. Mi villano favorito 4" << endl;
        cout << "3. Intensamente 2" << endl <<endl<<"Recuerde que cada pelicula tiene una sala predeterminada" << endl;
        cout << "Elija una Pelicula: " << endl;
        int movieop;
        cin >> movieop;
        system("cls");

        moviesCollection.PrintMovie(movieop);
        cout << "===== Sala " << movieop << " =====" << endl << endl;
        theatersCollection.PrintTheater(movieop);

        cout << "Elija la fila de su asiento: " << endl;
        char seatrow;
        cin >> seatrow; cout << endl;
        cout << "Elija el numero de su asiento: " << endl;
        int seatnum;
        cin >> seatnum; cout << endl;
        system("cls");
        theatersCollection.ReserveTheaterSeat(movieop - 1, toupper(seatrow) -'A', seatnum - 1);

        moviesCollection.PrintMovie(movieop);
        cout << "===== Sala " << movieop << " =====" << endl << endl;
        theatersCollection.PrintTheater(movieop);
        

        break;

    case 4:

        cout << "===== Compra =====" << endl;
        cout << "1. Deadpool vs Wolverine" << endl;
        cout << "2. Mi villano favorito 4" << endl;
        cout << "3. Intensamente 2" << endl << endl << "Recuerde que requiere reservar el asiento primero" << endl;
        cout << "Elija una Pelicula: " << endl;
        int movieop2;
        cin >> movieop2;
        system("cls");

        theatersCollection.PrintTheater(movieop2);

        cout << "Desea comprar un asiento individual o desea comprar todos los reservados?" << endl << endl;
        cout << "1. Asiento individual" << endl;
        cout << "2. Todos los reservados" << endl;
        int seatop;
        cin >> seatop;
        system("cls");

        switch (seatop)
        {
        case 1:

            cout << "Elija la fila de su asiento: " << endl;
            char seatrow;
            cin >> seatrow; cout << endl;
            cout << "Elija el numero de su asiento: " << endl;
            int seatnum;
            cin >> seatnum; cout << endl;
            system("cls");
            theatersCollection.BuyTheaterSeat(movieop2 - 1, toupper(seatrow) - 'A', seatnum - 1);

            moviesCollection.PrintMovie(movieop2);
            cout << "===== Sala " << movieop2 << " =====" << endl << endl;
            theatersCollection.PrintTheater(movieop2);
            system("pause");

            break;

        case 2:

            for (int i = 0; i < 12; i++) {

                for (int j = 0; j < 12; j++) {

                    theatersCollection.BuyTheaterSeat(movieop2-1, i, j);                 
                }
            }

            moviesCollection.PrintMovie(movieop2);
            cout << "===== Sala " << movieop2 << " =====" << endl << endl;
            theatersCollection.PrintTheater(movieop2);

            break;

        default:
            break;
        }

        break;

    default:
        cout << "Opcion no valida " << endl;
        break;
    }

}





int main() {

    Menu menu;
    menu.moviesCollection.FillMovies();
    menu.theatersCollection.FillTheaters();
    int option;

    do {
        system("pause");
        system("cls");
        menu.ShowMenu();
        cin >> option;
        cout << endl;
        menu.RunMenu(option);
    } while (option < 5 && option > 0) ;

}