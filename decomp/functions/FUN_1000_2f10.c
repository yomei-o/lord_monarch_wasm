/* 1000:2f10 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012f54) overlaps instruction at (ram,0x00012f52)
    */

undefined4 FUN_1000_2f10(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char cVar5;
  undefined2 in_AX;
  int iVar7;
  uint in_DX;
  byte extraout_DH;
  int extraout_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar8;
  bool in_SF;
  undefined4 uVar9;
  undefined2 in_stack_00000000;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  undefined2 uVar6;
  
  uVar6 = in_AX;
  if (!in_SF) {
    *(uint *)0x3631 = *(uint *)0x3631 ^ (uint)unaff_SI;
    *(uint *)0x1236 = *(uint *)0x1236 ^ (uint)unaff_SI;
    cVar5 = (char)in_AX + 'I';
    uVar6 = CONCAT11((char)((uint)in_AX >> 8),cVar5);
    if (SCARRY1((char)in_AX,'I')) {
      iVar7 = *(int *)(in_BX + unaff_DI) * 0x36;
      iVar7 = CONCAT11((byte)((uint)iVar7 >> 8) | *(byte *)(unaff_BP + 1),(char)iVar7);
      FUN_1000_33ff();
      in_DX = CONCAT11(extraout_DH,4);
      unaff_DI = unaff_DI + 1;
      in_CF = extraout_DH < *(byte *)0x432;
      uVar6 = in_stack_00000000;
      if (iVar7 != 1) goto LAB_1000_2f49;
      uVar6 = CONCAT11((char)((uint)in_stack_00000000 >> 8) - *unaff_SI,(char)in_stack_00000000);
      in_DX = CONCAT11(extraout_DH,*unaff_SI) | 4;
    }
    else if ((POPCOUNT(cVar5) & 1U) != 0) goto code_r0x00012f56;
    if ((byte)uVar6 < 4) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    in_CF = 0;
  }
LAB_1000_2f49:
  puVar1 = (uint *)(unaff_SI + in_BX);
  uVar3 = (uint)in_CF;
  uVar2 = *puVar1;
  pcVar4 = unaff_SI + *puVar1;
  bVar8 = CARRY2(*puVar1,(uint)unaff_SI) || CARRY2((uint)pcVar4,uVar3);
  *puVar1 = (uint)(pcVar4 + uVar3);
  if (((SCARRY2(uVar2,(int)unaff_SI) != SCARRY2((int)pcVar4,uVar3)) != (int)*puVar1 < 0) ||
     (bVar8 = (byte)uVar6 < (byte)unaff_SI[0xc], (byte)uVar6 == unaff_SI[0xc])) {
    uVar9 = func_0x0001a47d();
    if (bVar8) {
      return uVar9;
    }
    uVar9 = FUN_1000_3f40();
    return uVar9;
  }
  unaff_DI = *(int *)(unaff_DI + -0x1b86);
code_r0x00012f56:
  uVar9 = CONCAT22(in_DX,uVar6);
  if (unaff_DI != 0) {
    uVar2 = *(uint *)(unaff_DI + 6);
    uVar3 = uVar2 * 3;
    iVar7 = (in_DX << 1 | (uint)((int)uVar2 < 0)) + in_DX + (uint)CARRY2(uVar2 * 2,uVar2);
    uVar9 = CONCAT22(iVar7,uVar3);
    if ((iVar7 == 0) && (uVar9 = CONCAT22(iVar7,uVar3), uVar3 < *(uint *)(unaff_SI + 6))) {
      do {
        FUN_1000_63f1();
        func_0x000178b1();
        func_0x000163f3();
        iVar7 = extraout_DX;
        do {
          iVar7 = iVar7 * 2;
          in_DX = in_DX - 1;
          if (in_DX == 0) {
            FUN_1000_3ec3();
            return CONCAT22(in_stack_0000000a,in_stack_0000000e);
          }
        } while (-1 < (char)((byte)((uint)iVar7 >> 8) ^ (byte)iVar7));
        func_0x000178b1();
      } while( true );
    }
  }
  return uVar9;
}


