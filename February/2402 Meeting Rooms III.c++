// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/meeting-rooms-iii/

class Solution
{
public:
  int mostBooked(int n, vector<vector<int>> &meetings)
  {
    vector<int> meetingsPerRoom(n, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> busyRooms;
    priority_queue<int, vector<int>, greater<int>> availableRooms;
    for (int i = 0; i < n; i++)
    {
      availableRooms.push(i);
    }
    sort(meetings.begin(), meetings.end());

    for (auto meeting : meetings)
    {
      int startTime = meeting[0];
      int endTime = meeting[1];

      while (!busyRooms.empty() && busyRooms.top().first <= startTime)
      {
        availableRooms.push(busyRooms.top().second);
        busyRooms.pop();
      }

      if (availableRooms.size() > 0)
      {
        int top = availableRooms.top();
        meetingsPerRoom[top]++;
        availableRooms.pop();
        busyRooms.push({endTime, top});
      }
      else
      {
        auto top = busyRooms.top();
        long long availableTime = top.first;
        int availableRoom = top.second;

        meetingsPerRoom[availableRoom]++;
        busyRooms.pop();
        busyRooms.push({availableTime + endTime - startTime, availableRoom});
      }
    }

    int maxMeetingInRoom = 0;
    int maxMeetingRoom = 0;
    for (int i = 0; i < n; i++)
    {
      if (meetingsPerRoom[i] > maxMeetingRoom)
      {
        maxMeetingRoom = meetingsPerRoom[i];
        maxMeetingInRoom = i;
      }
    }

    return maxMeetingInRoom;
  }
};