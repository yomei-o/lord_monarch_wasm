/* 1000:8576 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018585) overlaps instruction at (ram,0x00018584)
    */

void FUN_1000_8576(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  char cVar4;
  uint uVar5;
  byte bVar6;
  undefined2 in_AX;
  byte bVar7;
  int in_CX;
  byte bVar8;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  
  *(uint *)(unaff_DI + in_BX + 0x31) = *(uint *)(unaff_DI + in_BX + 0x31) & in_DX;
  *unaff_SI = *unaff_SI + (char)in_CX;
  bVar6 = (byte)in_AX;
  bVar8 = (byte)in_DX;
  if (bVar8 == bVar6) {
    *unaff_DI = bVar6;
  }
  else {
    bVar7 = (byte)((uint)in_AX >> 8);
    bVar9 = bVar8 < bVar7;
    if (bVar8 == bVar7) {
      pcVar2 = unaff_SI + in_BX;
      cVar4 = *pcVar2;
      *pcVar2 = *pcVar2 + '\x01';
      if (!SCARRY1(cVar4,'\x01')) {
        *(int *)(unaff_SI + in_BX) = *(int *)(unaff_SI + in_BX) + 1;
        unaff_BP = *(int *)(unaff_SI + 2);
        unaff_SI[in_BX + 2] = unaff_SI[in_BX + 2] & bVar7;
        puVar3 = (uint *)(unaff_SI + in_BX);
        uVar5 = *puVar3;
        *puVar3 = *puVar3 + in_DX;
        pbVar1 = (byte *)(unaff_SI + unaff_BP);
        bVar9 = CARRY1(*pbVar1,bVar6) || CARRY1(*pbVar1 + bVar6,CARRY2(uVar5,in_DX));
        *pbVar1 = *pbVar1 + bVar6 + CARRY2(uVar5,in_DX);
      }
      unaff_SI[in_BX + 0xe] = unaff_SI[in_BX + 0xe] + (char)(in_DX >> 8) + bVar9;
      unaff_DI[in_BX] = unaff_DI[in_BX] + bVar6;
      if (in_CX != 1) {
        in(0xd1);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((char *)0xfffd < unaff_SI || unaff_SI + 2 == (char *)0x0) {
        pcVar2 = unaff_SI + 2 + unaff_BP;
        *pcVar2 = *pcVar2 + bVar6 + ((char *)0xfffd < unaff_SI);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


