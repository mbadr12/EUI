#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(REG,BIT_NO)					((REG>>BIT_NO)&1)
#define GET_VALUE(REG,Offset,count)			((REG>>Offset)&((1<<count)-1))
#define INSERT_BIT(REG,BIT_NO,VALUE)		(REG =(REG&(~(1<<BIT_NO))|(VALUE<<BIT_NO)))
#define INSERT_VALUE(REG,Offset,count,VALUE)(REG =(REG&(~((1<<count)-1)<<Offset))|(VALUE<<Offset))

#endif