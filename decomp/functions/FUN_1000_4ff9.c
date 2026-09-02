/* 1000:4ff9 */

/* WARNING: Instruction at (ram,0x00015002) overlaps instruction at (ram,0x00015000)
    */

undefined4 FUN_1000_4ff9(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 in_CX;
  char cVar3;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  undefined2 *unaff_DI;
  char *pcVar4;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar5;
  bool bVar6;
  longdouble in_ST0;
  undefined4 uVar7;
  undefined2 in_stack_00000008;
  undefined2 in_stack_0000000c;
  undefined2 uVar8;
  
  pcVar4 = (char *)(unaff_DI + 1);
  uVar8 = in(in_DX);
  *unaff_DI = uVar8;
  bVar6 = (char)((uint)in_DX >> 8) == '\0' && *(char *)(unaff_BP + unaff_SI + 5) == '\0';
  uVar7 = FUN_1000_59b2(0x1012);
  if (bVar6) {
    while( true ) {
      *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) & (byte)in_CX;
      bVar6 = (byte)uVar7 == 6;
      if (5 < (byte)uVar7) {
        if (!bVar6) {
          return uVar7;
        }
        cVar5 = CARRY1((byte)in_CX,pcVar4[in_BX]);
        cVar3 = (char)((uint)in_CX >> 8);
        uVar8 = 0x5014;
        cVar2 = FUN_1000_567c();
        if ((bool)cVar5) goto LAB_1000_501b;
        uVar7 = FUN_1000_2fef(uVar8);
        pcVar1 = (char *)(unaff_BP + unaff_SI + 0x12aa);
        *pcVar1 = *pcVar1 + cVar3 + cVar5;
        bVar6 = *pcVar1 == '\0';
      }
      unaff_ES = (undefined2)((ulong)*(undefined4 *)(pcVar4 + in_BX) >> 0x10);
      in_CX = (undefined2)*(undefined4 *)(pcVar4 + in_BX);
      if (!bVar6) break;
      *(uint *)((int)unaff_DI + 0xf) = *(uint *)((int)unaff_DI + 0xf) | unaff_SI;
    }
  }
  else {
    cVar2 = (char)uVar7 + -0x18;
    *(int *)(in_BX + unaff_SI) = (int)ROUND(in_ST0);
    pcVar1 = pcVar4;
    pcVar4 = (char *)((int)unaff_DI + 3);
    *pcVar1 = cVar2;
LAB_1000_501b:
    *pcVar4 = cVar2;
    *(uint *)(unaff_SI - 0x1f) = *(uint *)(unaff_SI - 0x1f) | unaff_SI;
  }
  return CONCAT22(in_stack_00000008,in_stack_0000000c);
}


