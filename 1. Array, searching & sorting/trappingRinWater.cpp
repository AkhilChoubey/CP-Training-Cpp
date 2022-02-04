
int getWater(vector<int> &heights)
{
    if (heights.size() == 0)
    {
        return 0;
    }
    int n = heights.size();
    int lMax[n], rMax[n];

    // precomputing lMax For Each element
    lMax[0] = heights[0];
    for (int i = 1; i < n; i++)
    {
        lMax[i] = max(lMax[i - 1], heights[i]);
    }

    // precomputing rMax for Each element
    rMax[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rMax[i] = max(rMax[i + 1], heights[i]);
    }

    // max water which can be trapped for i index = min(lMax[i], rMax[i]) - heights[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += min(lMax[i], rMax[i]) - heights[i];
    }

    return res;
}