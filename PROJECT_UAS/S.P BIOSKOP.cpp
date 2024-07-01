#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Kelas Movie
class Movie {
private:
    string title;
    int duration;
    string genre;

public:
    Movie(const string& title, int duration, const string& genre)
        : title(title), duration(duration), genre(genre) {}

    string getTitle() const { return title; }
    int getDuration() const { return duration; }
    string getGenre() const { return genre; }

    void setTitle(const string& title) { this->title = title; }
    void setDuration(int duration) { this->duration = duration; }
    void setGenre(const string& genre) { this->genre = genre; }

    string toString() const {
        return "Movie(title=" + title + ", duration=" + to_string(duration) + ", genre=" + genre + ")";
    }
};

// Kelas Showtime
class Showtime {
private:
    Movie movie;
    string time;
    int availableSeats;
    vector<int> bookedSeats;

public:
    Showtime(const Movie& movie, const string& time, int availableSeats)
        : movie(movie), time(time), availableSeats(availableSeats) {}

    Movie getMovie() const { return movie; }
    string getTime() const { return time; }
    int getAvailableSeats() const { return availableSeats; }
    vector<int> getBookedSeats() const { return bookedSeats; }

    void bookSeat(int seatNumber) {
        if (find(bookedSeats.begin(), bookedSeats.end(), seatNumber) != bookedSeats.end()) {
            throw invalid_argument("Seat already booked");
        }
        if (seatNumber > availableSeats || seatNumber <= 0) {
            throw std::invalid_argument("Invalid seat number");
        }
        bookedSeats.push_back(seatNumber);
    }

    string toString() const {
        return "Showtime(movie=" + movie.toString() + ", time=" + time + ", availableSeats=" + std::to_string(availableSeats) + ")";
    }
};

// Kelas Ticket
class Ticket {
private:
    Showtime showtime;
    int seatNumber;
    string buyer;

public:
    Ticket(const Showtime& showtime, int seatNumber, const string& buyer)
        : showtime(showtime), seatNumber(seatNumber), buyer(buyer) {}

    Showtime getShowtime() const { return showtime; }
    int getSeatNumber() const { return seatNumber; }
    string getBuyer() const { return buyer; }

    string toString() const {
        return "Ticket(showtime=" + showtime.toString() + ", seatNumber=" + std::to_string(seatNumber) + ", buyer=" + buyer + ")";
    }
};

//ticket hisori
// Kelas TiketHistori
class TiketHistori {
private:
    vector<Ticket> tickets;

public:
    void addTicket(Ticket ticket) {
        tickets.push_back(ticket);
    }

    vector<Ticket> getTickets() const {
        return tickets;
    }

    void displayTiketHistory() {
        cout << "Riwayat Pemesanan tiket :" << endl;
        for (const auto& ticket : tickets) {
            cout << ticket.getShowtime().getMovie().getTitle() << "-film|  " << ticket.getSeatNumber() << " -seatnumber| " << endl;
        }
    }
};

// Kelas Cinema
class Cinema {
private:
    vector<Movie> movies;
    vector<Showtime> showtimes;
    vector<Ticket> tickets;
    TiketHistori tiketHistori;
    

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void removeMovie(const std::string& title) {
        movies.erase(std::remove_if(movies.begin(), movies.end(),
            [&title](const Movie& movie) { return movie.getTitle() == title; }), movies.end());
    }

    void addShowtime(const Showtime& showtime) {
        showtimes.push_back(showtime);
    }

    void removeShowtime(const string& time) {
        showtimes.erase(remove_if(showtimes.begin(), showtimes.end(),
            [&time](const Showtime& showtime) { return showtime.getTime() == time; }), showtimes.end());
    }

    vector<Movie> getMovies() const {
        return movies;
    }

    vector<Showtime> getShowtimes(const std::string& title) const {
        vector<Showtime> result;
        for (const Showtime& showtime : showtimes) {
            if (showtime.getMovie().getTitle() == title) {
                result.push_back(showtime);
            }
        }
        return result;
    }

    void bookTicket(float showtimeIndex, int seatNumber, const string& buyer) {
        if (showtimeIndex < 0|| showtimeIndex >= showtimes.size()) {
            throw invalid_argument("Invalid showtime index");
        }
        showtimes[showtimeIndex].bookSeat(seatNumber);
        tickets.emplace_back(showtimes[showtimeIndex], seatNumber, buyer);
        tiketHistori.addTicket(tickets.back());
        
    }
    

