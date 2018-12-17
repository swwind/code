class PaginationHelper {
  constructor(arr, page) {
    this.arr = arr
    this.page = page
  }
  itemCount() {
    return this.arr.length
  }
  pageCount() {
    return Math.floor((this.arr.length - 1) / this.page) + 1
  }
  pageItemCount(index) {
    let pc = this.pageCount()
    if (index < 0 || pc <= index)
      return -1
    return index === pc - 1
      ? (this.arr.length - 1) % this.page + 1
      : this.page
  }
  pageIndex(index) {
    let pc = this.itemCount()
    if (index < 0 || pc <= index)
      return -1
    return Math.floor(index / this.page)
  }
}

let ph = new PaginationHelper([3, 4, 5, 6, 4, 5], 4)
console.log(ph.itemCount())
console.log(ph.pageCount())
console.log(ph.pageItemCount(-1))
console.log(ph.pageItemCount(0))
console.log(ph.pageItemCount(1))
console.log(ph.pageItemCount(2))
console.log('---------------')
console.log(ph.pageIndex(-1))
console.log(ph.pageIndex(0))
console.log(ph.pageIndex(1))
console.log(ph.pageIndex(2))
console.log(ph.pageIndex(3))
console.log(ph.pageIndex(4))
console.log(ph.pageIndex(5))
console.log(ph.pageIndex(6))
