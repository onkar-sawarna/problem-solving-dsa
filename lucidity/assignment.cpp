#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits> // Required for std::numeric_limits

// For PI constant
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Forward declarations
class GeoLocation;
class Order;
class DeliveryExecutive;

// 1. GeoLocation Class
// Encapsulates latitude and longitude coordinates.
class GeoLocation {
public:
    double latitude;
    double longitude;

    GeoLocation(double lat, double lon) : latitude(lat), longitude(lon) {}

    // Getters for encapsulation (though public members are fine for simple structs/data)
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
};

// 2. Haversine Utility Class
// Provides static methods for calculating the distance between two GeoLocation objects.
class Haversine {
public:
    // Earth's radius in kilometers
    static constexpr double EARTH_RADIUS_KM = 6371.0;

    static double toRadians(double degrees) {
        return degrees * (M_PI / 180.0);
    }

    static double calculateDistance(const GeoLocation& loc1, const GeoLocation& loc2) {
        double lat1_rad = toRadians(loc1.latitude);
        double lon1_rad = toRadians(loc1.longitude); // Corrected typo here from toToRadians to toRadians
        double lat2_rad = toRadians(loc2.latitude);
        double lon2_rad = toRadians(loc2.longitude);

        double dlat = lat2_rad - lat1_rad;
        double dlon = lon2_rad - lon1_rad;

        double a = std::sin(dlat / 2.0) * std::sin(dlat / 2.0) +
                   std::cos(lat1_rad) * std::cos(lat2_rad) *
                   std::sin(dlon / 2.0) * std::sin(dlon / 2.0);
        double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

        return EARTH_RADIUS_KM * c; // Distance in kilometers
    }
};

// 3. TimeCalculator Utility Class
// Converts distance to travel time based on the average speed.
class TimeCalculator {
public:
    static constexpr double AVERAGE_SPEED_KM_PER_HOUR = 20.0; //

    static double calculateTravelTimeMinutes(double distanceKm) {
        // time = distance / speed
        // Convert hours to minutes
        return (distanceKm / AVERAGE_SPEED_KM_PER_HOUR) * 60.0;
    }
};

// 4. Order Class
// Represents an individual order with consumer and restaurant locations and preparation time.
class Order {
public:
    GeoLocation consumerLocation;
    GeoLocation restaurantLocation;
    double preparationTimeMinutes; // pt1 or pt2
    std::string orderName; // For identification, e.g., "Order 1", "Order 2"

    Order(const std::string& name, const GeoLocation& resLoc, const GeoLocation& conLoc, double prepTime)
        : orderName(name), restaurantLocation(resLoc), consumerLocation(conLoc), preparationTimeMinutes(prepTime) {}
};

// 5. DeliveryExecutive Class
// Represents Aman, the delivery executive.
class DeliveryExecutive {
public:
    GeoLocation currentLocation;
    std::string name;

    DeliveryExecutive(const std::string& execName, const GeoLocation& startLoc)
        : name(execName), currentLocation(startLoc) {}
};

