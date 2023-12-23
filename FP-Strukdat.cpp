#include <iostream>
#include <vector>
using namespace std;

// Abstract class representing a city
class AbstractCity {
public:
  string name;
  string location;
  vector<AbstractCity*> neighbors;

public:
  AbstractCity(string name, string location) : name(name), location(location) {}

  virtual string getName() const = 0;
  virtual string getLocation() const = 0;
  virtual vector<AbstractCity*> getNeighbors() const = 0;
};

// Class Attraction
class Attraction {
private:
  string name;
  string description;

public:
  Attraction(string name, string description) {
    this->name = name;
    this->description = description;
  }

  string getName() {
    return name;
  }

  string getDescription() {
    return description;
  }
};

// Concrete class representing a city
class City : public AbstractCity {
private:
  vector<Attraction*> attractions;

public:
  City(string name, string location, vector<Attraction*> attractions) : AbstractCity(name, location), attractions(attractions) {}

  string getName() const override {
    return name;
  }

  string getLocation() const override {
    return location;
  }

  vector<AbstractCity*> getNeighbors() const override {
    return neighbors;
  }

  vector<Attraction*> getAttractions() const {
    return attractions;
  }
};

// Concrete class representing a route
class Route {
public:
  City* start_city;
  City* end_city;
  int distance;
  int travel_time;
  int cost;

  Route(City* start_city, City* end_city, int distance, int travel_time, int cost)
      : start_city(start_city), end_city(end_city), distance(distance), travel_time(travel_time), cost(cost) {}

  void printRouteInfo() const {
    cout << "Route Information:" << endl;
    cout << "Start City: " << start_city->getName() << endl;
    cout << "End City: " << end_city->getName() << endl;
    cout << "Distance: " << distance << " km" << endl;
    cout << "Travel Time: " << travel_time << " hours" << endl;
    cout << "Cost: Rp" << cost << endl;
  }
};

