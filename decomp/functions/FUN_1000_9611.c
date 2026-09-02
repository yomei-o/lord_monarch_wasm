/* 1000:9611 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_9611(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar6;
  int iVar7;
  char cVar8;
  int in_CX;
  byte extraout_DH;
  int in_BX;
  undefined2 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined2 *unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar13;
  longdouble in_ST0;
  undefined1 auStack_1a [24];
  undefined2 uStack_2;
  byte bVar5;
  
  uStack_2 = 0x9614;
  cVar8 = FUN_1000_3806();
  iVar7 = *(int *)(in_BX + unaff_DI + 0x7810);
  puVar12 = &stack0x0000 + iVar7;
  if (in_CX == 1 || (char)(cVar8 + (char)((uint)in_CX >> 8)) != '\0') {
    *(undefined2 *)(&stack0x0000 + iVar7) = 0x961f;
    FUN_1000_8cec();
    puVar1 = (uint *)(in_BX + unaff_DI + -0x38f8);
    bVar13 = CARRY2(unaff_SI,*puVar1);
    uVar6 = *(undefined2 *)0xa5be;
    LOCK();
    pbVar2 = (byte *)(in_BX + unaff_SI + *puVar1);
    bVar3 = *pbVar2;
    *pbVar2 = (byte)((uint)uVar6 >> 8);
    UNLOCK();
    pbVar2 = (byte *)(in_BX + -0x1739);
    bVar4 = *pbVar2;
    bVar5 = *pbVar2;
    *pbVar2 = bVar5 + extraout_DH + bVar13;
    *(undefined2 *)0x5017 =
         CONCAT11(bVar3,((char)uVar6 - *(char *)0xe83c) -
                        (CARRY1(bVar4,extraout_DH) || CARRY1(bVar5 + extraout_DH,bVar13)));
    *(byte *)(in_BX + -0x4698) = *(byte *)(in_BX + -0x4698) | bVar3;
    *(double *)(in_BX + 0x21) = (double)in_ST0;
    *(undefined2 *)(puVar12 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar9 = (undefined2 *)(&stack0x0000 + iVar7);
  *(undefined2 **)(&stack0x0000 + iVar7) = unaff_BP;
  cVar8 = '\f';
  do {
    unaff_BP = unaff_BP + -1;
    puVar9 = puVar9 + -1;
    *puVar9 = *unaff_BP;
    cVar8 = cVar8 + -1;
  } while ('\0' < cVar8);
  *(undefined1 **)(auStack_1a + iVar7) = &stack0x0000 + iVar7;
  puVar10 = &stack0x4a26 + iVar7;
  *(undefined2 *)(&stack0x4a26 + iVar7) = 0x95ef;
  FUN_1000_5e03();
  puVar11 = puVar10 + -2;
  *(undefined2 *)(puVar10 + -2) = 0x95f2;
  func_0x00016009();
  *(undefined2 *)(puVar11 + -2) = 0x95f5;
  cVar8 = func_0x00013310();
  *(char *)0x4020 = cVar8 + '\x01';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