// 6. DeliveryScenario Class
// Encapsulates a single delivery sequence and its total time calculation logic.
class DeliveryScenario {
public:
    // This method calculates the total time for a given sequence of locations.
    // The sequence should represent the path Aman takes.
    // It returns the total time in minutes.
    static double calculateTotalTime(
        const GeoLocation& amanStartLocation,
        const Order& order1, // This is C1's order
        const Order& order2, // This is C2's order
        const std::vector<GeoLocation>& sequenceLocations,
        const std::vector<std::string>& sequenceTypes // "pickup_R1", "deliver_C1", etc.
    ) {
        if (sequenceLocations.size() != sequenceTypes.size() || sequenceLocations.empty()) {
            return std::numeric_limits<double>::max(); // Invalid sequence
        }

        double currentTime = 0.0; // Time elapsed since orders were assigned (t=0)
        GeoLocation currentLocation = amanStartLocation;

        // Keep track of when food is ready at each restaurant
        double r1ReadyTime = order1.preparationTimeMinutes;
        double r2ReadyTime = order2.preparationTimeMinutes;

        // Keep track of whether orders have been picked up
        bool order1PickedUp = false;
        bool order2PickedUp = false;

        // Keep track of whether orders have been delivered
        bool order1Delivered = false;
        bool order2Delivered = false;

        for (size_t i = 0; i < sequenceLocations.size(); ++i) {
            const GeoLocation& nextLocation = sequenceLocations[i];
            const std::string& actionType = sequenceTypes[i];

            double travelTime = Haversine::calculateDistance(currentLocation, nextLocation);
            double travelTimeMinutes = TimeCalculator::calculateTravelTimeMinutes(travelTime);

            currentTime += travelTimeMinutes;

            // Handle actions at each location
            if (actionType == "pickup_R1") {
                // Aman arrives at R1. Wait if food is not ready.
                if (currentTime < r1ReadyTime) {
                    currentTime = r1ReadyTime; // Aman waits until food is ready
                }
                order1PickedUp = true;
            } else if (actionType == "pickup_R2") {
                // Aman arrives at R2. Wait if food is not ready.
                if (currentTime < r2ReadyTime) {
                    currentTime = r2ReadyTime; // Aman waits until food is ready
                }
                order2PickedUp = true;
            } else if (actionType == "deliver_C1") {
                if (!order1PickedUp) {
                    // This scenario should not happen in valid sequences, but as a safeguard
                    return std::numeric_limits<double>::max(); // Cannot deliver without picking up
                }
                order1Delivered = true;
            } else if (actionType == "deliver_C2") {
                if (!order2PickedUp) {
                    // Safeguard
                    return std::numeric_limits<double>::max(); // Cannot deliver without picking up
                }
                order2Delivered = true;
            }

            currentLocation = nextLocation;
        }

        // Ensure both orders are picked up and delivered at the end of the sequence
        if (!order1PickedUp || !order2PickedUp || !order1Delivered || !order2Delivered) {
             return std::numeric_limits<double>::max(); // Incomplete delivery
        }

        return currentTime;
    }
};

// 7. DeliveryPlanner Class
// Orchestrates the overall solution to find the best route.
class DeliveryPlanner {
public:
    DeliveryExecutive aman;
    Order order1;
    Order order2;

    DeliveryPlanner(const DeliveryExecutive& exec, const Order& o1, const Order& o2)
        : aman(exec), order1(o1), order2(o2) {}

