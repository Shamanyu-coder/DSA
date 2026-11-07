
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;

        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> busy;

        int n = servers.size();
        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        for(int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, id] = busy.top();
                busy.pop();
                free.push({w, id});
            }

            if(free.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t, w, id] = busy.top();
                    busy.pop();
                    free.push({w, id});
                }
            }

            auto [w, id] = free.top();
            free.pop();

            ans.push_back(id);

            busy.push({time + tasks[i], w, id});
        }

        return ans;
    }
};