    vector<Ticket> getTickets() const {
        return tickets;
    }
    void displayTiketHistory() {
        tiketHistori.displayTiketHistory(); 
}
};




// Kelas Customer
class Customer {
private:
    string name;
    int customerId;

public:
    Customer(const string& name, int customerId)
        : name(name), customerId(customerId) {}

    string getName() const {
        return name;
    }

    int getCustomerId() const {
        return customerId;
    }

    string toString() const {
        return "Customer(name=" + name + ", customerId=" + std::to_string(customerId) + ")";
    }
};

// Fungsi untuk menampilkan menu
 void showMenu(){
    cout<<"                ###########  ## ########  ########  ##    ## #########  #########   ##     ## ##    ## ########        "<<endl;
    cout<<"                ##        ## ## ##    ##  ##        ##  ##   ##     ##  ##     ##    ##   ##   ##  ##  ########        "<<endl;
    cout<<"                ##        ## ## ##    ##  ##        ####     ##     ##  ##     ##     ## ##     ####       ###     "<<endl;
    cout<<"                ##########   ## ##    ##   ######   ####     ##     ##  #######        ###       ##       ###          "<<endl;
    cout<<"                ##        ## ## ##    ##         ## ## ##    ##     ##  ##            ## ##      ##     ###              "<<endl;
    cout<<"                ##        ## ## ##    ##         ## ##   ##  ##     ##  ##           ##   ##     ##   ###               " <<endl;
    cout<<"                ###########  ## ########  ########  ##   ##  ########   ##          ##     ##    ##  ##########                "<<endl;






    
    cout<<  "                                    =================================================="<<endl;
    cout << "                                    |         Sistem Pemesanan Tiket Bioskop         |" <<endl;
    cout << "                                    |         Selamat Datang di Bioskop XYZ          |" <<endl;
    cout<<  "                                    |================================================|"<<endl;

    cout<<  "                                    |                  DAFTAR MENU                   |"<<endl;
    cout<<  "                                     -------------------------------------------------"<<endl;
    cout << "                                    | 1.| Menambahkan film                           |"<<endl;
    cout << "                                    | 2.| Menghapus film                             |"<<endl;
    cout << "                                    | 3.| Menambahkan jadwal tayang                  |"<<endl;
    cout << "                                    | 4.| Menghapus jadwal tayang                    |"<<endl;
    cout << "                                    | 5.| Melihat daftar film yang sedang tayang     |"<<endl;
    cout << "                                    | 6.| Melihat jadwal tayang untuk film tertentu  |"<<endl;
    cout << "                                    | 7.| Memesan tiket untuk jadwal tayang tertentu |"<<endl;
    cout << "                                    | 8.| Melihat daftar tiket yang telah dipesan    |"<<endl;
    cout << "                                    | 9.| Melihat riwayat pemesanan oleh pelanggan   |"<<endl;
    cout << "                                    |10.| Keluar                                     |"<<endl;
    cout<<  "                                     --------------------------------------------------"<<endl;
    

 }

