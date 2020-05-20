# https://leetcode.com/problems/online-stock-span/
'''
算法思路：
    使用单调递减栈，当一个新的price到来时，和栈顶作比较
    + 如果比栈顶小，入栈，continue
    + 如果比栈顶大，栈顶出栈，price的属性count+=出栈元素的count属性, 并重复此步直到比栈顶小或栈空
'''
class StockSpanner:
    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        if not self.stack or self.stack[-1][0] > price:
            self.stack.append([price, 1])
            return 1
        else:
            num = 1
            while self.stack:
                if self.stack[-1][0] <= price:
                    num += self.stack.pop()[1]
                else:
                    break
            self.stack.append([price, num])
            return num



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)