// Main Function
int main() {
  // Create cities
  City jakarta("Jakarta", "Java", {new Attraction("Monas", "National Monument"), new Attraction("Ancol Dreamland", "Theme park")});
  City bandung("Bandung", "Java", {new Attraction("Saung Angklung Udjo", "Traditional music performance"), new Attraction("Tangkuban Perahu Volcano", "Natural landmark")});
  City yogyakarta("Yogyakarta", "Java", {new Attraction("Prambanan Temple", "Hindu temple complex"), new Attraction("Malioboro Street", "Bustling shopping street")});
  City surabaya("Surabaya", "East Java", {new Attraction("Surabaya Zoo", "Zoological garden"), new Attraction("Tanjung Perak Port", "Largest port in Indonesia")});
  City denpasar("Denpasar", "Bali", {new Attraction("Pura Tanah Lot", "Temple perched on a rock"), new Attraction("Kuta Beach", "Popular surfing destination")});

  Route jakartaBandungRoute(&jakarta, &bandung, 157, 3, 72500);
  Route jakartaYogyakartaRoute(&jakarta, &yogyakarta, 568, 8, 439500);
  Route jakartaSurabayaRoute(&jakarta, &surabaya, 788, 11, 678000);
  Route jakartaDenpasarRoute(&jakarta, &denpasar, 1187, 20, 811500);

  Route bandungJakartaRoute(&bandung, &jakarta, 157, 3, 72500);
  Route bandungYogyakartaRoute(&bandung, &yogyakarta, 484, 7, 455500);
  Route bandungSurabayaRoute(&bandung, &surabaya, 788, 11, 744500);
  Route bandungDenpasarRoute(&bandung, &denpasar, 1103, 18, 830000);

  Route yogyakartaBandungRoute(&yogyakarta, &bandung, 484, 7, 455500);
  Route yogyakartaJakartaRoute(&yogyakarta, &jakarta, 568 , 8, 439500);
  Route yogyakartaSurabayaRoute(&yogyakarta, &surabaya, 788, 11, 678000);
  Route yogyakartaDenpasarRoute(&yogyakarta, &denpasar, 1187, 20, 811500);

  Route surabayaBandungRoute(&surabaya, &bandung, 157, 3, 744500);
  Route surabayaYogyakartaRoute(&surabaya, &yogyakarta, 157, 8, 453500);
  Route surabayaJakartaRoute(&surabaya, &jakarta, 788, 11, 678000);
  Route surabayaDenpasarRoute(&jakarta, &denpasar, 1187, 20, 811500);

  Route denpasarBandungRoute(&denpasar, &bandung, 1103, 18, 830000);
  Route denpasarYogyakartaRoute(&denpasar, &yogyakarta, 157, 8, 453500);
  Route denpasarSurabayaRoute(&denpasar, &surabaya, 788, 11, 678000);
  Route denpasarJakartaRoute(&denpasar, &jakarta, 1187, 20, 811500);

  // Connect cities with routes
  jakarta.neighbors.push_back(&bandung);
  jakarta.neighbors.push_back(&yogyakarta);
  jakarta.neighbors.push_back(&surabaya);
  jakarta.neighbors.push_back(&denpasar);
  bandung.neighbors.push_back(&jakarta);
  bandung.neighbors.push_back(&yogyakarta);
  yogyakarta.neighbors.push_back(&jakarta);
  yogyakarta.neighbors.push_back(&bandung);
  yogyakarta.neighbors.push_back(&surabaya);
  surabaya.neighbors.push_back(&jakarta);
  surabaya.neighbors.push_back(&yogyakarta);
  denpasar.neighbors.push_back(&surabaya);

  // Start the game
cout << "Welcome to the Indonesia Travel Game!" << endl;

int startCityIndex, endCityIndex;

do {
  cout << "Select your starting city:" << endl;
  cout << "1. Jakarta" << endl;
  cout << "2. Bandung" << endl;
  cout << "3. Yogyakarta" << endl;
  cout << "4. Surabaya" << endl;
  cout << "5. Denpasar" << endl;
  cout << "Enter your choice (1-5): ";
  cin >> startCityIndex;
} while (startCityIndex < 1 || startCityIndex > 5);

do {
  cout << "Select your destination city:" << endl;
  cout << "1. Jakarta" << endl;
  cout << "2. Bandung" << endl;
  cout << "3. Yogyakarta" << endl;
  cout << "4. Surabaya" << endl;
  cout << "5. Denpasar" << endl;
  cout << "Enter your choice (1-5): ";
  cin >> endCityIndex;
} while (endCityIndex < 1 || endCityIndex > 5);

City* startCity, *endCity;

switch (startCityIndex) {
  case 1:
    startCity = &jakarta;
    break;
  case 2:
    startCity = &bandung;
    break;
  case 3:
    startCity = &yogyakarta;
    break;
  case 4:
    startCity = &surabaya;
    break;
  case 5:
    startCity = &denpasar;
    break;
  default:
    break;
}

switch (endCityIndex) {
  case 1:
    endCity = &jakarta;
    break;
  case 2:
    endCity = &bandung;
    break;
  case 3:
    endCity = &yogyakarta;
    break;
  case 4:
    endCity = &surabaya;
    break;
  case 5:
    endCity = &denpasar;
    break;
  default:
    break;
}

// Find the route between the start and end cities
Route* route = nullptr;

for (AbstractCity* neighbor : startCity->getNeighbors()) {
  if (dynamic_cast<City*>(neighbor) == endCity) {
    route = new Route(startCity, endCity, 100, 1, 100000);
    break;
  } else {
    for (AbstractCity* neighbor2 : neighbor->getNeighbors()) {
      if (dynamic_cast<City*>(neighbor2) == endCity) {
        route = new Route(startCity, endCity, 300, 3, 300000);
        break;
      }
    }
  }
}

// Display the route information
if (route) {
  route->printRouteInfo();
} else {
  cout << "No route found between " << startCity->getName() << " and " << endCity->getName() << endl;
}

return 0;
}