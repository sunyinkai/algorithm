// http://codeforces.com/contest/1562/problem/A
package main

import "fmt"

func main()  {
	var T int
	fmt.Scan(&T)
	for i:=0;i<T;i++{
		var a,b int
		fmt.Scan(&a,&b)
		k:=b/2+1
		var y int
		if k>=a{
			y=k
		}else {
			y=a
		}
		fmt.Println(b%y)
	}
}