int main() {
     system("cls");
    Cinema cinema;
    Customer customer("Aji Sakti", 1);
    int choice;
    do {
        system("cls");
        showMenu();
        cout << "                                              Masukkan pilihan Anda: ";
        cin >>choice;
           cout<<  " \t========================================================================================================="<<endl;
    cout<<endl;
    cout<<endl;


        switch (choice) {
        case 1: {
            string title, genre;
            int duration;

            cout << "                                           Masukkan judul film: ";
            cin.ignore();
            getline(std::cin, title);
            cout << "                                    Masukkan durasi film (dalam menit): ";
            cin >> duration;
            cout << "                                           Masukkan genre film: ";
            cin.ignore();   
            getline(cin, genre);
            Movie movie(title, duration, genre);
            cinema.addMovie(movie);
            cout << "                                        Film berhasil ditambahkan.\n ";
            cout<<  " \t========================================================================================================="<<endl;
  
      system("pause");
            break;
             
        
        }
        case 2: {
            system("cls");
            string title, genre;
            int duration;
            cout << "Masukkan judul film yang akan dihapus: ";
            cin.ignore();
            getline(cin, title);
            cinema.removeMovie(title);
            cout << "Film berhasil dihapus.\n";
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            string title, time;
            int availableSeats;
            cout << "Masukkan judul film: ";
            cin.ignore();
            getline(std::cin, title);
            cout << "Masukkan waktu tayang (contoh: 10:00 AM): ";
            getline(std::cin, time);
            cout << "Masukkan jumlah kursi tersedia: ";
            cin >> availableSeats;
            Movie movie = cinema.getMovies().front(); // Asumsi film sudah ada dalam cinema
            for (const Movie& m : cinema.getMovies()) {
                if (m.getTitle() == title) {
                    movie = m;
                    system("pause");
                    break;
                }
            }
            Showtime showtime(movie, time, availableSeats);
            cinema.addShowtime(showtime);
            cout << "Jadwal tayang berhasil ditambahkan.\n";
            break;
        }
        case 4: {
            system("cls");
            string time;
            cout << "Masukkan waktu tayang yang akan dihapus: ";
            cin.ignore();
            getline(cin, time);
            cinema.removeShowtime(time);
            cout << "Jadwal tayang berhasil dihapus.\n";
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            vector<Movie> movies = cinema.getMovies();
            for (const Movie& movie : movies) {
                cout << movie.toString() << endl;
            }
            system("pause");
            break;
        }
        case 6: {
            system("cls");
            string title;
            cout << "Masukkan judul film: ";
            cin.ignore();
            getline(cin, title);
            vector<Showtime> showtimes = cinema.getShowtimes(title);
            for (const Showtime& showtime : showtimes) {
                cout << showtime.toString() << endl;
                system("pause");
            }
            break;
        }
        case 7: {
         
              int seatNumber;
            string title;
 cout<< "             ########::'########::'######:::::'###::::'##::: ##::::'########:'####:'##:::'##:'########:'########:" <<endl;
 cout << "            ##.... ##: ##.....::'##... ##:::'## ##::: ###:: ##::::... ##..::. ##:: ##::'##:: ##.....::... ##..::" <<endl;
 cout << "            ##:::: ##: ##::::::: ##:::..:::'##:. ##:: ####: ##::::::: ##::::: ##:: ##:'##::: ##:::::::::: ##::::" <<endl;
 cout << "            ########:: ######:::. ######::'##:::. ##: ## ## ##::::::: ##::::: ##:: #####:::: ######:::::: ##::::" <<endl;
 cout << "            ##.....::: ##...:::::..... ##: #########: ##. ####::::::: ##::::: ##:: ##. ##::: ##...::::::: ##::::" <<endl;
 cout << "            ##:::::::: ##:::::::'##::: ##: ##.... ##: ##:. ###::::::: ##::::: ##:: ##:. ##:: ##:::::::::: ##::::" <<endl;
 cout << "            ##:::::::: ########:. ######:: ##:::: ##: ##::. ##::::::: ##::::'####: ##::. ##: ########:::: ##::::" <<endl;
 cout<<  "          ========================================================================================================="<<endl;
            cout << "Masukkan judul film: ";
            cin.ignore();
            getline(cin, title);
            vector<Showtime> showtimes = cinema.getShowtimes(title);
            for (size_t i = 0; i < showtimes.size(); ++i) {
                cout <<"|"<< i << ".|   " << showtimes[i].toString() << endl;
            }
            
            float showtimeIndex;
            cout << "Pilih jadwal tayang (masukkan nomor): ";
            cin >> showtimeIndex;
            cout << "Masukkan nomor kursi: ";
            cin >> seatNumber;
            cinema.bookTicket(showtimeIndex , seatNumber, customer.getName());
            cout << "Tiket berhasil dipesan.\n";
        
            break;
        }
        case 8: {
            system("cls");
            
            vector<Ticket> tickets = cinema.getTickets();
            for (const Ticket& ticket : tickets) {
                cout << ticket.toString() << endl;
            }
            system("pause");
            break;
        }
        case 9:
           {
        system("cls"); 
        cinema.displayTiketHistory();
        
        system("pause");
        break;
    }
        

        case 10:
            cout << "Keluar dari program.\                                                                          n";
            system("pause");
        
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        
        }  
    } while (choice != 10);

    return 0;
}
