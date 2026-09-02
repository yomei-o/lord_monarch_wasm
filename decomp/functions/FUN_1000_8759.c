/* 1000:8759 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018778) overlaps instruction at (ram,0x00018777)
    */

void FUN_1000_8759(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar5;
  int in_AX;
  byte bVar6;
  int in_CX;
  undefined2 in_DX;
  undefined2 *in_BX;
  uint unaff_BP;
  uint *unaff_SI;
  uint *unaff_DI;
  uint unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  uint uVar4;
  
  bVar7 = false;
  if ((((byte)((byte)*unaff_DI & (byte)((uint)in_DX >> 8)) == 0) &&
      (bVar7 = unaff_SI < unaff_DI, unaff_SI != unaff_DI)) &&
     (bVar7 = (byte)in_DX < *(byte *)((int)unaff_DI + 0xb),
     (byte)in_DX == *(byte *)((int)unaff_DI + 0xb))) {
    bVar6 = (byte)((uint)in_AX >> 8);
    if (bVar6 == (byte)unaff_DI[6]) {
      bVar7 = 0xd9 < (byte)in_AX;
      in_AX = CONCAT11(bVar6,(byte)in_AX + 0x26);
      *in_BX = 0xffff;
      unaff_BP = unaff_ES;
    }
    else {
      puVar2 = unaff_SI;
      uVar5 = (uint)(bVar6 < (byte)unaff_DI[6]);
      uVar3 = *puVar2;
      uVar4 = *puVar2;
      *puVar2 = (uint)(&stack0xffee + uVar4 + uVar5);
      piVar1 = (int *)((int)unaff_DI + unaff_BP + 0x65d);
      *piVar1 = *piVar1 + in_CX +
                (uint)(CARRY2(uVar3,(uint)&stack0xffee) ||
                      CARRY2((uint)(&stack0xffee + uVar4),uVar5));
      bVar7 = CARRY2((uint)in_BX,unaff_BP);
      if (bVar7) {
        *(undefined2 *)unaff_DI[2] = 0xffff;
      }
    }
  }
  *(int *)(unaff_BP + (int)unaff_SI) = *(int *)(unaff_BP + (int)unaff_SI) + in_AX + (uint)bVar7;
  *(uint *)0x4911 = *(uint *)0x4911 >> ((byte)in_CX & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


