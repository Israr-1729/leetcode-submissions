class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInInfo;

    unordered_map<string, pair<long long, int>> routeInfo;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkInInfo[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkInInfo[id];

        string route = startStation + "#" + stationName;

        routeInfo[route].first += (t - startTime);
        routeInfo[route].second++;

        checkInInfo.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "#" + endStation;

        auto &p = routeInfo[route];

        return (double)p.first / p.second;
    }
};