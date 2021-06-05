#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next = 0;
    // 무게 시간
    vector<pair<int, int>> bridge;
    while (!bridge.empty() || !truck_weights.empty())
    {
        answer++;
        int bridgeWeight = 0;
        for (vector<pair<int, int>>::iterator i = bridge.begin(); i < bridge.size(); i++)
        {
            bridge[i].second++;
            if (bridge[i].second > bridge_length)
            {
                bridge.erase(bridge.begin() + i);
                continue;
            }
            bridgeWeight += bridge[i].first;
        }
        if (weight > bridgeWeight)
        {
            if (weight >= bridgeWeight + truck_weights[next])
            {
                bridge.push_back(make_pair(truck_weights[next], 1));
                truck_weights.erase(truck_weights.begin() + next);
                next++;
            }
        }
    }
    return answer;
}