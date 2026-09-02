/* 1000:2f08 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012f54) overlaps instruction at (ram,0x00012f52)
    */

undefined4 FUN_1000_2f08(void)

{
  uint *puVar1;
  uint uVar2;
  char *pcVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint in_AX;
  uint uVar7;
  int iVar9;
  uint in_DX;
  byte extraout_DH;
  int extraout_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  byte in_AF;
  undefined4 uVar11;
  undefined2 in_stack_00000000;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  undefined2 uVar8;
  
  uVar7 = (in_AX ^ 0xec37) & 0x5f37;
  bVar5 = (byte)uVar7;
  bVar4 = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = bVar5 + bVar4 * '\x06' & 0xf;
  *(uint *)0x3631 = *(uint *)0x3631 ^ (uint)unaff_SI;
  *(uint *)0x1236 = *(uint *)0x1236 ^ (uint)unaff_SI;
  cVar6 = bVar5 + 0x49;
  uVar8 = CONCAT11((char)(uVar7 >> 8) + bVar4,cVar6);
  if (SCARRY1(bVar5,'I')) {
    iVar9 = *(int *)(in_BX + unaff_DI) * 0x36;
    iVar9 = CONCAT11((byte)((uint)iVar9 >> 8) | *(byte *)(unaff_BP + 1),(char)iVar9);
    FUN_1000_33ff();
    in_DX = CONCAT11(extraout_DH,4);
    unaff_DI = unaff_DI + 1;
    bVar10 = extraout_DH < *(byte *)0x432;
    uVar8 = in_stack_00000000;
    if (iVar9 == 1) {
      uVar8 = CONCAT11((char)((uint)in_stack_00000000 >> 8) - *unaff_SI,(char)in_stack_00000000);
      in_DX = CONCAT11(extraout_DH,*unaff_SI) | 4;
      goto code_r0x00012f3a;
    }
  }
  else {
    if ((POPCOUNT(cVar6) & 1U) != 0) goto code_r0x00012f56;
code_r0x00012f3a:
    if ((byte)uVar8 < 4) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar10 = false;
  }
  puVar1 = (uint *)(unaff_SI + in_BX);
  uVar2 = (uint)bVar10;
  uVar7 = *puVar1;
  pcVar3 = unaff_SI + *puVar1;
  bVar10 = CARRY2(*puVar1,(uint)unaff_SI) || CARRY2((uint)pcVar3,uVar2);
  *puVar1 = (uint)(pcVar3 + uVar2);
  if (((SCARRY2(uVar7,(int)unaff_SI) != SCARRY2((int)pcVar3,uVar2)) != (int)*puVar1 < 0) ||
     (bVar10 = (byte)uVar8 < (byte)unaff_SI[0xc], (byte)uVar8 == unaff_SI[0xc])) {
    uVar11 = func_0x0001a47d();
    if (bVar10) {
      return uVar11;
    }
    uVar11 = FUN_1000_3f40();
    return uVar11;
  }
  unaff_DI = *(int *)(unaff_DI + -0x1b86);
code_r0x00012f56:
  uVar11 = CONCAT22(in_DX,uVar8);
  if (unaff_DI != 0) {
    uVar7 = *(uint *)(unaff_DI + 6);
    uVar2 = uVar7 * 3;
    iVar9 = (in_DX << 1 | (uint)((int)uVar7 < 0)) + in_DX + (uint)CARRY2(uVar7 * 2,uVar7);
    uVar11 = CONCAT22(iVar9,uVar2);
    if ((iVar9 == 0) && (uVar11 = CONCAT22(iVar9,uVar2), uVar2 < *(uint *)(unaff_SI + 6))) {
      do {
        FUN_1000_63f1();
        func_0x000178b1();
        func_0x000163f3();
        iVar9 = extraout_DX;
        do {
          iVar9 = iVar9 * 2;
          in_DX = in_DX - 1;
          if (in_DX == 0) {
            FUN_1000_3ec3();
            return CONCAT22(in_stack_0000000a,in_stack_0000000e);
          }
        } while (-1 < (char)((byte)((uint)iVar9 >> 8) ^ (byte)iVar9));
        func_0x000178b1();
      } while( true );
    }
  }
  return uVar11;
}


