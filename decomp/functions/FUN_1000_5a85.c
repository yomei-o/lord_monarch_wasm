/* 1000:5a85 */

uint FUN_1000_5a85(void)

{
  char cVar1;
  byte bVar2;
  undefined1 in_CL;
  int iVar3;
  int *unaff_SI;
  undefined2 unaff_DS;
  longdouble in_ST0;
  uint in_stack_00000008;
  
  cVar1 = FUN_1000_5abc();
  iVar3 = CONCAT11(cVar1 << 3,in_CL);
  bVar2 = FUN_1000_5abc();
  *unaff_SI = (int)ROUND(in_ST0);
  if (iVar3 != 0) {
    FUN_1000_5ab9();
    return in_stack_00000008;
  }
  return (uint)(byte)((bVar2 >> 4) * '\n' + (bVar2 & 0xf));
}


