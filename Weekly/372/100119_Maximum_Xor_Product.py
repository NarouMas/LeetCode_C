class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        ba, bb = [], []
        ta, tb = a, b
        c = []
        while ta > 0:
            if ta % 2 == 0:
                ba.append(0)
            else:
                ba.append(1)
            ta = ta // 2
        while tb > 0:
            if tb % 2 == 0:
                bb.append(0)
            else:
                bb.append(1)
            tb = tb // 2
        while len(ba) < n:
            ba.append(0)
        while len(bb) < n:
            bb.append(0)
        while len(ba) > n:
            ba.pop(len(ba) - 1)
        while len(bb) > n:
            bb.pop(len(bb) - 1)

        for i in range(n):
            if ba[i] == 1 and bb[i] == 1:
                c.append(0)
            elif ba[i] == 0 and bb[i] == 0:
                c.append(1)
            else:
                c.append(2)

        self.res = 0

        def foo(cur, arr, depth, n):
            # print("cur:", cur)
            # print("depth:", depth)
            # print("n:", n)
            # input()
            if len(cur) == n:
                num = 0
                base = 1
                for i in range(n):
                    if cur[i] == 1:
                        num += base
                    base *= 2
                # print("cur:", cur)
                # print("n:", num)
                # print("sum:", (a ^ num) * (b ^ num))
                self.res = max((a ^ num) * (b ^ num), self.res)
                return
            if arr[depth] == 0:
                cur.append(0)
                foo(cur, arr, depth + 1, n)
                cur.pop(len(cur) - 1)
            elif arr[depth] == 1:
                cur.append(1)
                foo(cur, arr, depth + 1, n)
                cur.pop(len(cur) - 1)
            else:
                cur.append(0)
                foo(cur, arr, depth + 1, n)
                cur.pop(len(cur) - 1)
                cur.append(1)
                foo(cur, arr, depth + 1, n)
                cur.pop(len(cur) - 1)
        foo([], c, 0, n)

        return self.res % (pow(10, 9) + 7)


if __name__ == '__main__':
    sol = Solution()
    print(sol.maximumXorProduct(12, 5, 4))
    print(sol.maximumXorProduct(6, 7, 5))
    print(sol.maximumXorProduct(1, 6, 3))
