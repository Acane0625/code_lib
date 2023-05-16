class FrequencyTracker {
public:
    unordered_map<int, int> mp;
    unordered_map<int, int> fr;
    FrequencyTracker() {
        mp.clear();
        fr.clear();    
    }

    void add(int x) {
        fr[mp[x]]--;
        mp[x]++;
        fr[mp[x]]++;
    }
    
    void deleteOne(int x) {
        if(mp[x] > 0) {
            fr[mp[x]]--;
            mp[x]--;
            fr[mp[x]]++;
        }
    }
    
    bool hasFrequency(int y) {
        return fr[y] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */