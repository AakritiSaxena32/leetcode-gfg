class Solution {
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        vector<int> roomUsedCount(n,0);

        int m = meetings.size();

        for(int room = 0; room<n; room++)
        {
            availableRooms.push(room);
        }

        for(vector<int> & meet: meetings)
        {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            while(!usedRooms.empty() && usedRooms.top().first <= start) 
            {
                int room = usedRooms.top().second;
                availableRooms.push(room);
                usedRooms.pop();
            }
            if(!availableRooms.empty())
            {
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, room});
                roomUsedCount[room]++;
            }
            else
            {
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime+duration, room});
                roomUsedCount[room]++;
            }
        }
        int resultRoom = -1;
        int maxUse = 0;
        for(int i=0; i<n; i++)
        {
            if(roomUsedCount[i] > maxUse)
            {
                maxUse = roomUsedCount[i];
                resultRoom = i;
            }
        }
        return resultRoom;
    }
};