/* 1000:68b7 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000168d1) overlaps instruction at (ram,0x000168d0)
    */

void FUN_1000_68b7(void)

{
  code *pcVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  undefined2 in_AX;
  uint uVar6;
  undefined2 in_DX;
  int in_BX;
  int iVar8;
  code *unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  unkbyte10 in_ST0;
  undefined4 uVar10;
  byte in_stack_00000000;
  int iVar7;
  
  pcVar1 = unaff_BP + unaff_DI + 0x4c7;
  *(uint *)pcVar1 = *(uint *)pcVar1 + 1;
  if ((POPCOUNT(*(uint *)pcVar1 & 0xff) & 1U) == 0) {
    uVar10 = (*unaff_BP)();
    in_DX = (undefined2)((ulong)uVar10 >> 0x10);
    uVar6 = (uint)uVar10;
  }
  else {
    uVar6 = CONCAT11((char)((uint)in_AX >> 8),
                     (((char)in_AX + -1) - (char)unaff_BP[(int)unaff_SI]) - ((char)in_AX != '\0'));
  }
  puVar9 = (undefined2 *)(unaff_DI + 0x30);
  *unaff_SI = *unaff_SI & (byte)uVar6;
  XACQUIRE();
  LOCK();
  pbVar3 = *(byte **)(unaff_BP + (int)unaff_SI + -0x7cfc);
  *(byte **)(unaff_BP + (int)unaff_SI + -0x7cfc) = unaff_SI;
  UNLOCK();
  puVar2 = (uint *)(in_BX + -0x77c6);
  uVar4 = *puVar2;
  *puVar2 = *puVar2 + uVar6;
  bVar5 = in_stack_00000000 + *pbVar3;
  if (!CARRY1(in_stack_00000000,*pbVar3) && !CARRY1(bVar5,CARRY2(uVar4,uVar6))) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar5 = (byte)uVar6 - (bVar5 + CARRY2(uVar4,uVar6));
  iVar7 = CONCAT11((char)(uVar6 >> 8),bVar5);
  *pbVar3 = *pbVar3 + bVar5 + (bVar5 < 9);
  *(int *)(in_BX + -0x7656) = *(int *)(in_BX + -0x7656) + iVar7;
  iVar8 = (in_BX + 0x48) * 2;
  unaff_BP[(int)puVar9] = (code)((byte)unaff_BP[(int)puVar9] ^ bVar5);
  *(unkbyte10 *)(pbVar3 + iVar8 + -1) = in_ST0;
  *(int *)(iVar8 + 0x648c) = iVar7;
  *(int *)(iVar8 + 0x648e) = iVar7;
  *(int *)(iVar8 + 0x64bc) = iVar7;
  *(int *)(iVar8 + 0x64be) = iVar7;
  pcVar1 = unaff_BP + 0x2757;
  *pcVar1 = (code)((byte)*pcVar1 | (byte)((uint)iVar8 >> 8));
  if ((char)*pcVar1 < '\x01') {
    *puVar9 = *(undefined2 *)0x270b;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_1000_69c7(puVar9,pbVar3,in_DX,0xd5ff);
  bVar5 = FUN_1000_78c3();
  unaff_BP[0x36] = (code)((byte)unaff_BP[0x36] ^ bVar5);
  *(char *)(iVar8 + 0x276a) = *(char *)(iVar8 + 0x276a) + (char)iVar8;
  return;
}


