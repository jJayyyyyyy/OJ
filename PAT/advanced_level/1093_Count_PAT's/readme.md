排列组合

先算出一共有多少个T，得到cntT

然后对s进行遍历

遇到`P`，则cntP++，表示`A`前面有多少个`P`

遇到`T`，则cntT--，表示`A`后面还有多少个`T`

遇到`A`，则进行`cntPAT += cntP * cntT;`

即进行全组合，`C(1, cntP) * C(1, cntT)`

