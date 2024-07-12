package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

type Transaction struct {
	writes_   []Write
	start_ts_ int
}

type Write struct {
	row   string
	col   string
	value string
}

func NewTransaction() *Transaction {
	return &Transaction{
		writes_:   make([]Write, 0),
		start_ts_: GetTimestamp(),
	}
}

func (t *Transaction) Set(w Write) {
	t.writes_ = append(t.writes_, w)
}

func (t *Transaction) Get(row string, col string) (string, bool) {
	for {
		T := StartRowTransaction(row)
		if T.Read(row, col+"lock", []int{0, t.start_ts_}) {
			BackoffAndMaybeCleanupLock(row, col)
			continue
		}

		latestWrite := T.Read(row, col+"write", []int{0, t.start_ts_})
		if !latestWrite.found() {
			return "", false
		}

		data_ts := latestWrite.start_timestamp()
		value := T.Read(row, col+"data", []int{data_ts, data_ts})
		return value, true
	}
}

func (t *Transaction) Prewrite(w Write, primary Write) bool {
	c := w.col
	T := StartRowTransaction(w.row)
	if T.Read(w.row, c+"write", []int{t.start_ts_, infinity}) {
		return false
	}

	if T.Read(w.row, c+"lock", []int{0, infinity}) {
		return false
	}

	T.Write(w.row, c+"data", t.start_ts_, w.value)
	T.Write(w.row, c+"lock", t.start_ts_, []string{primary.row, primary.col})
	return T.Commit()
}

func (t *Transaction) Commit() bool {
	primary := t.writes_[0]
	secondaries := t.writes_[1:]

	if !t.Prewrite(primary, primary) {
		return false
	}

	for _, w := range secondaries {
		if !t.Prewrite(w, primary) {
			return false
		}
	}

	commit_ts := GetTimestamp()
	T := StartRowTransaction(primary.row)
	if !T.Read(primary.row, primary.col+"lock", []int{t.start_ts_, t.start_ts_}) {
		return false
	}

	T.Write(primary.row, primary.col+"write", commit_ts, t.start_ts_)
	T.Erase(primary.row, primary.col+"lock", commit_ts)

	if !T.Commit() {
		return false
	}

	for _, w := range secondaries {
		Write(w.row, w.col+"write", commit_ts, t.start_ts_)
		Erase(w.row, w.col+"lock", commit_ts)
	}

	return true
}

func GetTimestamp() int {
	return int(time.Now().Unix())
}

func StartRowTransaction(row string) *bigtableTxn {
	fmt.Printf("开始事务处理行：%s\n", row)
	// 模拟行级事务设置
	return &bigtableTxn{}
}

func (t *bigtableTxn) Read(row string, col string, tsRange []int) bool {
	// 模拟读操作，在本示例中始终返回true
	fmt.Printf("从行：%s，列：%s，时间范围：%v 读取\n", row, col, tsRange)
	return true
}

func (t *bigtableTxn) Write(row string, col string, ts int, value interface{}) {
	// 模拟写操作
	fmt.Printf("写入行：%s，列：%s，时间戳：%d，值：%v\n", row, col, ts, value)
}

func (t *bigtableTxn) Erase(row string, col string, ts int) {
	// 模拟擦除操作
	fmt.Printf("从行：%s，列：%s，时间戳：%d 擦除\n", row, col, ts)
}

func (t *bigtableTxn) Commit() bool {
	// 模拟提交操作，在本示例中始终返回true
	fmt.Println("事务提交")
	return true
}

func BackoffAndMaybeCleanupLock(row string, col string) {
	// 模拟等待和锁清理
	fmt.Printf("等待并可能清理行：%s，列：%s 的锁\n", row, col)
}

func main() {
	// 事务类的示例用法
	txn := NewTransaction()

	// 模拟写操作
	txn.Set(Write{row: "row1", col: "col1", value: "value1"})
	txn.Set(Write{row: "row2", col: "col2", value: "value2"})

	// 提交事务
	if txn.Commit() {
		fmt.Println("事务成功提交")
	} else {
		fmt.Println("事务提交失败")
	}
}
