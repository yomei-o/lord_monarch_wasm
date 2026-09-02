/* 1000:3fa7 */

/* WARNING: Instruction at (ram,0x00013fbb) overlaps instruction at (ram,0x00013fb9)
    */

undefined4 FUN_1000_3fa7(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char extraout_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  char cVar4;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  
  do {
    FUN_1000_3cba();
    FUN_1000_78e2();
    cVar4 = '\0';
    iVar3 = 0xf;
    FUN_1000_49e2();
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + extraout_DL + cVar4;
  } while (iVar3 != 1);
  func_0x000178e1();
  if ((*(int *)0x10 != 0) ||
     (bVar1 = 0x14 - *(byte *)0xf, uVar2 = (uint)bVar1, 0x14 < *(byte *)0xf || bVar1 == 0)) {
    uVar2 = 0;
  }
  *(int *)0xc4ee = uVar2 + 0xc90;
  FUN_1000_7f80();
  *(undefined2 *)0x328c = 0xffff;
  return CONCAT22(in_stack_0000000e,in_stack_00000012);
}


