|   1   |     0    |  字节
|7654321076543 2 10|  比特
|-------------|-|--|  占位
|    INDEX    |T|R |  含义
|             |I|P |
|             | |L |

RPL   : 请求特权级。以什么样的权限去访问段。
TI    : Table Indicator,这个值为0表示查找GDT，1则查找LDT
INDEX : 在GDT数组或LDT数组的索引号

|   7    |     6       |     5     |   4    |   3    |   2    |   1    |   0    |  字节
|76543210|7 6 5 4 3210 |7 65 4 3210|76543210|76543210|76543210|76543210|76543210|  比特
|--------|-|-|-|-|---- |-|--|-|----|--------|--------|--------|--------|--------|  占位
|  BASE  |G|D|0|A|LIMIT|P|D |S|TYPE|<------- BASE 23-0 ------>|<-- LIMIT 15-0 ->|  含义
|  31-24 | |/| |V|19-16| |P |
           |B| |L|     | |L |

BASE    : 段基址，由上图中的两部分(BASE 31-24 和 BASE 23-0)组成
G       : LIMIT的单位，该位 0 表示单位是字节，1表示单位是 4KB
D/B     : 该位为 0 表示这是一个 16 位的段，1 表示这是一个 32 位段
AVL     : 该位是用户位，可以被用户自由使用
LIMIT   : 段的界限，单位由 G 位决定。数值上（经过单位换算后的值）等于段的长度（字节）- 1。
P       : 段存在位，该位为 0 表示该段不存在，为 1 表示存在。
DPL     : 段权限
S       : 该位为 1 表示这是一个数据段或者代码段。为 0 表示这是一个系统段（比如调用门，中断门等）
TYPE    : 根据 S 位的结果，再次对段类型进行细分。