#include <list>
#include <string>
using namespace std;

class BrowserHistory {
    list<string> history;
    list<string>::iterator curr;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = history.begin();
    }

    void visit(string url) {
        auto it = curr;
        ++it;
        history.erase(it, history.end());

        history.push_back(url);
        curr = prev(history.end());
    }

    string back(int steps) {
        while (curr != history.begin() && steps > 0) {
            --curr;
            --steps;
        }
        return *curr;
    }

    string forward(int steps) {
        while (steps > 0) {
            auto next = curr;
            ++next;

            if (next == history.end())
                break;

            curr = next;
            --steps;
        }
        return *curr;
    }
};