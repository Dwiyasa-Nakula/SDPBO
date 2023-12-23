#include <iostream>
#include <vector>
using namespace std;

// Class AbstractCity
class AbstractCity {
public:
  string name;
  string location;
  vector<AbstractCity*> neighbors;

public:
  AbstractCity(string name, string location) : name(name), location(location) {
    neighbors = vector<AbstractCity*>();
}


  virtual string getName() = 0;
  virtual string getLocation() = 0;
  virtual vector<AbstractCity*> getNeighbors() = 0;
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

// Class City
class City : public AbstractCity {
public:
  vector<Attraction*> attractions;

public:
  City(string name, string location, vector<Attraction*> attractions) : AbstractCity(name, location), attractions(attractions) {}

  string getName() override {
    return name;
  }

  string getLocation() override {
    return location;
  }

  vector<AbstractCity*> getNeighbors() override {
    return neighbors;
  }

  vector<Attraction*> getAttractions() {
    return attractions;
  }
};

// Class Route
class Route {
public:
  City* start_city;
  City* end_city;
  int distance;
  int travel_time;
  int cost;

public:
  Route(City* start_city, City* end_city, int distance, int travel_time, int cost)
      : start_city(start_city), end_city(end_city), distance(distance), travel_time(travel_time), cost(cost) {}

  City* getStartCity() {
    return start_city;
  }

  City* getEndCity() {
    return end_city;
  }

  int getDistance() {
    return distance;
  }

  int getTravelTime() {
    return travel_time;
  }

  int getCost() {
    return cost;
  }

  void printRouteInfo() {
    cout << "Route Information:" << endl;
    cout << "Start City: " << start_city->getName() << endl;
    cout << "End City: " << end_city->getName() << endl;
    cout << "Distance: " << distance << " km" << endl;
    cout << "Travel Time: " << travel_time << " hours" << endl;
    cout << "Cost: Rp" << cost << endl;
  }
};

// Function to find all possible routes
void findRoutes(AbstractCity* startCity, City* endCity, vector<Route>& routes, vector<AbstractCity*>& path) {
 path.push_back(startCity);

 if (startCity == endCity) {
    // Calculate distance, time, and cost based on backtracking path
    int distance = 0;
    int travel_time = 0;
    int cost = 0;
    // ... add logic to calculate route details based on backtracking
    routes.emplace_back(dynamic_cast<City*>(startCity), endCity, distance, travel_time, cost);
 } else {
    for (AbstractCity* neighbor : startCity->getNeighbors()) {
      findRoutes(neighbor, endCity, routes, path);
    }
 }

 path.pop_back();
}


// Main Function
int main() {
  // Create cities
  City jakarta("Jakarta", "Java", {new Attraction("Monas", "National Monument"), new Attraction("Ancol Dreamland", "Theme park")});
  City bandung("Bandung", "Java", {new Attraction("Saung Angklung Udjo", "Traditional music performance"), new Attraction("Tangkuban Perahu Volcano", "Natural landmark")});
  City yogyakarta("Yogyakarta", "Java", {new Attraction("Prambanan Temple", "Hindu temple complex"), new Attraction("Malioboro Street", "Bustling shopping street")});
  City surabaya("Surabaya", "East Java", {new Attraction("Surabaya Zoo", "Zoological garden"), new Attraction("Tanjung Perak Port", "Largest port in Indonesia")});
  City denpasar("Denpasar", "Bali", {new Attraction("Pura Tanah Lot", "Temple perched on a rock"), new Attraction("Kuta Beach", "Popular surfing destination")});

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

  cout << "Welcome!" << endl;
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

    // Find all possible routes
    vector<Route> routes;
    vector<AbstractCity*> path;
    findRoutes(startCity, endCity, routes, path);

    // Display the routes
    if (routes.empty()) {
    cout << "No route found between " << startCity->getName() << " and " << endCity->getName() << endl;
    } else {
    cout << "Found " << routes.size() << " possible routes:" << endl;
    for (std::vector<Route>::size_type i = 0; i < routes.size(); ++i) {
        cout << "Route " << i + 1 << ":" << endl;
        routes[i].printRouteInfo();  // Use dot operator instead of arrow operator
        cout << endl;
    }
    }

  return 0;
}