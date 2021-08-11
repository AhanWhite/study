# Go语言编程

## 1 初识Go语言

### 1.1 语言特性

这里罗列以下G哦语言最主要的特性

- 自动垃圾回收
- 更丰富的内置类型
- 函数多返回值
- 错误处理
- 匿名函数和闭包
- 类型和接口
- 并发编程
- 反射
- 语言交互性

## 1.2 第一个Go程序

```go
// hello.go 
package main
import "fmt"
func main() {
 fmt.Println("Hello, world. 你好，世界！")
}
```

每个Go源代码文件的开头都是一个package声明，表示该Go代码所属的包。包是Go语言里最基本的分发单位，也是工程管理中依赖关系的体现。要生成Go可执行程序，必须建立一个名字为main的包，并且该包中包含一个叫main()的函数(该函数是Go可执行程序的执行起点)。

Go语言的main()函数不能带参数，也不能定义返回值，命令行传入的参数在os.Args变量中保存。如果需要支持命令行开关，可使用flag包。

在包声明之后，是一系列的import语句，用于导入该程序所依赖的包。由于本示例程序使用到了Println()函数，所以需要导入该函数所属的fmt包。

有一点需要注意，不得包含在源代码文件中没有用到的包，否则编译器回报编译错误。这与下面提到的强制左花括号{的放置位置以及之后会提到的函数名的大小写规则，均体现了Go语言在语言层面解决软件工程问题的设计哲学。

所有Go函数(包括在对象编程中会提到的类型成员函数)以关键字func开头。一个常规的函数定义包含以下部分：

```go
func 函数名(参数列表) (返回值列表) {
    // 函数体
}
```

对于的实例如下：

```go
func Compute(value1 int, value float64) (result float64, err error) {
    // 函数体
}
```

Go支持多个函数返回值。以上的实力函数Compute()返回了两个值，一个叫result，一个是err。并不是所有返回值都必须赋值。在函数返回时没有被明确赋值的返回值都会被设置为默认值，比如result会被设为0.0， err会被设为nil。

Go程序的代码注释与C++保持一致，即同时支持以下两种用法：

```go
/**
 * 块注释
 */

// 行注释
```

Go程序不要求开发者在每个语句后面加上分号表示语句结束。

有些读者可能会自然地把左花括号{另起一行放置，这样做的后果是Go编译器报告编译错误，这点需要特别注意：

```go
syntax error: unexpected semicolon or newline before {
```

## 2 顺序编程

### 2.1 变量

从根本上来说，变量相当于是对一块数据存储空间的命名，程序可以通过定义一个变量来申请一块数据存储空间，之后可以通过引用变量名来使用这块存储空间。

#### 2.1.1 变量声明

对于纯粹的变量声明，go语言引入了关键字var，而类型信息放在变量名之后，示例如下：

```go
var v1 int
var v2 string
var v3 [10]int	// 数组
var v4 []int 	// 数组切片
var v5 struct {
    f int
}
var v6 *int		// 指针
var v7 map[string]int	// map，key为string类型，value为int类型
var v8 func(a int) int
```

变量声明语句不需要使用分号作为结束符。与C相比，Go摒弃了语句必须以分号作为语句结束标记的习惯。

var关键字的另一种用法是可以将若干个需要声明的变量放置在一起，避免程序员需要重复写var关键字

```go
var {
    v1 int
    v2 string
}
```

#### 2.1.2 变量初始化

对于声明变量时需要进行初始化的场景，var关键字可以保留，但不再是必要的元素，如下所示：

```go
var v1 int = 10	// 正确1
var v2 = 10		// 正确2 编译器自动推导类型
v3 := 10		// 正确3 编译器自动推导类型
```

以上三种用法效果完全一样(除了第三种不能用于声明全局变量)。与第一种用法相比，第三种用法需要输入的字符数大大减少。冒号和等号(:=)用于明确表达同事进行变量声明和初始化的工作。

指明类型已不再是必须的，Go编译器可以从初始化表达式的右值推导出该变量应该声明为哪种类型，这让Go看起来有点像动态类型语言，尽管Go语言实际上是不折不扣的强类型语言(静态类型语言)。

当然，出现在:=左侧的变量不应该是已经被声明过的，否则会导致编译错误，比如下面这个写法

```go
var i int
i := 2
```

会导致如下错误

> no new variables on left side of :=

#### 2.1.3 变量赋值

在Go语法中，变量初始化和变量赋值是两个不同的概念。下面为声明一个变量之后的赋值过程

```go
var v10 int
v10 = 22
```

Go的变量赋值与多数语言一致，但Go提供了多重赋值功能，比如下面这个交换i和j变量：

```go
i, j = j, i
```

在不支持多重变量赋值的语言中，需要引入一个中间变量

```go
t = i, i = j, j = t
```

多重赋值的特性在Go语言库的实现中也被使用的相当充分，在介绍函数的多重返回值时，将对其进行更深入的介绍

#### 2.1.4 匿名变量

我们在使用传统的强类型语言编程时，经常会出现这种情况，即在调用函数是为了获取一个值，却因为该函数返回多个值而不得不定义一堆没用的变量，在Go中这种情况可以通过结合使用多重返回和匿名变量来避免这种丑陋的写法

假设GetName()函数定义如下，它返回3个值，分别是firstName，lastName，nickName

```go
func GetName() (firstName, lastName, nickName string) {
    return "Ahan", "White", "Bai"
}
```

如果只想获得nickName，则可如下

```go
_, _, nickName = GetName()
```

### 2.2 常量

在Go语言中，常量是指编译期间就已知且不可改变的值。常量可以是数值类型(包含整型、浮点型和复数类型)、布尔类型、字符串类型等

#### 2.2.1 字面常量

所谓字面常量，是指程序中硬编码的常量

```go
12
3.14159265358979323846	// 浮点类型的常量
3.2+12i					// 复数类型的常量
true					// 布尔类型的常量
"foo"					// 字符串常量
```

在其他语言中，常量通常有特定的类型，比如-12在C语言中会被认为是一个int类型的常量。如果要指定一个值为-12的long类型常量，需要写成-12l，这有点违反人们的直观感受。Go语言的字面常量更接近我们自然语言中的常量概念，它是无类型的。只要这个常量在相应类型的值域范围内，就可以作为该类型的常量，比如上面的-12，它可以赋给int、uint、int32、int64、float32、float64、complex64、complex128等类型的变量。

#### 2.2.2 常量定义

通过const关键字，你可以给字面常量指定一个友好的名字：

```go
const PI float64 = 3.14159265358979323846
const zero = 0.0		// 无类型浮点常量
const (
	size int64 = 1024
    eof = -1			// 无类型整型常量
)
const u, v, float32 = 0, 3
const a, b, c = 3, 4, "foo" // u = 0.0, v= 3.0常量的多重赋值
```

Go的常量定义可以限定常量类型，但不是必须的。如果定义常量时没有指定类型，那么它和字面常量一样是无符号常量。

常量定义的右值也可以是一个在编译期运算的常量表达式，比如

```go
const mask = 1 << 3
```

由于常量的赋值是一个编译期行为，所以右值不能出现任何需要运行期才能得出结果的表达式，比如试图以如下方式定义常量就会导致编译错误

```go
const Home = os.GetEnv("HOME")
```

原因很简单，os.GetEnv()只有在运行期才能知道返回结果，在编译器并不能确定，所以无法作为常量定义的右值

#### 2.2.3 预定义常量

Go预定义了这些常量：true、false和iota。

iota比较特殊，可以被认为是一个可被编译器修改常量，在每一个const关键字出现时被重置为0，然后再下一个const出现之前，每出现一次iota，其所代表的数字户自动增1.

从以下的例子可以基本理解iota的用法：

```go
const (	// iota重置为0
	c0 = iota	// c0 == 0
    c1 = iota	// c1 == 1
    c2 = iota	// c2 == 2
)
const ( // iota重置为0
	a = 1 << iota	// a = 1 << 0 = 1
    b = 1 << iota	// b = 1 << 1 = 2
    c = 1 << iota	// c = 1 << 2 = 4
)
const ( // iota重置为0
	u			= iota * 42 // u = 0  	// iota = 0
    v	float64	= iota * 42 // v = 42.0	// iota = 1
    w			= iota * 42 // w = 84	// iota = 2
)
const x = iota	// x = 0 // const重置
const y = iota	// y = 0 // 又重置了
```

如果两个const的赋值语句的表达式是一样的，那么可以省略掉后一个赋值表达式：

```go
const (
	c0 = iota	// c0 = 0
    c1			// c1 = 1
    c2			// c2 = 2
)
const (
	a = 1 << iota	// a = 1
    b				// b = 2
    c				// c = 4
)
```

#### 2.2.4 枚举

枚举指一系列相关的常量，比如下面关于一个星期中每天的定义。通过上一节的例子，我们看到可以在const后跟一对圆括号的方式定义一组常量，这种定义法在Go语言中通常用于定义枚举值。Go语言并不支持众多其他语言明确支持的enum关键字

下面是一个常规的枚举表示法，其中定义了一系列整型常量

```go
const (
	Sunday = iota
    Monday
    Tuesday
    Wendnesday
    Thursday
    Friday
    Saturday
    numberOfDays //这个常量没有导出
)
```

同Go语言的其他符号一样，以**大写字母开头的常量在包外可见**。

以上例子中numberOfDays为包内私有，其他符号则可被其他包访问。

### 2.3 类型

Go语言内置以下这些基础类型

- 布尔类型  bool
- 整型 int8、byte、int16、int、uint、uintptr
- 浮点类型 float32、float64
- 复数类型 complex64、complex128
- 字符串 string
- 字符类型 rune
- 错误类型 error

此外，Go语言也支持以下这些复合类型

- 指针pointer
- 数组array
- 切片slice
- 字典map
- 通道channel
- 结构体struct
- 接口interface

#### 2.3.1 布尔类型

Go语言中的布尔类型与其他语言基本一致，关键字也为bool，可赋值为预定义的true和false。

```go
var v1 bool
v1 = true
v2 := (1==2) // v2也会被推导为bool类型
```

布尔类型不能接收其他类型的赋值，不支持自动或强制的类型转换，以下错误示例

```go
var b bool
b = 1 // 错误
b = bool(1) // 编译错误
```

以下的用法才是正确的

```go
var b bool
b = (1!=0) // 编译正确
fmt.Println("Result:", b) // 打印结果： Result: true
```

#### 2.3.2 整型

整型是所有编程语言里最基础的数据类型

1、类型表示

需要注意的是 int和int32在Go语言里被认为是两种不同的类型，编译器也不会帮你自动做类型转换，比如

```go
var value2 int32
value := 64	// value会被自动推导为int类型
value2 = value // 编译错误
```

编译错误类似于

> cannot use value (type int) as type int32 in assignment

用强制类型转换可以解决这个问题

```go
value2 = int32(value) // 编译通过
```

在做强制类型转换时要注意数据精度损失和值溢出

2、数值运算

Go支持下面的常规整数运算：+ - \* \\ 和%。%和c语言中一样是求余运算，比如

```go
5 % 3
```

3、比较运算

Go语言支持以下几种比较运算符： >、<、==、>=、<=和!=。

```go
i, j := 1, 2
if i == j {
    fmt.Println("i and j are equal.")
}
```

两个不同类型整型数不能直接比较，比如int8和int类型的数不能直接比较，但各种类型都可以直接和字面常量比较。

```go
var i int32
var j int64
i, j = 1, 2
if i == j { // 编译错误
    fmt.Println("i and j are equal.")
}
if i == 1 || j == 2 { // 编译通过
    fmt.Println("i == 1 or j == 2.")
}
```

4、位运算

Go语言支持 x << y(左移) x >> y(右移) x ^ y(异或) x & y(与) x | y(或)  ^x(取反) 

#### 2.3.3 浮点型

浮点型用于表示包含小数点的数，比如1.234就是一个浮点型数据。Go语言中的浮点类型采用IEEE-754标准的表达方式。

1、浮点数表示

Go语言定义了两个类型float32和float64，其中float32等价于C语言的float类型，float64等价于C语言的double类型。

在Go语言里，定义一个浮点数变量的代码如下：

```go
var fvalue1 float32
fvalue1 = 12
fvalue2 := 12.0 //如果不加小数点，会被推导为整型而不是浮点型
```

fvalue2将被自动设为float64，而不管给他的数值是否用32位长度表示的。因此对于以上的例子，下面的赋值将导致编译错误

```go
fvalue1 = fvalue2
```

而必须使用这样的强制类型转换

```go
fvalue1 = float32(fvalue2)
```

 2、浮点数比较

因为浮点数不是一种精确的表达方式，所以像整型那样直接用==来判断两个浮点数是否相等是不可行的，这可能会导致不稳定的后果

下面是一种推荐的替代方案

```go
import "math"

// p为用户自定义的比较精度，比如0.00001
func IsEqual(f1, f2, p float64) bool {
    return math.Abs(f1-f2) < p
}
```

#### 2.3.4 复数类型

复数实际上由两个实数(在计算机中用浮点数表示)构成，一个表示实部，一个表示虚部。如果了解了数学上的复数是怎么回事，那么Go语言的复数就非常容易理解了。

1、复数表示

```go
var value1 complex64 //由两个float32构成的复数类型
value1 = 3.2 + 12i
value2 := 3.2 + 12i // value2是complex128的类型
value3 := complex(3.2, 12) // value3结果同value2
```

2、实部与虚部

对于一个复数z = complex(x, y)，就可以通过Go语言内置函数real(z)获得该复数的实部，也就是x，通过imag(z)获取该复数的虚部，也就是y

#### 2.3.5 字符串

在Go语言中，字符串也是一种基本类型。相比之下，C/C++中并不存在原生的字符串类型，通常用字符数组来表示，并以字符指针来传递。

Go语言中字符串的声明和初始化非常简单，

```go
var str string // 声明一个字符串变量
str = "Hello World"
ch := str[0] // 取字符串的第一个字符
fmt.Printf("The length of \"%s\" is %d \n", str, len(str))
fmt.Printf("The firtst character of \"%\" is %c.\n", str, ch)
```

输出结果为

```go
The length of "Hello World" is 11
The first character of "Hello World" is H
```

字符串的内容可以用类似于数组下标的方式获取，但与数组不同，字符串的内容不能再初始化后被修改。举个例子

```go
str := "Hello World" // 字符串也支持声明时进行初始化的做法
str[0] = 'X'	// 编译错误
```

编译器会报如下的错误

```go
cannot assign to str[0]
```

在这个例子中我们使用了一个Go语言内置的函数len()来获取字符串的长度。这个函数非常有用，我们在实际开发过程中处理字符串、数组、切片时常会用到。

Printf()函数与C语言运行库中的一模一样。

Go编译器支持UTF-9的源代码文件格式。这意味着源代码中的字符串可以包含非ANSI的字符，比如"Hello world. 你好，世界！"可以出现在Go代码中。但需要注意的是，如果你的Go代码需要包含非ANSI字符，保存源文件时请注意编码格式必须选择UTF-8.特别是Windows下一般编辑器都默认存为本地编码，比如中国地区可能是GBK编码而不是UTF-8，如果没注意这点在编译和运行时就会出现一些意料之外的情况

字符串的编码转换是处理文本文档(比如TXT、XML、HTML)非常常见的需求，不过可惜的是Go语言仅支持UTF-8和Unicode编码。对于其他编码，Go语言标准库并没有内置的编码转换支持。不过所幸的是，我们可以很容易基于iconv库用Cgo包装一个。这里有个开源项目: https://github.com/xushiwei/go-iconv

1、字符串操作

```go
x, y := "hello", "world"
x + y // 字符串连接"hello wrold"
len(x) // 求长度 5
x[0] // 取字符 h
```

更多操作，参考标准库strings包

2、字符串遍历

Go支持两种方式遍历字符串。一种是以字节数组的方式遍历

```go
str := "hello, 世界"
n := len(str)
for i := 0; i < n; i++ {
    ch := str[i] // 依据下标取字符串中的字符，类型为byte
    fmt.Println(i, ch)
}
```

输出

>0 104
>1 101
>2 108
>3 108
>4 111
>5 44
>6 32
>7 228
>8 184
>9 150
>10 231
>11 149
>12 140

可以看出，字符串长度为13，尽管直接看上去只有9个字符。这是因为每个中文字符在UTF-8中占3个字节，而不是1个字节

另一种是以Unicode字符遍历：

```go
str := "hello, 世界"
for i, ch := range str {
    fmt.Println(i, ch)
}
```

输出

> 0 104
> 1 101
> 2 108
> 3 108
> 4 111
> 5 44
> 6 32
> 7 19990
> 10 30028

以Unicode字符方式遍历时 每个字符的类型是rune(早起的Go语言用int表示Unicode字符)，而不是byte

#### 2.3.6 字符类型

在Go语言中指出两个字符类型，一个是byte(实际上是unit8的别名)代表UTF-8字符串的单个字节的值；另一个是rune，代表单个Unicode字符。

关于rune的操作，可查阅Go标准库的unicode包。另外unicode/utf8包也提供了UTF8和Unicode之间的转换。

出于简化语言的考虑，Go语言的多数API都假设字符串为UTF-8编码。尽管Unicode字符在标准库中有支持，实际很少使用

#### 2.3.7 数组

数组是Go语言编程中最常用的数据结构之一。顾名思义，数组就是一系列同一类型数据的集合。数组中包含的每个数据被称为数组元素，一个数组包含的元素个数被称为数组的长度。

以下为一些常规的数组声明方法:

```go
[32]byte					// 长度为32的数组，每个元素为一个字节
[2*N] struct {x, y int32}	// 复杂类型数组
[1000]*float64				// 指针数组
[3][5]int					// 二位数组
[2][2][2]float64			// 等同于[2]([2]([2]float64))
```

从以上类型也可以看出，数组是多维的。在Go语言中，数组长度定义后就不可再更改，在声明时长度可以为一个常量或者一个常量表达式(常量表达式是指在编译期就可计算结果的表达式)。数组的长度是该数组类型的一个内置常量，可以用Go语言的内置函数len()来获取。下面是一个获取数组arr元素个数的写法

```go
arrLength := len(arr)
```

1、元素访问

可以使用数组下标来访问数组中的元素。与C语言相同，数组下标从0开始，len(array)-1则表示最后一个元素的下标。下面是示例遍历整型数组并诸葛打印元素内容

```go
for i := 0; i < len(array); i++ {
    fmt.Println("Element", i, "of array is", array[i])
}
```

Go语言还提供了一个关键字range，用于便捷的遍历容器中的元素。当然数组也是range的支持范围。上面的遍历过程可以简化为如下的写法

```go
for i, v := range array {
    fmt.Println("Element", i, "of array is", array[i])
}
```

range具有两个返回值，第一个返回值是元素的数组下标，第二个返回值是元素的值。

2、值类型

在Go语言中数组是一个值类型。所有值类型变量在赋值和作为参数传递时都将产生一次赋值动作。如果将数组作为函数的参数类型，则在函数调用时该参数会发生数据复制。因此，在函数体中无法修改传入的数组的内容，因为函数内操作的只是传入数组的一个副本。

```go
package main

import "fmt"

func modify(array [5]int) {
    array[0] = 10 // 试图修改数组的第一个元素
    fmt.Println("In modify(), array values:". array)
}

func main() {
    array := [5]int{1,2,3,4,5} // 定义并初始化一个数组
    modify(array) // 传递给一个函数并试图在这个函数内修改这个数组内容
    fmt.Println("In main(). array values:". array)
}
```

输出

>In modify(), array values: [10 2 3 4 5]
>In main(). array values: [1 2 3 4 5]

函数modify()内操作的数组跟main()传入的数组是两个不同的实例。

#### 2.3.8 数组切片

数组的特点：数组的长度在定义之后无法再次修改，数组是值类型，每次传递都将产生一份副本。显然这种数据结构无法完全满足开发者的真实需求。

Go提供了数组切片(slice)来满足数组的不足。

初看起来，slice就想一个指向数组的指针，实际上它拥有自己的数据结构，而不仅仅是个指针。数组切片的数据结构可以抽象为以下3个变量：

- 一个指向原生数组的指针
- 数组切片中的元素个数
- 数组切片已分配的存储空间

从底层实现的角度看，数组切片依然使用数组来管理元素，因此它们之间的关系很容易联想起STL中std::vector和数组的关系。基于数组，数组切片添加了一系列管理功能，可以随时动态扩充存放空间，并且可以随意传递而不会导致所管理的元素被重复复制。

1、创建数组切片

创建数组切片的方法主要有两种——基于数组和直接创建。

基于数组

数组切片可以基于一个已存在的数组创建。数组切片可以只使用数组的一部分元素或者整个数组来创建。下述代码演示基于一个数组的前5个元素创建一个数组切片

```go
package main

import "fmt"

func main() {
	// 定义一个数组
	var myArray [10]int = [10]int{1,2,3,4,5,6,7,8,9,0}
	// 基于数组创建一个数组切片
	var mySlice []int = myArray[:5]

	fmt.Println("Elements of myArray: ")
	for _, v := range myArray {
		fmt.Print(v, " ")
	}
	fmt.Println("\nElements of mySlice")
	for _, v := range mySlice {
		fmt.Print(v, " ")
	}
}
```

输出

>Elements of myArray: 
>1 2 3 4 5 6 7 8 9 0 
>Elements of mySlice
>1 2 3 4 5 

Go支持用myArray[first:last]这样的方式来基于数组生成一个数组切片，而且这个用法还很灵活，比如下面几种都是合法的

```go
// 基于所有元素切片
mySlice = myArray[:]
// 基于前5个元素
mySlice = myArray[:5]
// 基于从第5个开始的所有元素
mySlice = myArray[5:]
```

直接创建

并非一定要事先准备一个数组才能创建数组切片。Go语言提供的内置函数make()可以用于灵活的创建数组切片。下面的例子演示了直接创建数组切片的方法。

```go
// 创建一个初始元素个数为5的数组切片，元素初始值为0
mySlice1 := make([]int, 5)
// 创建一个初始元素个数为5的数组切片，元素初始值为0，并预留10个元素的存储空间
mySlice1 := make([]int, 5, 10)
// 直接创建并初始化包含5个元素的数组切片
mySlice1 := []int{1,2,3,4,5}
// 当然这种方法创建事实上还有一个匿名函数会被创建出来，只是不需要我们来操心
```

2、元素遍历

操作数组元素的所有方法都适用于数组切片，比如数组切片也可以按下标读写元素，用len()函数获取元素个数，并支持使用range关键字来快速遍历所有元素

传统遍历

```go
for i := 0; i <len(mySlice); i++ {
    fmt.Println("mySlice[",i,"] = ",mySlice[i])
}
```

使用range可以让遍历代码显得更整洁。range表达式由两个返回值，一个是索引，第二个是元素的值

```go
for i, v := range mySlice {
    fmt.Println("mySlice[",i,"] = ",v)
}
```

3、动态增减元素

与数组相比，数组切片多了一个存储能力的概念，即元素个数与分配的空间可以是两个不同的值。合理的设置存储能力的值，可以大幅降低数组切片内部重新分配内存和搬送内存块的概率，从而大大提高程序性能。

假如你明知道当前创建的数组切片最多可能需要存储的元素个数是50，那么如果你存储能力小于50，比如20，那么在元素超过20时，底层至少会发生一次这样的动作——重新分配一块"够大"的内存，并且需要把内容由原来的内存块复制到新分配的内存块，这会产生比较明显的开销。给"够大"这两个字加上引号的原因是系统并不知道多大是够大明所以只是一个简单的猜测。比如，将原有的内存空间扩大两倍，但两倍不一定够，所以之前提到的内存重新分配和内容赋值的过程很可能发生多次，从而明显降低系统的整体性能。但如果你知道最大是50而且一开始设置存储能力是50，那么之后就不会发生这样耗费cpu的动作，从而达到用空间换时间的效果。

数组切片支持Go语言内置的cap()函数和len()函数。cap()函数返回的是数组切片分配的空间大小，而len()函数返回的是数组切片中当前所存储的元素个数

```go
mySlice := make([]int, 5, 10)

fmt.Println("len(mySlice): ", len(mySlice))
fmt.Println("cap(mySlice): ", cap(mySlice))
```

输出

> len(slice2):  5
> cap(slice2):  10

新增元素可以使用append()函数。

```go
mySlice = append(mySlice, 1, 2, 3)
```

append的第二个参数其实是一个不定参数，可以按需求添加若干个元素。甚至直接将一个数组切片追加到另一个数组切片的末尾。

```go
mySlice2 := []int{8,9,10}
// 给mySlice添加另一个数组切片
mySlice = append(mySlice, mySlice2...)
```

需要注意的是，我们在第二个参数mySlice2后面加了3个点，即一个省略号，如果没有这个省略号的话，会产生编译错误，因为按append的语义，当从第二个参数起的所有参数都是待附加的元素。因为mySlice中的元素类型是int，所以直接传递mySlice2是行不通的。加上省略号相当于把mySlice2包含的所有元素打散后传入。

上述调用等同于：

```go
mySlice = append(myslice, 8,9,10)
```

数组切片会自动处理存储空间不足的问题。如果追加的内容长度超过当前已分配的存储空间，即cap调用返回的信息，数组切片会自动分配一块足够大的内存。

4、基于数组切片创建数组切片

类似于数组切片可以基于一个数组创建，数组切片也可以基于另一个数组切片创建。

```go
oldSlice := []int{1,2,3,4,5}
newSlice := oldSlice[:3]
```

有意思的是，选择的oldSlice范围甚至可以超过所包含的元素个数，只要不超过oldSlice的存储能力(即cap返回的值)，那么这个创建就是合法的。超过元素个数的部分都会填上0.

5、内容复制

数组切片支持Go的另一个内置函数copy()，用于将内容从一个数组切片复制到另一个数组切片。如果加入的两个数组切片不一样大，就会按其中较小的数组的元素个数进行复制

```go
slice1 := []int{1,2,3,4,5}
slice2 := []int{5,4,3}
copy(slice2, slice1) // 只会复制slice1的前3个元素到slice2中
copy(slice1, slice2) // 只会复制slice2的3个元素到slice1的前3个位置
```

#### 2.3.9 map

在C++/Java中，map一般以库的形式出现，比如C++是STL的std::map<>，在java中是Hashmap<>，在这些语言中使用map需要事先导包，Go语言不用。

map是一堆键值对的未排序集合。比如以身份证号作为唯一键来标识一个人的信息，则这个map可以定义为如下代码

```go
package main

import "fmt"

// PersonInfo PersonInfo是一个包含个人信息的类型
type PersonInfo struct {
	ID string
	Name string
	Address string
}

func main() {
	var personDb map[string] PersonInfo
	personDb = make(map[string]PersonInfo)
	// 往这个map里插入几条数据
	personDb["12345"] = PersonInfo{"12345", "Tom", "Room 12345"}
	personDb["1"] = PersonInfo{"1", "Jack", "Room 1"}

	// 查询
	person, ok := personDb["1234"]
	// ok是bool类型，true代表找到了对于的数据
	if ok {
		fmt.Println("找到了这个人：", person.Name)
	} else {
		fmt.Println("没找到这个人")
	}
}
```

1、变量声明

map的声明基本上没有多余的元素

```go
var myMap map[string] PersonInfo
```

myMap是声明的map变量名，string是键的类型，PersonInfo则是其所存放的值类型。

2、创建

我们可以是使用Go语言内置的函数make()来创建一个新map。下面这个例子创建了一个键类型为string、值类型为PersonInfo的map。

```go
myMap = make(map[string] PersonInfo)
// 也可以指定初始存储能力
myMap = make(map[string] PersonInfo， 100)
```

创建并初始化map的代码如下

```go
mymap = map[string] PersonInfo{
    PersonInfo{"12345", "Tom", "Room 12345"},
}
```

3、元素赋值

```go
personDb["12345"] = PersonInfo{"12345", "Tom", "Room 12345"}
```

4、元素删除

Go语言提供了一个内置函数delete()，用于删除容器内的元素。

```go
delete(myMap, "1234")
```

如果键不存在，调用什么也不会发生，也不会有什么副作用。但是如果传入的map变量的值是nil，会导致程序抛出异常panic

5、元素查找

Go语言在map中查找一个特定的键

```go
value, ok := myMap["1234"]
if ok {
    // 找到了，进行处理
}
```

判断是否成功找到特定的键，不需要检查取到的值是否为value，只需要看第二个返回值ok。

### 2.4 流程控制

流程控制语句一般起一下三个作用：

- 选择 根据条件跳转到不同的执行序列
- 循环 根据条件反复执行某个序列。当然每次循环执行的输入输出可能有变化
- 跳转 根据条件返回到某执行序列

Go语言支持以下几种流程控制语句

- 条件语句 对应的关键字为if、else和else if
- 选择语句 对应的关键字为switch、case和select
- 循环语句 对应的关键字为for和range
- 跳转语句 对应的关键字为goto

在具体的应用场景中，害添加了如下关键字：break、continue和fallthrough。

#### 2.4.1 条件语句

```go
if a < 5 {
    return 0
} else {
    return 1
}
```

关于条件语句，需要注意：

- 条件语句不需要使用括号将条件括起来()

- 无论语句体内有几条语句，花括号{}必须存在

- 左花括号{必须与if或else处于同一行

- 在if之后，条件语句之前，可以添加变量初始化语句，使用;间隔

- 在有返回值的函数中，不允许将"最终的"return语句包含在if...else...结构中，否则编译失败：

  > function ends without a return statement

  失败的原因在于，Go编译器无法找到终止该函数的return语句。编译失败的案例如下：

  ```go
  func example(x int) int {
      if x == 0 {
          return 5
      } else {
          return x
      }
  }
  ```

#### 2.4.2 选择语句

根据传入条件的不同，选择语句会执行不同的语句，下面的例子根据传入的整型变量i的不同而打印不同的内容：

```go
switch i {
    case 0:
    	fmt.Printf("0")
    case 1:
    	fmt.Printf("1")
    case 2:
    	fallthrough
    case 3, 4, 5, 6:
    	fmt.Printf("3,4,5,6")
    default:
    	fmt.Printf("Default")
}
```

输出

>i = 0, 输出0
>
>i = 1, 输出1
>
>i = 2, 输出3,4,5,6
>
>i = 3/4/5/6, 输出3,4,5,6
>
>i = 其他，输出Default

比较有意思的是，switch后面的表达式甚至不是必须的，比如

```go
switch {
    case 0 <= Num && Num <=3:
    	fmt.Printf("0-3")
    case 4 <= Num && Num <=6:
    	fmt.Printf("4-6")
    case 7 <= Num && Num <=9:
    	fmt.Printf("7-9")
}
```

使用switch需要注意：

- 左花括号{必须和switch同一行
- 条件表达式不限制为常量或者整数
- 单个case中，可以出现多个结果或选项
- 与C语言相反，Go不需要用break来明确退出一个case
- 只要在case中明确添加fallthrough关键字，才会继续执行紧跟的下一个case
- 可以不设定switch之后的条件表达式，在这种情况下，整个switch结构与多个if...else...的逻辑作用等同

#### 2.4.3 循环语句

Go只支持for关键字，而不支持while和do-while结构。关键字for的基本使用方法和C/C++非常接近

```go
sum := 0
for i := 0; i<10; i++ {
    sum += i
}
```

for后面的条件表达式不需要用圆括号()抱起来。Go的无限循环直接简化为:

```go
sum := 0
for {
    sum++
    if sum > 1000 {
        break
    }
}
```

在条件表达式中也支持多重赋值，如下所示

```go
a := []int{1,2,3,4,5,6}
for i,j := 0, len(a) - 1; i < j; i, j=i+1, j-1 {
    a[i], a[j] = a[j], a[i]
}
```

使用循环语句时，需要注意

- 左花括号，必须和for同一行

- Go的for循环与C语言一样，都允许在循环条件中定义和初始化变量，唯一的区别是，Go不支持以逗号为间隔的多个赋值语句，必须使用平行赋值的方式来初始化多个变量

- Go语言的for循环同样支持continue和break来控制循环，但是它提供了一个更高级的功能break，可以选择中断哪一个循环，如下

  ```go
  JLoop:
  // ...
  for j := 0; j < 5; j++ {
      for i := 0; i < 10; i++ {
          if i > 5 {
              break JLoop
          }
          fmt.Println(i)
      }
  }
  ```

  本例中，break语句终止的是JLoop标签处的外层循环。

#### 2.4.4 跳转语句

goto语句的语义非常简单，就是跳转到本函数内的某个标签

```go
func myfunc(){
    i := 0
    HERE:
    fmt.Println(i)
    i++
    if i < 10 {
        goto HERE
    }
}
```

### 2.5 函数

函数构成代码的逻辑结构。在Go语言中，函数的基本组成为：关键字func、函数名、参数列表、返回值、函数体和返回语句

#### 2.5.1 函数定义

加法函数

```go
package mymath
import "errors"

func Add(a int, b int) (ret int, err error) {
    if a < 0 || b < 0 { // 假设这个函数只支持两个非负数字的加法
        err = errors.New("Should be non-negative numbers!")
        return
    }
    return a + b, nil // 支持多重返回值
}
```

如果参数列表中若干个相邻类型的参数相同，比如上面的a和b，则可以在参数列表中省略前面变量的类型声明

```go
func Add(a, b int) (ret int, err error) {
    // ...
}
```

如果返回值列表也是多个类型相同，也可以用同样的方式合并

如果函数只有一个返回值，也可以这么写

```go
func Add(a, b int) int {
    // ...
}
```

#### 2.5.2 函数调用

函数调用非常简单，只要事先导入了函数所在的包没救可以直接按照下列方式调用函数

```go
import "mymath"

c := mymath.Add(1, 2)
```

小写字母开头的函数只在本包内可见，大写字母开头的函数才能被其他包使用。这个规则也适用于类型和变量的可见性。

#### 2.5.3 不定参数

1、不定参数类型

不定参数就是指函数传入的参数个数为不定数量。为了做到这点，首先需要将函数定义为接收不定参数类型

```go
func myfunc(args ...int) {
    for _, arg := range args {
        fmt.Println(arg)
    }
}
```

myfunc函数接收不定数量的参数，这些参数的类型全部是int，所以它可以用如下方式调用。

```go
myfunc(2,3,4)
myfunc(1,2,4,5)
```

形如...type格式的类型只能作为函数的参数类型存在，而且必须是最后一个参数。他是一个语法糖，即这种语法对语言的功能没有影响，但是更方便程序员使用。

从内部实现机理来说，类型...type本质上是一个数组切片，也就是[]type，这也是为什么上面的参数args可以用for循环来获取每个传入的参数。

2、不定参数的传递

假设有另一个变参函数myfunc3(args ...int)，下面例子演示如何向其传递变参。

```go
func myfunc(args ...int) {
    // 按原样传递
    myfunc3(args...)
    // 传递片段，实际上任意的int slice都可以传进去
    myfunc3(args[1:]...)
}
```

3、任意类型的不定参数

之前的例子中将不定参数类型约束为int，如果你希望传任意类型，可以指定类型为interface{}。下面是Go语言标准库中fmt.Printf()的函数原型

```go
func Printf(format string, args ...interface{}) {
    // ...
}
```

用interfaceP{}传递任何类型数据是Go语言的惯例用法。使用interfaceP{}仍是类型安全的，这和C/C++不太一样。下例演示了如何分派传入interfaceP{}类型的数据

```go
package main

import "fmt"

func MyPrintf(args ...interface{}) {
	for _, arg := range args {
		switch arg.(type) {
		case int:
			fmt.Println(arg, "is a int value.")
		case string:
			fmt.Println(arg, "is a string value.")
		case int64:
			fmt.Println(arg, "is a int64 value.")
		default:
			fmt.Println(arg, "is a unkown value.")
		}
	}
}

func main() {
	var v1 int = 1
	var v2 int64 = 234
	var v3 string = "hello"
	var v4 float64 = 1.234

	MyPrintf(v1, v2, v3, v4)
}
```

输出

> 1 is a int value.
> 234 is a int64 value.
> hello is a string value.
> 1.234 is a unkown value.

#### 2.5.4 多返回值

Go的函数或者成员的方法可以有多个返回值。

比如File.Read()函数，就可以同时返回读取的字节数和出错信息。如果成功则返回值n为读取的字节，err为nil，否则err为具体的出错信息。

```go
func (file *File) Read(b []type) (n int, err Error)
```

同时，从上面的方法原型可以看到，我们还可以给返回值命名，就行函数的输入参数一样。返回值被命名之后，他们的值在函数开始的时候就自动初始化为空。在函数中执行不带任何参数的return语句时，会返回对于的返回值变量的值。

如果调用方调用了一个具有多个返回值的方法，但是却不想关心其中的某个返回值，可以简单的用一个下划线"_"来跳过这个返回值，比如：

```go
n, _ := f.Read(buf)
```

#### 2.5.5 匿名函数与闭包

匿名函数是指不需要定义函数名的一种函数实现方式。

1、匿名函数

在Go里面，函数可以像普通变量一样被传递或使用，这与C语言的回调函数比较类似。不同的是，Go语言支持随时在代码里定义匿名函数。

匿名函数由一个不带函数名的函数声明和函数体组成，如下

```go
func(a, b int, z float64) bool {
    return a * b < int(z)
}
```

匿名数可以直接赋值给一个变量或者直接执行

```go
f := func(x, y int) int {
    return x + y
}
func(ch chan int){
    ch <- ACK
}(reply_chan) // 花括号直接跟参数列表表示函数调用
```

2、必报

Go的匿名函数是一个闭包。

基本概念

闭包可以包含自由(未绑定到特定对象)变量的代码块，这些变量不在这个代码块内或任何全局上下文定义，而是在定义代码块的环境中定义。要执行的代码块(由于自由变量包含在代码块中，所以这些自由变量以及他们引用的对象没有被释放)为自由变量提供绑定的计算环境(作用域)

闭包的价值

闭包的价值在于可以作为函数对象或者匿名函数，对于类型系统而言，这意味着不仅要表示数据还要表示代码。支持闭包的多数语言都将函数作为第一级对象，就是说这些函数可以存储到变量中作为函数传递给其他函数，最重要的是能够被函数动态创建和返回。

Go语言中的闭包

Go语言中的闭包同样会引用到函数外的变量。闭包的实现确保只要闭包还被使用，那么被闭包引用的变量会一直存在,如代码所示

```go
package main

import "fmt"

func main() {
	var j int = 5
	a := func() func() {
		var i int = 10
		return func() {
			fmt.Printf("i, j: %d, %d\n", i, j)
		}
	}() // 加()执行匿名函数，a被赋值为匿名函数返回的函数
	a()
	j *= 2
	a()
}
```

输出

>i, j: 10, 5
>i, j: 10, 10

变量a指向的闭包函数引用了局部变量i和j，i的值被隔离，在闭包外不能被修改，改变j的值以后，再次调用a，发现结果是修改过的值。

在变量a指向的闭包函数中，只有内部的匿名函数才能访问变量i，而无法通过其他途径访问到，因此保证了i的安全性。

### 2.6 错误处理

#### 2.6.1 error接口

Go引入了一个关于错误处理的标准模式，即error接口，该接口的定义如下

```GO
type error interface {
    Error() string
}
```

对于大多数函数，如果要返回错误，大致上都可以定义为如下模式，将error作为多种返回值中的最后一个，但这并非是强制要求：

```go
func Foo(param int) (n int, err error) {
    // ...
}
```

调用时的代码建议按如下方式处理错误情况

```go
n, err := Foo(0)
if err != nil {
    // 错误处理
} else {
    // 使用返回值n
}
```

示范如何使用自定义的error类型

首先，定义一个用于承载错误信息的类型。因为Go语言中接口的灵活性，根本不需要从error接口继承或者像Java一样需要使用implements来明确执行类型与接口之间的关系，具体代码如下

```go
type PathError struct {
    Op		string
    Path	string
    Err		error
}
```

但是如果这样的话，编译器怎么知道PathError可以当一个error来传递呢？关键在于下面的代码实现了Error()方法

```go
func (e *PathError) Error() string {
    return e.Op + " " + e.Path + ": " + e.Err.Error()
}
```

关于接口的更多细节，参加3.5节。之后就可以返回PathError变量了。比如下面当syscall.Stat()失败返回err时，将该err包装到一个PathError对象中返回：

```go
func Stat(name string) (fi FileInfo, err error) {
    var stat syscall.Stat_t
    err = syscall.Stat(name, &stat)
    if err != nil {
        return nil, &PathError{"stat", name, err}
    }
    return fileInfoFormStat(&stat, name), nil
}
```

如果在处理错误时获取详细信息，而不仅仅满足于打印一句错误信息，那就需要用到类型转换只是了：

```go
fi, err := os.Stat("a.txt")
if err != nil {
    if e, ok := err.(*os.PathError); ok && e.Err != nil {
        // 获取PathError类型变量e中的其他信息进行处理
    } 
}
```

#### 2.6.2 defer

关键字defer是Go语言引入的一个非常有意思的特性，相信C++程序员很多写多类似下面这样的代码

```c++
class file_closer {
    FILE _f;
    public:
    file_closer(FILE f) : _f(f) {}
    ~file_closer() {if (f) fclose(f);}
};
```

然后再需要的地方这么写

```c++
void f() {
    FILE f = open_file("file.txt");//打开一个文件句柄
    file_closer _closer(f);
    // 对f句柄进行操作
}
```

为什么需要file_closer这么个包装类呢？因为如果没有这个类，代码中所有退出函数的环节，比如每一个可能抛出异常的地方，每一个return的位置，都需要关掉之前打开的文件句柄。即使你头脑清晰，想明白了每一个分支和可能出错的条件，在该关闭的地方都关闭了，怎么保证你的后继者也能做到同样水平？大量莫名其妙的问题就出现了。

在C/C++中海油另一种解决方案。开发者可以将需要释放的资源变量都声明在函数的开头部分，并在函数的末尾部分统一释放资源。函数需要退出时，就必须用goto语句跳转到指定位置先完成资源清理工作，而不能调用return语句直接返回。

这种方案也是可行的，也仍然在被使用着，但存在非常大的维护性问题。而Go语言使用defer关键字简简单单解决了这个问题，比如

```go
func CopyFile(dst, src string) (w int64, err error) {
    srcFile, err := os.Open(src)
    if err != nil {
        return
    }
    defer srcFile.Close()
    
    dstFile, err := os.Create(dstName)
    if err != nil {
        return
    }
    defer dstFile.Clos()
    return io.Copy(dstFile, srcFile)
}
```

即使其中的Copy函数抛出异常，Go仍然会保证dstFile, srcFile会被正常关闭。

如果的一句话干不完清理工作，也可以使用在defer后加一个匿名函数的做法

```go
defer func() {
    // 复杂清理工作
}()
```

一个函数中可以存在多个defer语句，因此需要注意的是，defer语句的调用是遵照先进后出的原则，即最后一个defer语句将最先执行。

#### 2.6.3 panic()和recover()

 Go语言引入了两个内置函数panic和recover来报告和处理运行时错误和程序中的错误场景：

```go
func panic(interface{})
func recover() interface{}
```

当一个函数执行过程中调用panic函数时，正常的函数执行流程将立即终止，但函数中之前使用defer关键字延迟执行的语句将正常展开执行，之后该函数将返回到调用函数，并导致逐层向上执行panic流程，直至所述的goruntine中所有正在执行的函数被终止。错误信息将被报告，包括在调用panic()函数时传入的参数，这个过程称为错误处理流程。

从panic的参数类型interface{}我们可以得知，该函数接收任意类型的数据，比如整型、字符串、对象等。调用方法很简单，下面为几个例子

```go
panic(404)
panic("network broken")
panic(Error("file not exists"))
```

recover()函数用于终止错误处理流程，一般情况下，recover()应该在一个使用defer关键字的函数中执行有效截取错误处理流程。如果在没有发生异常的goruntine中明确调用恢复过程，使用recover关键字，会导致该goruntine所属的进程打印异常信息后直接退出

以下为一个常见场景。

我们对foo()函数的只需要么心里没底感觉可能会除法错误处理，或者自己再其中明确加入了特定条件除法错误处理的语句，那么可以用如下方式在调用代码中截取recover():

```go
defer func() {
    if r := recover(); r != nil {
        log.Printf("Runtime error caught: %v", r)
    }
} ()
foo()
```

无论foo中是否触发了错误处理流程，该匿名defer函数都将在函数退出时得到执行。加入foo()中触发了错误处理流程，recover函数执行将使得该错误处理过程终止。如果错误处理流程被触发时，程序传给panic函数的参数不为nil，则该函数还会打印详细的错误信息。

### 2.7 完整示例

本节想要实现一个完整的程序。准备开发一个排序算法的比较程序，从命令行指定输入的数据文件和输出的数据文件，并指定对于的排序算法，该程序的用法如下所示：

> USAEG: sorter -i \<in\> -o \<out\> -a \<qsort|bubblesort\>

一个具体的执行过程如下

> $ ./sorter -I in.dat -o out.dat -a qsort
>
> The sorting process costs 10us to complete.

当然，输入不合法应该给出对于的提示。

#### 2.7.1 程序结构