    // Method to find the best route among all possible sequences
    std::pair<double, std::string> findBestRoute() {
        double minTotalTime = std::numeric_limits<double>::max();
        std::string bestSequenceDescription = "No optimal sequence found";

        // Define the locations based on the orders and Aman's start
        GeoLocation amanStart = aman.currentLocation;
        GeoLocation r1Loc = order1.restaurantLocation;
        GeoLocation c1Loc = order1.consumerLocation;
        GeoLocation r2Loc = order2.restaurantLocation;
        GeoLocation c2Loc = order2.consumerLocation;

        // All possible valid delivery sequences
        // Sequence 1: A -> R1 -> C1 -> R2 -> C2
        {
            std::vector<GeoLocation> locations = {r1Loc, c1Loc, r2Loc, c2Loc};
            std::vector<std::string> types = {"pickup_R1", "deliver_C1", "pickup_R2", "deliver_C2"};
            double time = DeliveryScenario::calculateTotalTime(amanStart, order1, order2, locations, types);
            if (time < minTotalTime) {
                minTotalTime = time;
                bestSequenceDescription = "A -> R1 -> C1 -> R2 -> C2";
            }
        }

        // Sequence 2: A -> R1 -> R2 -> C1 -> C2
        {
            std::vector<GeoLocation> locations = {r1Loc, r2Loc, c1Loc, c2Loc};
            std::vector<std::string> types = {"pickup_R1", "pickup_R2", "deliver_C1", "deliver_C2"};
            double time = DeliveryScenario::calculateTotalTime(amanStart, order1, order2, locations, types);
            if (time < minTotalTime) {
                minTotalTime = time;
                bestSequenceDescription = "A -> R1 -> R2 -> C1 -> C2";
            }
        }

        // Sequence 3: A -> R1 -> R2 -> C2 -> C1
        {
            std::vector<GeoLocation> locations = {r1Loc, r2Loc, c2Loc, c1Loc};
            std::vector<std::string> types = {"pickup_R1", "pickup_R2", "deliver_C2", "deliver_C1"};
            double time = DeliveryScenario::calculateTotalTime(amanStart, order1, order2, locations, types);
            if (time < minTotalTime) {
                minTotalTime = time;
                bestSequenceDescription = "A -> R1 -> R2 -> C2 -> C1";
            }
        }

        // Sequence 4: A -> R2 -> C2 -> R1 -> C1
        {
            std::vector<GeoLocation> locations = {r2Loc, c2Loc, r1Loc, c1Loc};
            std::vector<std::string> types = {"pickup_R2", "deliver_C2", "pickup_R1", "deliver_C1"};
            double time = DeliveryScenario::calculateTotalTime(amanStart, order1, order2, locations, types);
            if (time < minTotalTime) {
                minTotalTime = time;
                bestSequenceDescription = "A -> R2 -> C2 -> R1 -> C1";
            }
        }

        // Sequence 5: A -> R2 -> R1 -> C1 -> C2
        {
            std::vector<GeoLocation> locations = {r2Loc, r1Loc, c1Loc, c2Loc};
            std::vector<std::string> types = {"pickup_R2", "pickup_R1", "deliver_C1", "deliver_C2"};
            double time = DeliveryScenario::calculateTotalTime(amanStart, order1, order2, locations, types);
            if (time < minTotalTime) {
                minTotalTime = time;
                bestSequenceDescription = "A -> R2 -> R1 -> C1 -> C2";
            }
        }

        // Sequence 6: A -> R2 -> R1 -> C2 -> C1
        {
            std::vector<GeoLocation> locations = {r2Loc, r1Loc, c2Loc, c1Loc};
            std::vector<std::string> types = {"pickup_R2", "pickup_R1", "deliver_C2", "deliver_C1"};
            double time = DeliveryScenario::calculateTotalTime(amanStart, order1, order2, locations, types);
            if (time < minTotalTime) {
                minTotalTime = time;
                bestSequenceDescription = "A -> R2 -> R1 -> C2 -> C1";
            }
        }

        return {minTotalTime, bestSequenceDescription};
    }
};

// Main function for testing
int main() {
    // Placeholder Geo-locations (approximate values for Bengaluru areas)
    GeoLocation koramangala(12.9352, 77.6245); // Aman's starting point
    GeoLocation r1Loc(12.9692, 77.5937);       // Restaurant R1
    GeoLocation r2Loc(12.9161, 77.6101);       // Restaurant R2
    GeoLocation c1Loc(12.9716, 77.5946);       // Consumer C1
    GeoLocation c2Loc(12.9088, 77.6322);       // Consumer C2

    // Example preparation times in minutes
    double pt1 = 15.0; // Average time it takes to prepare a meal is pt1
    double pt2 = 20.0; // Average time it takes to prepare a meal is pt2

    // Create orders
    Order order1("Order 1 (C1)", r1Loc, c1Loc, pt1);
    Order order2("Order 2 (C2)", r2Loc, c2Loc, pt2);

    // Create delivery executive
    DeliveryExecutive aman("Aman", koramangala); // A delivery executive called Aman standing idle in Koramangala

    // Initialize the planner
    DeliveryPlanner planner(aman, order1, order2);

    // Find the best route
    std::pair<double, std::string> result = planner.findBestRoute();

    if (result.first == std::numeric_limits<double>::max()) {
        std::cout << "Could not find a valid delivery route." << std::endl;
    } else {
        std::cout << "Best Route for Aman: " << result.second << std::endl;
        std::cout << "Shortest possible time: " << result.first << " minutes" << std::endl;
    }

    return 0;
}