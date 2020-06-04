# https://leetcode.com/problems/two-city-scheduling/
'''
假设所有的人都选择城市A， 这时候sum=sum{a[i][0]},
然后要选择一半的人改成B， 这个时候, 选择某一个人对sum的影响是d=a[i][1]-a[i][0],
那么， 我们要让结果最小， 就需要让这个d最小， 那按照这个d对数组排序，然后选择最小的一半就好
'''

class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        change_cost = []
        sum = 0

        for i in range(0, len(costs)):
            change_cost.append(costs[i][1] - costs[i][0])
            sum += costs[i][0]

        change_cost.sort(reverse=False)

        #print(change_cost)

        for each in change_cost[:(len(costs)//2)]:
            sum += each
        return sum
