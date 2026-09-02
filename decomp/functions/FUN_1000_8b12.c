/* 1000:8b12 */

undefined4 FUN_1000_8b12(void)

{
  int in_AX;
  byte in_CL;
  int in_BX;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  
  return CONCAT22(*unaff_DI,
                  CONCAT11(3,(*(byte *)(in_BX + in_AX + 0x2400) >> (in_CL & 3) * '\x02' & 3) *
                             '\x02'));
}


