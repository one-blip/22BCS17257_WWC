// Design a train reservation system in C++ using linked lists to manage bookings for multiple trains, each with several compartments. Each compartment has a fixed number of seats, and passengers can book, cancel, or check the availability of seats for specific compartments. Additionally, the system should dynamically allocate memory for new bookings and keep track of canceled seats efficiently

#include <iostream>
#include <string>

struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;

    Seat(int seatNumber) : seatNumber(seatNumber), isBooked(false), next(nullptr) {}
};

struct Compartment {
    int compartmentNumber;
    Seat* seatHead;
    Compartment* next;

    Compartment(int compartmentNumber, int totalSeats) : compartmentNumber(compartmentNumber), seatHead(nullptr), next(nullptr) {
        for (int i = totalSeats; i > 0; --i) {
            Seat* newSeat = new Seat(i);
            newSeat->next = seatHead;
            seatHead = newSeat;
        }
    }
};

struct Train {
    int trainNumber;
    Compartment* compartmentHead;
    Train* next;

    Train(int trainNumber) : trainNumber(trainNumber), compartmentHead(nullptr), next(nullptr) {}
};

class TrainReservationSystem {
    Train* trainHead;

public:
    TrainReservationSystem() : trainHead(nullptr) {}

    void addTrain(int trainNumber) {
        Train* newTrain = new Train(trainNumber);
        newTrain->next = trainHead;
        trainHead = newTrain;
    }

    void addCompartment(int trainNumber, int compartmentNumber, int totalSeats) {
        Train* train = findTrain(trainNumber);
        if (!train) return;
        Compartment* newCompartment = new Compartment(compartmentNumber, totalSeats);
        newCompartment->next = train->compartmentHead;
        train->compartmentHead = newCompartment;
    }

    void bookSeat(int trainNumber, int compartmentNumber, int seatNumber) {
        Seat* seat = findSeat(trainNumber, compartmentNumber, seatNumber);
        if (seat && !seat->isBooked) seat->isBooked = true;
    }

    void cancelSeat(int trainNumber, int compartmentNumber, int seatNumber) {
        Seat* seat = findSeat(trainNumber, compartmentNumber, seatNumber);
        if (seat && seat->isBooked) seat->isBooked = false;
    }

    void checkAvailability(int trainNumber, int compartmentNumber) {
        Compartment* compartment = findCompartment(trainNumber, compartmentNumber);
        if (!compartment) return;
        Seat* seat = compartment->seatHead;
        while (seat) {
            std::cout << "Seat " << seat->seatNumber << (seat->isBooked ? " is booked" : " is available") << std::endl;
            seat = seat->next;
        }
    }

private:
    Train* findTrain(int trainNumber) {
        Train* temp = trainHead;
        while (temp && temp->trainNumber != trainNumber)
            temp = temp->next;
        return temp;
    }

    Compartment* findCompartment(int trainNumber, int compartmentNumber) {
        Train* train = findTrain(trainNumber);
        if (!train) return nullptr;
        Compartment* temp = train->compartmentHead;
        while (temp && temp->compartmentNumber != compartmentNumber)
            temp = temp->next;
        return temp;
    }

    Seat* findSeat(int trainNumber, int compartmentNumber, int seatNumber) {
        Compartment* compartment = findCompartment(trainNumber, compartmentNumber);
        if (!compartment) return nullptr;
        Seat* temp = compartment->seatHead;
        while (temp && temp->seatNumber != seatNumber)
            temp = temp->next;
        return temp;
    }
};

int main() {
    TrainReservationSystem system;
    system.addTrain(101);
    system.addCompartment(101, 1, 5);
    system.addCompartment(101, 2, 3);

    system.bookSeat(101, 1, 3);
    system.bookSeat(101, 1, 1);

    system.checkAvailability(101, 1);
    system.cancelSeat(101, 1, 3);
    system.checkAvailability(101, 1);

    return 0;
}
