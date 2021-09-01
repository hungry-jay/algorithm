#include <string>
#include <vector>
#include <map>

using namespace std;

#define MAX 100005

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> cache;
    
    for(int i = 0; i < cities.size(); i++) {
        for(int j = 0; j < cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
    }
    
    for(int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        bool isFound = false;
        
        if(cache.find(city) != cache.end()) isFound = true;
        cache[city] = i;
        
        if(cache.size() > cacheSize) {
            int minIdx = MAX;
            string toDelete;
            for(auto iter = cache.begin(); iter != cache.end(); iter++) {
                if(iter->second < minIdx) {
                    minIdx = iter->second;
                    toDelete = iter->first;
                }
            }
            cache.erase(toDelete);
        }
        answer += isFound ? 1 : 5;
    }
    
    return answer;
}
