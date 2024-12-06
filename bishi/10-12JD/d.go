package main

import "fmt"

func main() {
	logTrickCnt := func(a []int, op func(x, y int) int) map[int]int {
		cnt := map[int]int{}
		// 视情况，r 可以省略
		// 或者把 l 和 r 换掉，改成维护 r-l
		type result struct{ v, l, r int } // [l,r)
		curRes := []result{}
		for i, v := range a {
			// 计算的相当于是在 i 结束的 suf op
			for j, p := range curRes {
				curRes[j].v = op(p.v, v)
			}
			curRes = append(curRes, result{v, i, i + 1})

			// 去重（合并 v 相同的 result）
			j := 1
			for k := 1; k < len(curRes); k++ {
				if curRes[k].v != curRes[k-1].v {
					curRes[j] = curRes[k]
					j++
				} else {
					curRes[j-1].r = curRes[k].r // 如果省略 r 的话，这行可以去掉
				}
			}
			curRes = curRes[:j]

			// 此时我们将区间 [0,i] 划分成了 len(set) 个左闭右开区间
			// 对于任意 p∈set，任意 j∈[p.l,p.r)，op(区间[j,i]) 的计算结果均为 p.v
			for _, p := range curRes {
				// do p...     [l,r)
				cnt[p.v] += p.r - p.l
			}
		}
		return cnt
	}
	mp := logTrickCnt([]int{1, 2, 3, 4, 5}, func(x, y int) int {
		return x | y
	})
	fmt.Println(mp)
}
