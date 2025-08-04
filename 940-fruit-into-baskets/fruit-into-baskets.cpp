class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int lastFruit = -1, secondLastFruit = -1;
    int lastFruitCount = 0;
    int maxCount = 0, curCount = 0;

    for (int fruit : arr) {
        if (fruit == lastFruit || fruit == secondLastFruit) {
            curCount++;
        } else {
            curCount = lastFruitCount + 1;  // just last streak + new fruit
        }

        if (fruit == lastFruit) lastFruitCount++;
        else {
            lastFruitCount = 1;
            secondLastFruit = lastFruit;
            lastFruit = fruit;
        }

        maxCount = max(maxCount, curCount);
    }
    return maxCount;
    }
};